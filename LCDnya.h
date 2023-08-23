/*
Header yang berisi kodingan untuk interfacing LCD 20x4 ke jalur I2C
Untuk keterangan selengkapnya, silahkan kunjungi link berikut
https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <String.h>

//Deklarasi objek LCD 20x4 dengan nama "sibocil" yang memiliki address 0x27 (lihat keterangan LCD di toko saat membeli, dia address nya berapa)
LiquidCrystal_I2C sibocil(0x27, 20, 4);

//Fungsi setup LCD
void LCDnyaS() {
  sibocil.begin(20, 4);
  sibocil.init();
  sibocil.backlight();
}

//Fungsi untuk menampilkan nilai dari sensor level air (ultrasonik), turbidity air, pH air, dan suhu air ke LCD 20x4
void LCDnyaL1() {
  sibocil.clear();
  sibocil.setCursor(0, 0);
  sibocil.print("Level = " + String(level) + " cm");

  sibocil.setCursor(0, 1);
  sibocil.print("Turb  = " + String(ntu) + " NTU");

  sibocil.setCursor(0, 2);
  sibocil.print("pH    = " + String(pHv));

  sibocil.setCursor(0, 3);
  sibocil.print("Suhu  = " + String(T) + " C");
}

//Fungsi untuk menampilkan nilai dari sensor tegangan, suhu dan kelembapan tempat penyimpanan alat (DHT), dan keterangan tanggal & waktu
void LCDnyaL2() {
  sibocil.clear();
  sibocil.setCursor(0, 0);
  sibocil.print("Teg.  = " + String(V) + " V");

  sibocil.setCursor(0, 1);
  sibocil.print("T Chm = " + String(DHTT) + " C");

  sibocil.setCursor(0, 2);
  sibocil.print("H Chm = " + String(DHTH) + "%");

  sibocil.setCursor(0, 3);
  sibocil.print(date + "  " + timee);
}

//Fungsi untuk menampilkan keterangan pada saat akan menghubungkan ke WiFi
void LCDW() {
  sibocil.clear();
  sibocil.setCursor(0, 1);
  sibocil.print("Menghubngkan ke WiFi");
  int a = 20 - strlen(ssid);
  sibocil.setCursor(a / 2, 2);
  sibocil.print(ssid);
  Serial.print("Menghubungkan");
}