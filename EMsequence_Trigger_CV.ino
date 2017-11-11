//A simple random trigger generator that makes use of the Ehrenfeucht-Mycielski sequence
//https://en.wikipedia.org/wiki/Ehrenfeucht%E2%80%93Mycielski_sequence
//https://oeis.org/A038219

//potentiometer input pin, for controlling the delay
int potPin1 = 0;

//output pin for control voltage
int cvPinout1 = 3;

//delay value variable
int delayVal = 0;

//the first 105 numbers of the Ehrenfeucht-Mycielski sequence, where 255 = 1
int EMseq[105] = {0,255,0,0,255,255,0,255,0,255,255,255,0,0,0,255,0,0,0,0,255,255,255,255,
 0,255,255,0,0,255,0,255,0,0,255,0,0,255,255,255,0,255,0,0,0,255,255,0,0,
 0,0,0,255,0,255,255,0,255,255,255,255,255,0,0,255,255,0,0,255,255,255,255,255,255,
 0,255,0,255,0,255,255,0,0,0,255,255,255,0,0,255,0,0,0,255,0,255,0,255,0,
 0,0,0,0,0,255};

//result variable, to be passed to output
int result = 0;

void setup() {
  
  Serial.begin(9600); // serial initialization for output monitoring
  
  pinMode(cvPinout1, OUTPUT); //ensuring the designated PWM pin is set to output

}

void loop() {

//getting the delay value, delaying the loop
delayVal = analogRead(potPin1);
delay(delayVal);

//choosing a random value from the sequence
result = EMseq[random(0, 104)];

//writing the value to the PWM output pin. acts as a trigger when sent to such an input on a VCO or other such device
analogWrite(cvPinout1, result); 

//quick and dirty output monitor to confirm that the axo is sending signal, uncomment if you need it
//Serial.println(result); 

}

//tested with an Arduino Uno R3, sending the output signal to an Intellijel Shapeshifter's trigger input. Said module's inputs are tolerant up to +5V.
//be very careful when testing code such as this with expensive hardware. Check the relevant documentation to make sure that your device can handle the voltage that this spits out. 
