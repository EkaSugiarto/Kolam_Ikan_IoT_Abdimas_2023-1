/*
Projek Abdimas Telkom University
di desa Bojongsari untuk
Mini Edufarm PKBM Schole Fitrah
Periode 2023-1
https://www.youtube.com/watch?v=DXoR8bg5tmQ
*/

//SSID dan password WiFi yang digunakan
const char ssid[] = "";
const char pass[] = "";

#include <WiFi.h>
#include "Levelnya.h"
#include "NTPnya.h"
#include "Suhunya.h"
#include "Turbiditynya.h"
#include "Voltnya.h"
#include "pHnya.h"
#include "Relaynya.h"
#include "LCDnya.h"
#include "Thingspeaknya.h"

void setup() {
  Serial.begin(9600);

  //Untuk menghubungkan ke wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  //Fungsi setup tiap sensor/modul
  LCDnyaS();
  LevelnyaS();
  NTPnyaS();
  RelaynyaS();
  SuhunyaS();
  ThingspeaknyaS();
  TurbiditynyaS();
  VoltnyaS();
  pHnyaS();
}


void loop() {
  //Mendapatkan keterangan tanggal dan waktu
  NTPnyaL();

  //Menampilkan data level air, turbidity air, pH air, dan suhu air terbaru ke LCD setiap 3 detik
  if (waktu.getSeconds() % 3 == 0) {
    LevelnyaL();
    TurbiditynyaL();
    pHnyaL();
    SuhunyaL();
    LCDnyaL1();
    delay(1000);
  }

  NTPnyaL();
  //Menampilkan data tegangan, suhu & kelembapan tempat penyimpanan alat, dan tanggal & waktu terbaru ke LCD setiap 3 detik
  if (waktu.getSeconds() % 3 == 0) {
    VoltnyaL();
    SuhunyaL();
    LCDnyaL2();
    delay(1000);
  }

  NTPnyaL();
  //Mengirimkan data ke Thingspeak setiap detik 0 dan 30
  if (waktu.getSeconds() % 30 == 0) ThingspeaknyaL();
}