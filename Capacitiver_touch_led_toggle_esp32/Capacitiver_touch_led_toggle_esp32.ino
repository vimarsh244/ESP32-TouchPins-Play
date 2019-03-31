/*
 * Project: Using touch inputs on ESP32 and controlling brightness of an LED
 * Connections: A wire connected to D15 or T3 and to a fruit or any such thing.
 * LED connected to D4 or GPIO4
   Board: ESP32 Dev Module
   Touch Sensor Pin Layout
   T0 = GPIO4
   T1 = GPIO0
   T2 = GPIO2
   T3 = GPIO15
   T4 = GPIO13
   T5 = GPIO12
   T6 = GPIO14
   T7 = GPIO27
   T8 = GPIO33
   T9 = GPIO32 
*/


uint8_t led = 4;  //LED connected on pin


int buff(int pin)                                       //Function to handle the touch raw sensor data
{

  int out = (50 - touchRead(pin));                         //  Scale by n, value very sensitive currently
  // change to adjust sensitivity as required
  if (out > 0 )
  {
    return (out + 2);
  }
  else
  {
    return 0;                                        //Else, return 0
  }

}

void setup()
{
  ledcAttachPin(led, 1);                                                    //Configure variable led, pin 18 to channel 1
  ledcSetup(1, 12000, 8);                                                  // 12 kHz PWM and 8 bit resolution
  ledcWrite(1, 100);                                                       // Write a test value of 100 to channel 1
  Serial.begin(115200);                                                    //for debugging
  Serial.println("Testing ledc 12 channel 1");




}
void loop()
{
  Serial.print("Touch sensor value:");
  Serial.println(buff(T3));


  {
    ledcWrite(1, (buff(T3)));                 // Using T0 for touch data
  }

  delay(100);
}
