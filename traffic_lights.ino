#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 


const int RED_PIN = 2;
const int YELLOW_PIN = 4;
const int GREEN_PIN = 7;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
  lcd.print("Lights:");  
  lcd.setCursor(0, 1);
}

void printColor(int colorPin) {
  lcd.setCursor(0, 1);
  if (colorPin == YELLOW_PIN) {
     lcd.print("yellow");
  } else {
    if (colorPin == GREEN_PIN) {
       lcd.print("green ");
    } else {
      lcd.print("red    ");
    }
  }
}

void setColor(int colorPin, bool shouldBlink) {
  printColor(colorPin);
  digitalWrite(colorPin, HIGH);   
  delay(1000);  
  if (shouldBlink) {     
    for (int i = 0; i < 5; i++) {
      digitalWrite(colorPin, LOW);     
      delay(100);
      digitalWrite(colorPin, HIGH);
      delay(200);
    }   
  } else {
    delay(500);
  }
  digitalWrite(colorPin, LOW);   
}


// the loop function runs over and over again forever
void loop() {

  setColor(RED_PIN, true);
  setColor(YELLOW_PIN, false);
  setColor(GREEN_PIN, true);

  delay(1000);
}
