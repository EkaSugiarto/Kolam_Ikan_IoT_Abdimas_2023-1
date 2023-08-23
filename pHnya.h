/*
Header berikut berisi kodingan untuk interfacing sensor pH dari DFRobot
Untuk keterangan selengkapnya untuk sensor ini, silahkan kunjungi link berikut
https://www.dfrobot.com/product-1782.html
https://wiki.dfrobot.com/Gravity__Analog_pH_Sensor_Meter_Kit_V2_SKU_SEN0161-V2
*/

//Pin yang digunakan
const int pinpH = 34;

float pHv;

//Fungsi setup nya
void pHnyaS() {
  pinMode(pinpH, INPUT);
}

//Fungsi loop nya
void pHnyaL() {
  /*
  Persamaan berikut didapat dari hasil regresi linier saat kalibrasi
  sensor ini menggunakan larutan buffer dengan pH 4 dan 7
  Silahkan cek file "Data kalibrasi dan pengetesan.xlsx"
  untuk keterangan selengkapnya
  */
  pHv = -0.0047 * analogRead(pinpH) + 15.315;
}