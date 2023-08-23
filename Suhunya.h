/*
Header ini berisi kodingan untuk interfacing sensor suhu DS18B20 dan DHT11
Untuk penjelasan selengkapnya, silahkan kunjungi link berikut
https://randomnerdtutorials.com/guide-for-ds18b20-temperature-sensor-with-arduino/
https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

//Objek untuk OneWire, diberi nama "alaala", dengan parameter dia terhubung ke pin mana. Di sini dihubungkan ke pin 23
OneWire alaala(23);

//Objek untuk DallasTemperature, diberi nama "ajojing", dengan objek OneWire sebagai parameter nya
DallasTemperature ajojing(&alaala);

//Objek untuk DHT, diberi nama "dehate", dengan parameter dia terhubung ke pin mana dan jenis DHT nya.
//Di sini digunakan DHT11, yang terhubung ke pin 16
DHT dehate(16, DHT11);

//Variabel untuk nilai suhu (Dari DS18B20), suhu (dari DHT11), dan kelembapan (dari DHT11)
float T, DHTT, DHTH;

//Fungsi setup nya
void SuhunyaS() {
  ajojing.begin();
  dehate.begin();
}

//Fungsi loop nya
void SuhunyaL() {
  ajojing.requestTemperatures();
  T = ajojing.getTempCByIndex(0);

  DHTH = dehate.readHumidity();
  DHTT = dehate.readTemperature();
}