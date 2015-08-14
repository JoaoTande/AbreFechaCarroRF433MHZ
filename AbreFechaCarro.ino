#define rfTransmitPin 4  //RF Transmitter pin = digital pin 4
#define ledPin 13
#define TIMES 85
const int buttonPin = 2;
int buttonState = 0;  

int vetAbre[TIMES] = {1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 
                    0, 0, 1, 0, 1, 1, 0, 0, 1, 0,
                    0, 1, 0, 0, 1, 0, 0, 1, 0, 1,
                    1, 0, 0, 1, 0, 0, 1, 0, 1, 1,
                    0, 0, 1, 0, 1, 1, 0, 1, 1, 0,
                    1, 1, 0, 1, 1, 0, 0, 1, 0, 1,
                    1, 0, 0, 1, 0, 0, 1, 0, 1, 1,
                    0, 0, 1, 0, 1, 1, 0, 0, 1, 0,
                    1, 1, 0, 0, 1};

int vetFecha[TIMES] = {1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 
                    0, 0, 1, 0, 1, 1, 0, 0, 1, 0,
                    0, 1, 0, 0, 1, 0, 0, 1, 0, 1,
                    1, 0, 0, 1, 0, 0, 1, 0, 1, 1,
                    0, 0, 1, 0, 1, 1, 0, 1, 1, 0,
                    1, 1, 0, 1, 1, 0, 0, 1, 0, 1,
                    1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
                    0, 1, 1, 0, 1, 1, 0, 0, 1, 0,
                    1, 1, 0, 0, 1};

void setup() {
  // put your setup code here, to run once:
  pinMode(rfTransmitPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void bit1J(){
 digitalWrite(rfTransmitPin, HIGH);
 delayMicroseconds(514);
}

void bit0J(){
digitalWrite(rfTransmitPin, LOW);
delayMicroseconds(514);
}

void abreCarro(){
  for(int i = 0; i<TIMES; i++){
    if(vetAbre[i] == 1){
      bit1J();
    } else {
      bit0J();
    }
  }

  for(int i = 0; i<23; i++){
    bit0J();
  }
}

void fechaCarro(){
  for(int i = 0; i<TIMES; i++){
    if(vetFecha[i] == 1){
      bit1J();
    } else {
      bit0J();
    }
  }

  for(int i = 0; i<23; i++){
    bit0J();
  }
}

void loop() {
  //buttonState = digitalRead(buttonPin);
  //if (buttonState == LOW) {
      //for(int i = 0; i<23; i++){
        //bit0J();
      //}
  //} else {
    //abreCarro();
    fechaCarro();
 // }
    
}
