
#include "FastLED.h"


// define some pins and settings for LED strip
#define DATA_PIN    5
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS   250
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

void setup()
{ry

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  lcd.clear();
}

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, confetti, sinelon, juggle, bpm };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 9);
  lcd.print("LCD Program");
  lcd.setCursor(9, 0);
  lcd.print(millis() / 1000);    // display seconds elapsed since power-up


  lcd.setCursor(0, 1);           // move to the begining of the second line
  lcd_key = read_LCD_buttons();  // read the buttons


  if (menu == 0) {
    if (menuitem == 0) {
      lcd.print("Pattern Menu");
      switch (lcd_key)               // depending on which button was pushed, we perform an action
      {
        case btnRIGHT:
          {
            if (menu >= 3 ) {
              menu = 0
            }
              menu = 0
            }
            else {
              menu + 1
            }
            break;
          }
        case btnLEFT:
          {
            if (menu <= 0 ) {
              menu = 3
            }
            else {
              menu - 1
            }
            break;
          }
        case btnUP:
          {
            if (menuitem >= 2 ) {
              menuitem = 0
            }
            else {
              menuitem + 1
            }
            break;
          }
        case btnDOWN:
          {
            if (menu <= 0 ) {
              menu = 2
            }
            else {
              menu - 1
            }
            break;
          }
        case btnSELECT:
          {
            lcd.setCursor(0, 1);
            lcd.print("~~~SELECT~~~");
            break;
          }
        case btnNONE:
          {
            break;
          }
      }
    }
  }
 elseif (menu == 2) {
  if (menuitem == 0) {
      lcd.print("Brightness +-");
      switch (lcd_key)               // depending on which button was pushed, we perform an action
      {
        case btnRIGHT:
          {
            if (menu >= 3 ) {
              menu = 0
            }
            else {
              menu + 1
            }
            break;
          }
        case btnLEFT:
          {
            if (menu <= 0 ) {
              menu = 3
            }
            else {
              menu - 1
            }
            break;
          }
        case btnUP:
          {
            BRIGHTNESS + 10
            break;
          }
        case btnDOWN:
          {
            BRIGHTNESS - 10
            break;
          }
        case btnSELECT:
          {
            break;
          }
        case btnNONE:
          {
            break;
          }
      }
    }
  }
   elseif (menu == 2) {
  if (menuitem == 0) {
      lcd.print("Brightness +-");
      switch (lcd_key)               // depending on which button was pushed, we perform an action
      {
        case btnRIGHT:
          {
            if (menu >= 3 ) {
              menu = 0
            }
            else {
              menu + 1
            }
            break;
          }
        case btnLEFT:
          {
            if (menu <= 0 ) {
              menu = 3
            }
            else {
              menu - 1
            }
            break;
          }
        case btnUP:
          {
            BRIGHTNESS + 10
            break;
          }
        case btnDOWN:
          {
            BRIGHTNESS - 10
            break;
          }
        case btnSELECT:
          {
            break;
          }
        case btnNONE:
          {
            break;
          }
      }
    }
  }
   elseif (menu == 3) {
  if (menuitem == 0) {
      lcd.print("~DEVICE OFF~");
      switch (lcd_key)               // depending on which button was pushed, we perform an action
      {
        case btnRIGHT:
          {
            if (menu >= 3 ) {
              menu = 0
            }
            else {
              menu + 1
            }
            break;
          }
        case btnLEFT:
          {
            if (menu <= 0 ) {
              menu = 3
            }
            else {
              menu - 1
            }
            break;
          }
        case btnUP:
          {
            break;
          }
        case btnDOWN:
          {
            break;
          }
        case btnSELECT:
          {
            break;
          }
        case btnNONE:
          {
            break;
          }
      }
    }
  }
}
