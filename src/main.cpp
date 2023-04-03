#include <Arduino.h>
#include <LiquidCrystal.h>
#include "functions.h"

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

unsigned char reset(unsigned char *i, unsigned char *but);
void check_deactivate(unsigned char *but_tab, unsigned char first_idx, unsigned char last_idx);
void cut_text(char** save_mem, const char* text, const unsigned char no_slices);

unsigned char i = 0;

unsigned char but[3] = {HIGH, HIGH, HIGH};
const unsigned char no_slices = 3;
const char *text = "Gratulacje";

char *sliced[no_slices];

void setup() {

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Zgadnij kod!");
  pinMode(8, INPUT_PULLUP); //Przycisk 1
  pinMode(9, INPUT_PULLUP); //Przycisk 2
  pinMode(10, INPUT_PULLUP); //Przycisk 3
  cut_text(sliced, text, no_slices); 
  
}

void loop() {
  
  check_deactivate(but, 8, 10);
  
  if (but[0] == LOW){
    if (i == 0) i = reset(&i, but);
    lcd.setCursor(0, 1);
    lcd.print("bob");
    if (but[1] == LOW){
      if (i == 1) i = reset(&i, but);
      lcd.setCursor(3, 1);
      lcd.print("tul");
      if (but[2] == LOW){
        lcd.setCursor(6, 1);
        lcd.print("acje");
      }      
    }
  }
}