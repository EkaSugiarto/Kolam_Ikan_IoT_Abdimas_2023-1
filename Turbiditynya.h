/*
Header berikut berisi kodingan untuk interfacing sensor Turbidity dari DFRobot
Untuk keterangan selengkapnya untuk sensor ini, silahkan kunjungi link berikut
https://wiki.dfrobot.com/Turbidity_sensor_SKU__SEN0189
*/

//Pin yang digunakan
const int pinTurbidity = 32;

float ntu;

//Fungsi setup nya
void TurbiditynyaS() {
  pinMode(pinTurbidity, INPUT);
}

//Fungsi loop nya
void TurbiditynyaL() {
  ntu = analogRead(pinTurbidity);

  /*
  PERSAMAAN BERIKUT HANYALAH CONTOH!
  Silahkan lakukan kalibrasi nilai NTU menggunakan kalibrator
  yang valid agar nilai sesuai dengan keadaan sebenarnya
  */
  ntu = 3000 * (1 - ntu / 2375);

  if (ntu < 0) ntu = 0;
}