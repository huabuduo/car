
void setup(void) {
  Serial.begin(9600);
  irtInit();
  motorInit();
  powerInit();
  oledInit();
  irInit();
  lightInit();
}

void loop(void) {
  // motorCtrl(100, 100);
  //analogWrite(3, 200);
  //digitalWrite(3,HIGH);
  powerHandle();
  irHandle();
  oledHandle();
  lightHandle();
  irtHandle();
}
