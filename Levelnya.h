/*
Header yang berisi kodingan untuk interfacing sensor ultrasonik HCSR04
Silahkan kunjungi link berikut untuk keterangan selengkapnya
https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
*/

//Pin yang digunakan untuk sensor ultrasonik
const int pinTr = 19;
const int pinEc = 18;

float level;

//Fungsi setup nya
void LevelnyaS() {
  pinMode(pinTr, OUTPUT);
  pinMode(pinEc, INPUT);
}

//Fungsi loop nya
void LevelnyaL() {
  digitalWrite(pinTr, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTr, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTr, LOW);

  long t = pulseIn(pinEc, HIGH);
  level = t * 0.034 / 2;

  /*
  Nilai yang didapatkan adalah nilai jarak dari ujung speaker emitter dan receiver suara ultrasoniknya.
  Silahkan lakukan kalibrasi atau pendefinisian lain untuk menyesuaikan titik 0 cm nya ada dimana.
  Silahkan cek file "Data kalibrasi dan pengetesan.xlsx" untuk keterangan selengkapnya
  */
}