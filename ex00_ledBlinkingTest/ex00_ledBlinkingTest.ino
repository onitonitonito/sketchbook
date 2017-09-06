// THIS IS THE FILE FOR RSPI3 + ARDUINO-LEONARDO
// 4 LED + 4 SWITCHES EXAMPLE
void setup() {
  Serial.begin(9600);
  Serial.println("*** SERIAL MONITOR IS READY! ***");

  // 13, 12, 11, 10 = INPUT
  for (int n = 13; n >= 10; n--)  {
    pinMode(n, INPUT);
    Serial.print(n)
    Serial.println(" = INPUT");
  }
  Serial.println("********************");

  // 9, 8, 7, 6 = OUTPUT
  for (int n = 9; n >= 6; n--)  {
    pinMode(n, OUTPUT);
    Serial.print(n)
    Serial.println(" = OUTPUT");
  }
  Serial.println("********************");
}

void loop() {
  for (int n = 13; n >= 10; n--) {
    if (digitalRead(n) == HIGH) {
      digitalWrite(n - 4, HIGH);
      delay(200);
    }
  }

  for (int n = 9; n >= 6; n--) {
    digitalWrite(n, LOW);
    delay(200);
  }
  Serial.println("BEEP");
  Serial.println("********************");
}
