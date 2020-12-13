// Cameron Duncan and Seth Martin
// Senior Project
// LED Light Bulb RGB Control
// help for mapping potentiometer values to a color wheel
// received from https://github.com/BlitzCityDIY/rainbowSwirlProject/tree/master
// edited so only one LED would be on during operation


int DC_range  = 0;
double High_Period = 0;

void setup() {

  Serial.begin(9600);
  noInterrupts() ;

  
}

void loop() {
  // loop works with 1 LED always off, and switches the other 2 LEDs
  // uses switch statement to find what what 2 LEDs should be switched

    int pot = analogRead(A2);
    int color_section = map(pot, 0, 684, 1, 3);
    

    switch (color_section) {
      
      case 1: // This will start with pin 5 always high and pin 4 always low. 
              // As pot sweeps, pin 5 duty cycle drops and pin 4 duty cycle grows

        digitalWrite(3, LOW);
        
        DC_range = map(pot, 0, 341, 0, 100);

        High_Period = 15 * DC_range;
        

        
        digitalWrite(5, LOW);
        digitalWrite(4, HIGH);
        delay(High_Period);
        
        digitalWrite(4, LOW);        
        digitalWrite(5, HIGH);
        delay(1500-(High_Period));

        break;

      case 2:// This will start with pin 3 always high and pin 5 always low. 
              // As pot sweeps, pin 3 duty cycle drops and pin 5 duty cycle grows

        digitalWrite(4, LOW);
        
        DC_range = map(pot, 342, 682, 0, 100);
        High_Period = 15 * DC_range;

        
        digitalWrite(3, LOW);
        digitalWrite(5, HIGH);
        delay(High_Period);

        
        digitalWrite(5, LOW);
        digitalWrite(3, HIGH);
        delay(1500-(High_Period));
        break;

      case 3:// This will start with pin 4 always high and pin 3 always low. 
              // As pot sweeps, pin 4 duty cycle drops and pin 3 duty cycle grows

        digitalWrite(5, LOW);

        DC_range = map(pot, 683, 1023, 0, 100);

        High_Period = 15 * DC_range;

        
        digitalWrite(4, LOW);
        digitalWrite(3, HIGH);
        delay(High_Period);

        
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        delay(1500-(High_Period));
        break;
        
    }
    


    

}
