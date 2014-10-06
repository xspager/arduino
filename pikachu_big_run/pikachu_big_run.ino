#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

#define LOGO16_GLCD_HEIGHT 48
#define LOGO16_GLCD_WIDTH  30
#define DELAY 150

static unsigned char PROGMEM pikachu1[] = {
B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,
B00000000,B00000011,B00000000,B00000000,
B00000000,B00000100,B10000000,B00000000,
B00000000,B00000100,B10000000,B00000000,
B00000000,B00001000,B01000000,B00000000,
B00000000,B00001000,B01000000,B00000000,
B00000000,B00010000,B00100000,B00000000,
B00000000,B00010000,B00100000,B00000000,
B00000000,B00100000,B01000000,B00000000,
B00000000,B00100000,B10000000,B00000000,
B00000000,B01000001,B00000000,B00000000,
B00000000,B01000010,B00000000,B00000000,
B00000000,B00110001,B10000000,B00000000,
B00000000,B00001000,B01000000,B00000000,
B00000000,B00000110,B00110000,B00000000,
B00000000,B00000001,B00001000,B00000000,
B11110000,B00000010,B00110000,B00111100,
B11101110,B00000100,B11000001,B11011100,
B01100001,B10001011,B00000110,B00011000,
B01110000,B01111100,B11111000,B00111000,
B00110000,B00100000,B00010000,B00110000,
B00011000,B00000000,B00000000,B01100000,
B00000101,B00000000,B00000010,B10000000,
B00000010,B00000000,B00000001,B00000000,
B00000010,B11100000,B00011101,B00000000,
B00000100,B10100000,B00010100,B10000000,
B00000100,B11100000,B00011100,B10000000,
B00000100,B00000011,B00000000,B10000000,
B00001001,B10000000,B00000110,B01000000,
B00001011,B11000011,B00001111,B01000000,
B00001011,B11001100,B11001111,B01000000,
B00000101,B10000000,B00000110,B10000000,
B00000110,B00000000,B00000001,B10000000,
B00001001,B00000000,B00000010,B01000000,
B00001000,B11000000,B00001100,B01000000,
B00010000,B00110000,B00110000,B00100000,
B00010000,B00000000,B00000000,B00100000,
B00010000,B10000000,B00000100,B00100000,
B00010000,B10000000,B00000100,B00100000,
B00001001,B10000000,B00000110,B01000000,
B00000111,B00000000,B00000011,B10000000,
B00000100,B11100000,B00011100,B10000000,
B00000010,B00011111,B11100001,B00000000,
B00000100,B10010000,B00100100,B10000000,
B00000011,B01100000,B00011011,B00000000
};

static unsigned char PROGMEM pikachu2[] = {
B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,
B00000000,B00000001,B10000000,B00000000,
B00000000,B00000010,B01000000,B00000000,
B00000000,B00000010,B01000000,B00000000,
B00000000,B00000100,B00100000,B00000000,
B00000000,B00000100,B00100000,B00000000,
B00000000,B00001000,B00010000,B00000000,
B00000000,B00001000,B00010000,B00000000,
B00000000,B00010000,B00100000,B00000000,
B00000000,B00010000,B01000000,B00000000,
B00000000,B00100000,B10000000,B00000000,
B00000000,B00100001,B00000000,B00000000,
B00000000,B00011000,B11000000,B00000000,
B00000000,B00000110,B00100000,B00000000,
B00000000,B00000001,B00011000,B00000000,
B00000000,B00000110,B00000100,B00000000,
B11000000,B00011000,B00111000,B00001100,
B11110000,B00100000,B11000000,B00111100,
B11101000,B00010011,B00000000,B01011100,
B11100110,B00001001,B00000001,B10011100,
B01100001,B00000101,B00000010,B00011000,
B01100000,B11000111,B10001100,B00011000,
B00100000,B00111000,B01110000,B00010000,
B00100000,B00000000,B00000000,B00010000,
B00010000,B00000000,B00000000,B00100000,
B00001010,B00000000,B00000001,B01000000,
B00000100,B00000000,B00000000,B10000000,
B00000100,B00000000,B00000000,B10000000,
B00001000,B11000000,B00001100,B01000000,
B00001001,B01100000,B00011010,B01000000,
B00001001,B11100000,B00011110,B01000000,
B00001000,B11000011,B00001100,B01000000,
B00010011,B00000000,B00000011,B00100000,
B00010111,B10000000,B00000111,B10100000,
B00010111,B10010011,B00100111,B10100000,
B00101011,B00001100,B11000011,B01010000,
B00101100,B00000000,B00000000,B11010000,
B00100111,B10000000,B00000111,B10010000,
B00100101,B01100000,B00011010,B10010000,
B00011100,B01111000,B01111000,B11100000,
B00010000,B01000000,B00001000,B00100000,
B00011000,B00100000,B00010000,B01100000,
B00001100,B11111111,B11111100,B11000000,
B00000111,B00010000,B00100011,B10000000,
B00000000,B11100000,B00011100,B00000000,
B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000
};

