// THIS IS THE FILE FOR RSPI3 + ARDUINO-LEONARDO
// 4 NON-CONTACT LEVEL SENSORS

int port01 = 13, port02 = 12, port03 = 11, port04 = 10;
int buz01 = 9, buz02 = 8, buz03 = 7, buz04 = 6;

void setup()  {
  Serial.begin(9600);    // baud rate = 9600
  Serial.println("Hello Arduino!");

  for (int n = port01; n >= port04; n--)  {
    pinMode(n, INPUT);
    pinMode(n - 4, OUTPUT);
  }
}

void loop() {
  for (int n = port01; n >= port04; n-- )   {
    if ( digitalRead(n) == HIGH ) {
      digitalWrite(n - 4, HIGH);
      Serial.print(n);
      Serial.println(" =BUZZ ON");
    }
  }
  delay(500);

  for (int n = buz01; n >= buz04; n--)  {
    digitalWrite(n, LOW);
  }

  Serial.println("*** BUZZ ALL RESET (OFF) ***");

  for(int n = 1; n <= 20; n++)  {
    Serial.println(); 
  }
}

