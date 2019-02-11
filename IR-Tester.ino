#include <IRremote.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const int RECV_PIN= 7;  // IR data pin
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.clearDisplay();
  display.println("IR Reader by Alex");  // start screen.
  display.println("V 1.1");
  display.display();
  delay(500);
  display.clearDisplay();
  display.display();
}

void loop(){
  if (irrecv.decode(&results)){
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.clearDisplay();
        diplay.print("Hex: ");
        display.println(results.value, HEX);  // print IR code in Hex
        display.println();
        display.println("Binary:");
        display.println();
        display.println(results.value, BIN);  // print IR code in Binary
        display.display();
        irrecv.resume();
  }
}