static unsigned char PROGMEM pikachu3[] = {
B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B01100000,B00000000,
B00000000,B00000000,B10010000,B00000000,
B00000000,B00000000,B10010000,B00000000,
B00000000,B00000001,B00001000,B00000000,
B00000000,B00000001,B00001000,B00000000,
B00000000,B00000010,B00000100,B00000000,
B00000000,B00000010,B00000100,B00000000,
B00000000,B00000100,B00001000,B00000000,
B00000000,B00000100,B00010000,B00000000,
B00000000,B00001000,B00100000,B00000000,
B00000000,B00001000,B01000000,B00000000,
B00000000,B00000110,B00110000,B00000000,
B00000000,B00000001,B10001000,B00000000,
B00000000,B00000000,B01000110,B00000000,
B00000000,B00000000,B11100011,B00000000,
B00000000,B00000111,B00001100,B00000000,
B11000000,B00000010,B00110000,B00000000,
B11110000,B00000001,B00100000,B00001100,
B11111000,B00000000,B10010000,B00011100,
B11111100,B00000000,B10010000,B00111100,
B11110010,B00000000,B10100000,B01001100,
B01100001,B00001111,B11110000,B10000100,
B01100000,B10110000,B00001101,B00000100,
B00100000,B01000111,B11100011,B00000100,
B00100000,B01111000,B00011110,B00000100,
B00010000,B11000000,B00000011,B00001000,
B00010000,B00000000,B00000000,B00001000,
B00001000,B00000000,B00000000,B00010000,
B00011010,B00000000,B00000000,B01011000,
B00010100,B00000000,B00000000,B00101000,
B00010100,B00000000,B00000000,B00101000,
B00111000,B00000000,B00000000,B00011100,
B01101000,B01100000,B00000110,B00010100,
B10111000,B10110000,B00001101,B00011100,
B10111000,B11110000,B00001111,B00011100,
B01110000,B01100000,B00000110,B00001100,
B01110011,B00000001,B10000000,B11001100,
B00110111,B10000000,B00000001,B11101100,
B00001111,B10001001,B10010001,B11110000,
B00001011,B00000110,B01100000,B11010000,
B00000100,B00000000,B00000000,B00100000,
B00000111,B00000000,B00000000,B11100000,
B00000010,B11100000,B00000111,B01000000,
B00000010,B00001111,B11110000,B01000000,
B00000001,B00000100,B00100000,B10000000,
B00000001,B10001000,B00010001,B10000000,
B00000000,B10101000,B00010101,B00000000,
B00000000,B01110000,B00001110,B00000000
};

void setup()
{
  display.begin();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);
}

void loop()
{
  display.clearDisplay();
  display.drawBitmap(9, 0,  pikachu1, LOGO16_GLCD_WIDTH, LOGO16_GLCD_HEIGHT, 1);
  display.display();
  delay(DELAY);
  display.clearDisplay();
  display.drawBitmap(9, 0,  pikachu2, LOGO16_GLCD_WIDTH, LOGO16_GLCD_HEIGHT, 1);
  display.display();
  delay(DELAY);
  display.clearDisplay();
  display.drawBitmap(9, 0,  pikachu3, LOGO16_GLCD_WIDTH, LOGO16_GLCD_HEIGHT, 1);
  display.display();
  delay(DELAY);
}