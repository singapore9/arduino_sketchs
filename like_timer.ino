#include <Segment.h>
#include <Display.h>
#include <Digit.h>

#include <Arduino.h>


const byte digitPins[4] = {A1, A2, A3, A4};
const byte segmentsPins[7] = {5, 6, 7, 8, 9, 10, 11};
const byte dpPin = 12;
const byte MAX_NUMBER = 13;

int counter = 0;
int currentNumber = MAX_NUMBER;

char tim[MAX_NUMBER][5] = { 
  "00.00",
  "01.00",
  "02.00",
  "03.00",
  "04.00",
  "05.00",
  "06.00",
  "07.00",
  "08.00",
  "09.00",
  "10.00",
  "11.00",
  "12.00"
};

uint32_t period = 1000L; // 1 secs
char valueChars[5];

Display d(digitPins, segmentsPins, dpPin);


void setup() {
  for (int i = 0; i <= A5; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}


void printNumber(int number) {
  valueChars[0] = tim[currentNumber][0];
  valueChars[1] = tim[currentNumber][1];
  valueChars[2] = tim[currentNumber][2];
  valueChars[3] = tim[currentNumber][3];
  valueChars[4] = tim[currentNumber][4];
  Serial.print("valueChars: ");
  Serial.println(valueChars);
  delay(1);
  d.print(valueChars);
}

void loop() {
  counter++;
  if (currentNumber == 0) {
    currentNumber = MAX_NUMBER;
  }

  for (uint32_t curTime = millis(); (millis() - curTime) < (1*period); ) { 
    if (currentNumber <= 0) {
      currentNumber = 0;
      
    } else {
      printNumber(currentNumber);
    }
  }
  currentNumber--;
}
