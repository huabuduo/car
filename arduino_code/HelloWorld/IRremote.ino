#include <IRremote.h>

int RECV_PIN = 13;

IRrecv irrecv(RECV_PIN);

decode_results results;

void irInit(void)
{
  irrecv.enableIRIn(); // Start the receiver
}

void irHandle(void)
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
  }
}
