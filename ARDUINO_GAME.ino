#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int playerX = 0, playerY = 0;
int targetX = 5, targetY = 1;
int targetValue = 1;
int score = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(A2));
  spawnTarget();
  lcd.setCursor(0,0);
  lcd.print(" COLLISION GAME");
  lcd.setCursor(0, 1);
  lcd.print("Collect Sum: 9");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);

}

void spawnTarget() {
  targetX = random(0, 16);
  targetY = random(0, 2);
  targetValue = random(1, 5);
}

void loop() {
  // 1. Read Joystick
  int xVal = analogRead(A0);
  int yVal = analogRead(A1);

  // 2. Movement Logic (with threshold to prevent drift)
  if (xVal < 200 && playerX > 0) playerX--;
  else if (xVal > 800 && playerX < 15) playerX++;
  
  if (yVal < 200 && playerY > 0) playerY--;
  else if (yVal > 800 && playerY < 1) playerY++;

  // 3. Collision Detection
  if (playerX == targetX && playerY == targetY) {
    score += targetValue;
    if (score >= 9) {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("YOU WIN!");
      delay(2000);
      score = 0;
      lcd.clear();
    }
    spawnTarget();
  }

  // 4. Update Screen (Redraw state)
  lcd.clear();
  
  // Draw target
  lcd.setCursor(targetX, targetY);
  lcd.print(targetValue);
  
  // Draw player
  lcd.setCursor(playerX, playerY);
  lcd.print(score);

  // 5. Control Throttling
  delay(150); // Prevents input from being too fast/erratic
}