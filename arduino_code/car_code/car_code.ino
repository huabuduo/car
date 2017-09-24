#define IR_EN  10
#define DIS_EN 8
#define LED_EN 9

void setup() {

  pinMode(IR_EN,OUTPUT);
  pinMode(DIS_EN,OUTPUT);
  pinMode(LED_EN,OUTPUT);
  digitalWrite(IR_EN,LOW);
  digitalWrite(DIS_EN,LOW);
  digitalWrite(LED_EN,LOW);
}

void loop() {
  digitalWrite(13,LOW);
  delay(500);
  digitalWrite(13,HIGH);
  delay(500);
}
