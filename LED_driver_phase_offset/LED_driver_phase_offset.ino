//Cameron Duncan and Seth Martin
// This code is used for Senior Design project. The arduino is used to control 
// each of the LED drivers using 1 pin for each driver.  
// The code simply iterates over an array of bit patterns that mask port d and 
// sets each pin to low or high, and then delays to obtain the desired frequency 
// and duty cycle.
void setup() {
  pinMode (2, OUTPUT); //pins for r,g,b,w
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  noInterrupts() ;

}

const byte pulseDelay = 500; // used to set the frequency of the signal

const byte pattern[] = {0b00000100, 0b00000100, 0b00010000, // this is an array of bit patterns that will set the pins on port d to high or low.  itterates through
                        0b00100000};                        // bit patterns
byte i = 0;

void loop() {
//
  while (1) {
    PORTD = pattern[i++]; //itterates bit pattern
    if (i >= sizeof(pattern)) i = 0; // resets to beginning of array
    delay(pulseDelay);
  }

}
