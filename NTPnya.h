/*
Header ini berisi kodingan untuk mendapatkan keterangan tanggal dan waktu dengan NTP
Kunjungi link berikut untuk penjelasan selengkapnya:
https://randomnerdtutorials.com/esp32-date-time-ntp-client-server-arduino/
*/

#include <WiFiUdp.h>
#include <NTPClient.h>

//Setingan NTP yang digunakan untuk waktu GMT+7
const char* ntpServer = "pool.ntp.org";
const long gmtOffset = 25200;     //7*3600
const int daylightOffset = 3600;  //3600 detik

//Variabel untuk menyimpan jam, menit, detik dalam bentuk bilangan bulat (integer)
int hr, mi, sec;

//Variabel untuk menyimpan keterangan tanggal dan waktu dalam bentuk string
String date, timee;

//Objek untuk WiFiUDP, diberi nama "ntpUDP"
WiFiUDP ntpUDP;

//Objek untuk WiFiClient, diberi nama "client"
WiFiClient client;

//Objek untuk NTPClient, diberi nama "waktu"
NTPClient waktu(ntpUDP, ntpServer, gmtOffset, daylightOffset);

//Fungsi setup NTP
void NTPnyaS() {
  waktu.begin();
  waktu.update();
}

//Fungsi loop NTP
void NTPnyaL() {
  waktu.update();

  String date_time = waktu.getFormattedDate();
  int index_date = date_time.indexOf("T");
  date = date_time.substring(0, index_date);
  timee = waktu.getFormattedTime();
}