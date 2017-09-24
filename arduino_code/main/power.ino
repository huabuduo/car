
#define ADC_BAT_PIN A6
#define ADC_BOOST_PIN A7
#define ADC_CHAR_PIN A3
#define CHAR_PIN 12

float Vbat = 0, Vboost = 0, Vcharge = 0;

boolean IsCharge = false;
void powerInit(void)
{
  pinMode(ADC_BAT_PIN, INPUT);
  pinMode(ADC_BOOST_PIN, INPUT);
  pinMode(ADC_CHAR_PIN, INPUT);
  pinMode(CHAR_PIN, INPUT);
}

void powerHandle(void)
{
  Vbat = analogRead(ADC_BAT_PIN) / 102.4;
  Vboost = analogRead(ADC_BOOST_PIN) / 102.4;
  Vcharge = analogRead(ADC_CHAR_PIN) / 204.8;
  IsCharge = digitalRead(CHAR_PIN);
}

float powerGetChargeCurrent()
{
  return Vcharge * 500.0;
}
float powerGetVBat()
{
  return Vbat;
}
float powerGetVBoost()
{
  return Vboost;
}
