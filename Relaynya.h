/*
Header ini berisi kodingan untuk interfacing relay 4 channel
yang mengontrol nyala/mati modul cooler, heater, dan pompa
*/

//Fungsi setup nya
void RelaynyaS() {
  pinMode(25, OUTPUT);  //Cooler
  pinMode(26, OUTPUT);  //Heater
  pinMode(27, OUTPUT);  //Pompa ke cooler
  pinMode(13, OUTPUT);  //Pompa ke heater
}

//Fungsi loop nya
void RelaynyaSuhu() {
  if (T < 25) {
    digitalWrite(25, HIGH);
    digitalWrite(26, LOW);
    digitalWrite(27, HIGH);
    digitalWrite(13, LOW);
  }

  if (T >= 25 && T <= 28) {
    digitalWrite(25, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(13, HIGH);
  }

  if (T > 28) {
    digitalWrite(25, LOW);
    digitalWrite(26, HIGH);
    digitalWrite(27, LOW);
    digitalWrite(13, HIGH);
  }
}