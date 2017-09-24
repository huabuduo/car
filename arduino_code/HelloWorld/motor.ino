#define AN1  5
#define AN2  7
#define PWMA 6
#define BN1  2
#define BN2  4
#define PWMB 3


void motorInit()
{
  pinMode(AN1, OUTPUT);
  pinMode(AN2, OUTPUT);
  pinMode(BN1, OUTPUT);
  pinMode(BN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void motorCtrl(int leftVal, int rightVal)
{
 if (leftVal == 0)
  {
    digitalWrite(BN1, HIGH);
    digitalWrite(BN2, HIGH);
  }
  if (leftVal > 0)
  {
    digitalWrite(BN1, HIGH);
    digitalWrite(BN2, LOW);
    analogWrite(PWMB, leftVal);
  }
  if (leftVal < 0)
  {
    digitalWrite(BN1, LOW);
    digitalWrite(BN2, HIGH);
    analogWrite(PWMB, -leftVal);
  }

  if (rightVal == 0)
  {
    digitalWrite(AN1, HIGH);
    digitalWrite(AN2, HIGH);
  }
  if (rightVal > 0)
  {
    digitalWrite(AN2, HIGH);
    digitalWrite(AN1, LOW);
    analogWrite(PWMA, rightVal);
  }
  if (rightVal < 0)
  {
    digitalWrite(AN2, LOW);
    digitalWrite(AN1, HIGH);
    analogWrite(PWMA, -rightVal);
  }
}

