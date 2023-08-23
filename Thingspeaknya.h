/*
Header ini berisi kodingan untuk mengirimkan data ke Thingspeak
Untuk keterangan selengkapnya, silahkan kunjungi link berikut
https://randomnerdtutorials.com/esp32-thingspeak-publish-arduino/
*/

#include "ThingSpeak.h"

void ThingspeakS();
void ThingspeakL();

unsigned long myChannelNumber = 1;  //Nomor channel di akun Thingspeak
const char* myWriteAPIKey = "";     //API key dari channel tersebut

//Fungsi setup nya
void ThingspeaknyaS() {
  ThingSpeak.begin(client);
}

//Fungsi loop nya
void ThingspeaknyaL() {
  /*
  Parameter untuk fungsi setField berikut adalah field ke-, nama variabel yang datanya akan di upload ke field tersebut.
  Contoh, nilai suhu dari DS18B20 akan dikirim ke field ke-1 di Thingspeak, maka parameter nya ditulis sebagai berikut
  ThingSpeak.setField(1, T);
  */
  ThingSpeak.setField(1, T);
  ThingSpeak.setField(2, level);
  ThingSpeak.setField(3, ntu);
  ThingSpeak.setField(4, pHv);
  ThingSpeak.setField(5, V);
  ThingSpeak.setField(6, DHTT);
  ThingSpeak.setField(7, DHTH);

  //Fungsi untuk mengirimkan semua data yang sudah dimasukkan ke fungsi setField, ke channel Thingspeak
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
}