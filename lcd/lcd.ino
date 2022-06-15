#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();

  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Joe is Amazing");        // print message at (0, 0)
  lcd.setCursor(0, 1);         // move cursor to   (2, 1)
  lcd.print("Did you know it?"); // print message at (2, 1)
}

void loop()
{
}
