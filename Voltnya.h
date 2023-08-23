/*
Header berikut berisi kodingan untuk interfacing sensor tegangan yang menggunakan
rangkaian pembagi tegangan dengan resistor untuk mengukur tegangan yang diberikan
Untuk keterangan selengkapnya untuk sensor ini, silahkan kunjungi link berikut
https://how2electronics.com/interfacing-0-25v-dc-voltage-sensor-with-arduino/
*/

//Pin yang digunakan
const int pinVolt = 35;

float V;

//Fungsi setup nya
void VoltnyaS() {
  pinMode(pinVolt, INPUT);
}

//Fungsi loop nya
void VoltnyaL() {
  /*
  Persamaan berikut didapat dari hasil regresi linier saat kalibrasi
  sensor ini menggunakan power supply variabel dan multimeter
  Silahkan cek file "Data kalibrasi dan pengetesan.xlsx"
  untuk keterangan selengkapnya
  */
  V = 0.0041 * analogRead(pinVolt) + 0.479;
  if (V < 0.5) {
    V = 0;
  }
}