#include <Arduino.h>
#include <Wire.h>

static constexpr uint8_t MPU_ADDR = 0x68; // AD0=0 -> 0x68, AD0=1 -> 0x69

// Registers
static constexpr uint8_t REG_PWR_MGMT_1   = 0x6B;
static constexpr uint8_t REG_SMPLRT_DIV   = 0x19;
static constexpr uint8_t REG_CONFIG       = 0x1A;
static constexpr uint8_t REG_GYRO_CONFIG  = 0x1B;
static constexpr uint8_t REG_ACCEL_CONFIG = 0x1C;
static constexpr uint8_t REG_ACCEL_XOUT_H = 0x3B;
static constexpr uint8_t REG_WHO_AM_I     = 0x75;

// Scale factors (accel ±2g, gyro ±250 dps)
static constexpr float ACC_LSB_PER_G    = 16384.0f;
static constexpr float GYRO_LSB_PER_DPS = 131.0f;

// Print period in milliseconds
static constexpr uint32_t PRINT_PERIOD_MS = 500;

static void i2cWrite(uint8_t reg, uint8_t val) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

static uint8_t i2cRead8(uint8_t reg) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom((uint8_t)MPU_ADDR, (uint8_t)1);
  return Wire.read();
}

static void i2cReadBytes(uint8_t reg, uint8_t* buf, uint8_t len) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom((uint8_t)MPU_ADDR, len);
  for (uint8_t i = 0; i < len; i++) buf[i] = Wire.read();
}

static int16_t toInt16(uint8_t hi, uint8_t lo) {
  return (int16_t)((hi << 8) | lo);
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000);

  uint8_t who = i2cRead8(REG_WHO_AM_I);
  Serial.print("WHO_AM_I = 0x");
  Serial.println(who, HEX);

  // Wake up the sensor
  i2cWrite(REG_PWR_MGMT_1, 0x01);
  delay(50);

  // Basic configuration
  i2cWrite(REG_SMPLRT_DIV, 9);
  i2cWrite(REG_CONFIG, 0x03);
  i2cWrite(REG_GYRO_CONFIG, 0x00);   // ±250 dps
  i2cWrite(REG_ACCEL_CONFIG, 0x00);  // ±2g

  Serial.println("IMU reading started (500ms interval).");
}

void loop() {
  static uint32_t lastPrint = 0;
  uint32_t now = millis();
  if (now - lastPrint < PRINT_PERIOD_MS) return;
  lastPrint = now;

  uint8_t raw[14];
  i2cReadBytes(REG_ACCEL_XOUT_H, raw, 14);

  int16_t axRaw = toInt16(raw[0], raw[1]);
  int16_t ayRaw = toInt16(raw[2], raw[3]);
  int16_t azRaw = toInt16(raw[4], raw[5]);
  int16_t tRaw  = toInt16(raw[6], raw[7]);
  int16_t gxRaw = toInt16(raw[8], raw[9]);
  int16_t gyRaw = toInt16(raw[10], raw[11]);
  int16_t gzRaw = toInt16(raw[12], raw[13]);

  float ax_g = axRaw / ACC_LSB_PER_G;
  float ay_g = ayRaw / ACC_LSB_PER_G;
  float az_g = azRaw / ACC_LSB_PER_G;

  float gx_dps = gxRaw / GYRO_LSB_PER_DPS;
  float gy_dps = gyRaw / GYRO_LSB_PER_DPS;
  float gz_dps = gzRaw / GYRO_LSB_PER_DPS;

  float tempC = (tRaw / 340.0f) + 36.53f;

  Serial.print("ACC[g]  X: "); Serial.print(ax_g, 3);
  Serial.print("  Y: ");       Serial.print(ay_g, 3);
  Serial.print("  Z: ");       Serial.print(az_g, 3);

  Serial.print(" | GYRO[dps] X: "); Serial.print(gx_dps, 2);
  Serial.print("  Y: ");            Serial.print(gy_dps, 2);
  Serial.print("  Z: ");            Serial.print(gz_dps, 2);

  Serial.print(" | TEMP[C]: ");     Serial.println(tempC, 2);
}
