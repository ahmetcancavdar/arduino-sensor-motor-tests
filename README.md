# arduino-sensor-motor-tests
A collection of basic Arduino test scripts for motor control, motion sensing, and GPS tracking.
# Arduino Sensör ve Motor Kontrol Modülleri 🚀

Bu depo, Arduino ile yapılan robotik ve otonom sistem projelerinde en sık kullanılan üç temel donanımın bağımsız test ve kullanım kodlarını içermektedir. Kodlar; hareket, denge/yönelim ve konum takibi işlemlerini anlamak için minimal ve anlaşılır şekilde yazılmıştır.

## 🛠️ Kullanılan Donanımlar ve Özellikleri

1. **L298N Motor Sürücü**
   * Seri Port ekranından gönderilen basit karakterlerle (`w`: ileri, `s`: geri, `x`: dur) DC motor kontrolü sağlar.
   * PWM kullanılarak hız kontrolü (0-255 arası) yapılabilir.

2. **MPU6050 IMU (İvmeölçer ve Jiroskop)**
   * I2C protokolü kullanılarak sensörle haberleşilir.
   * X, Y, Z eksenlerinde ivme (g) ve dönüş hızı (dps) verilerini anlık olarak Seri Port'a yazdırır.
   * Modül üzerindeki dahili sıcaklık sensörünün (Temp) verisini okur.

3. **NEO-6M GPS Modülü**
   * `TinyGPS++` ve `SoftwareSerial` kütüphaneleri kullanılarak uydudan gelen NMEA verileri anlamlı hale getirilir.
   * Cihaz uyduya bağlandığında anlık **Enlem (Latitude)** ve **Boylam (Longitude)** verilerini virgülle ayrılmış şekilde verir.

## 📂 Klasör Yapısı

Projeyi klonladığınızda 3 farklı Arduino `.ino` dosyası göreceksiniz. Her donanımı projenize dahil etmeden önce bu kodlarla tekil olarak test edebilirsiniz.

## 🚀 Nasıl Kullanılır?

1. Test etmek istediğiniz donanımın kodunu Arduino IDE ile açın.
2. Gerekli kablo bağlantılarını (pin numaraları kodların başında belirtilmiştir) yapın.
3. Kodu Arduino'ya yükleyin.
4. `Araçlar > Seri Port Ekranı`'nı (Baud Rate değerine dikkat ederek: Motor ve GPS için 9600, IMU için 115200) açın ve verileri inceleyin.
