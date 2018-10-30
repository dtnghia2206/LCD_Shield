bool btnUpPressed = false;
bool btnDownPressed = false;
bool btnRightPressed = false;
bool btnLeftPressed = false;
bool btnSelectPressed = false;

enum Buttons { 
  UP, 
  DOWN, 
  RIGHT, 
  LEFT, 
  SELECT, 
  NONE 
};
Buttons Current_Button = NONE;

ISR(PCINT1_vect) {
   ButtonCheck(analogRead(0));
}

void ButtonCheck(uint16_t adc_value) {
    // The ISR will trigger when button is pressed and when it is let-go
    if (adc_value >= DFR_LCD_KEYPAD_KEY_NONE_ADC_LOW && adc_value <= DFR_LCD_KEYPAD_KEY_NONE_ADC_HIGH) 
    { 
      Current_Button = NONE; 
    }
    if (adc_value >= 0 && adc_value <= 20) 
    { 
      Current_Button = RIGHT; 
      btnRightPressed = true;
    }
    if (adc_value >= 345 && adc_value <= 365)  //354 or 355
    { 
      Current_Button = LEFT;
      btnLeftPressed = true;
    }
    if (adc_value >= 110 && adc_value <= 130) // 119 or 120
    { 
      Current_Button = UP;
      btnUpPressed = true;
    }
    if (adc_value >= 240 && adc_value <= 260) //250 or 251
    { 
      Current_Button = DOWN;
      btnDownPressed = true;
    }
    // not working
    if (adc_value >= 700 && adc_value <= 800) 
    { 
      Current_Button = SELECT;
      btnSelectPressed = true;
    }
}
