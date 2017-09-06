/*
YF‐ S201 Water Flow Sensor
Water Flow Sensor output processed to read in litres/hour
*/
volatile int flow_frequency;      // Measures flow sensor pulses
unsigned int l_hour;              // Calculated litres/hour
unsigned char flowsensor = 2;     // Sensor Input (default = D-2)
unsigned long currentTime;
unsigned long cloopTime;

// Interrupt function
void flow()  {
 flow_frequency++;
}

void setup()  {
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH);    // D-2 = SET High

   Serial.begin(9600);
   attachInterrupt(0, flow, RISING);  // Setup Interrupt

   sei();                             // Enable interrupts for ATmega8 function
   currentTime = millis();
   cloopTime = currentTime;
}


void loop ()  {
   currentTime = millis();
   // Every second, calculate and print litres/hour
   if(currentTime = (cloopTime + 1000))
   {
      cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/hour");
   }
}
