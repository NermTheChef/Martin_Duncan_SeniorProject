//Cameron Duncan and Seth Martin
// Senior Project
// LED Light Bulb White Light
// White LED control with dimmable feature
// controlled with potentiometer
void setup() {

  Serial.begin(9600);
  noInterrupts() ;

  
}

void loop() {

    int pot = analogRead(A2);
    int DC_range = map(pot, 0, 1023, 0, 100); //scales the range of the pot to be 0-100.  effective for duty cycle
    double High_Period = 15 * DC_range; //high period is set to 15 * the desired duty cycle.
    // desired frequency of about 120 Hz.

    digitalWrite(4, HIGH);
    delay(High_Period);
    
    digitalWrite(4, LOW);
    delay(1500-(High_Period));

}
