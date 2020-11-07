
void setup() {

  Serial.begin(9600);
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  noInterrupts() ;


  Serial.println("dumbass");

  
}

void loop() {

    int pot = analogRead(A2);
    int DC_range = map(pot, 0, 1023, 0, 100); //scales the range of the pot to be 0-100.  effective for duty cycle
    double High_Period = 15 * DC_range; //high period is set to 20 * the desired duty cycle.
    // desired frequency of about 120 Hz.  so one period is equal to 
    // 
    //
    //

    digitalWrite(2, HIGH);
    delay(High_Period);
    
    digitalWrite(2, LOW);
    delay(1500-(High_Period));

    // difficult to troubleshoot, serial.print is a long process and 
    // causes the out pulse train to look like
    // 1010100010101000
    //

}
