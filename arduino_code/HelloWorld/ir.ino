
#define DIS_EN 8
#define IR_EN  10

void irtInit(void)
{
  pinMode(DIS_EN, OUTPUT);
  pinMode(IR_EN, OUTPUT);
  digitalWrite(DIS_EN, LOW);
  digitalWrite(IR_EN, LOW);
}

void irtHandle(void)
{

}
