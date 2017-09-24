#define LEN_EN_PIN 9

typedef enum
{
  breath = 0,
  blink,
  lightOn,
  lightOff,
} LightState; 

LightState mState = lightOff;

int LightPwm = 0;
// LightPwm 的步进量
int SetpVal  = 5;
boolean BlinkState = true;

void lightInit(void)
{
  pinMode(LEN_EN_PIN, OUTPUT);
  digitalWrite(LEN_EN_PIN, LOW);
}

void lightHandle()
{
  switch (mState)
  {
    case breath:
      //static long int delayTime = 0;
      //if (millis() - delayTime >= 2)
      {
        // delayTime = millis();
        LightPwm += SetpVal;
        if (LightPwm >= 250 || LightPwm <= 0) SetpVal = -SetpVal;
        Serial.println(LightPwm);
        analogWrite(LEN_EN_PIN, LightPwm);
      }
      break;
    case blink:
      static long int delayTime = 0;
      if (millis() - delayTime > 1000)
      {
        delayTime = millis();
        BlinkState = !BlinkState;
        digitalWrite(LEN_EN_PIN, BlinkState);
      }
      break;
    case lightOn:
      analogWrite(LEN_EN_PIN, LightPwm);
      break;
    case lightOff:
      digitalWrite(LEN_EN_PIN, LOW);
      break;
  }
}

//void lightSetState(LightState state)
//{
//  mState = state;
//}
