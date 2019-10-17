
int ledPin = 13;      // select the pin for the LED
char input[8];
String input_serial;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
}

void loop() {
  if (Serial.available()) {   // if anything on port
    String myText = Serial.readString();   // read one character
    unsigned long StartTime = millis();
    if ((myText.length()) > 0) {
      digitalWrite(ledPin, HIGH);
      delay(1);
      digitalWrite(ledPin, LOW);
      delay(1);
      for (int i = 0; i < myText.length(); i++) {
        char myChar = myText.charAt(i);
        for (int i = 7; i >= 0; i--) {
          byte bytes = bitRead(myChar, i);
          if (bytes == 1) {
            digitalWrite(ledPin, HIGH);
            Serial.print("1");
          } else {
            digitalWrite(ledPin, LOW);
            Serial.print("0");
          }
          delay(1);
        }
      }
      unsigned long CurrentTime = millis();
      unsigned long ElapsedTime = CurrentTime - StartTime;
      Serial.println();
      Serial.println(ElapsedTime);
    }
  }
}
