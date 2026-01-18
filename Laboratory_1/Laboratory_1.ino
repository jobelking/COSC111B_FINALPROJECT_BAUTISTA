int  ledpins[5] = {12,11,10,9,8};

void setup() {
  for (int i=0; i<5; i++) {
    pinMode(ledpins[i], OUTPUT);
  }
}

void loop() {
  for (int x=0; x<5; x++){
    digitalWrite(ledpins[x], HIGH);
    delay(1000);
  }
  
  for (int y=0; y<5; y++){
    digitalWrite(ledpins[y], LOW);
    delay(1000);
  }
}