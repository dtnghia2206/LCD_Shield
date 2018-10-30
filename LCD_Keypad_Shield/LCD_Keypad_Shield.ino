#include <LiquidCrystal.h>
#include <DFR_LCD_Keypad.h>

#define JUMPING_GAME 1
#define PLAYING_MUSIC 2
#define SETTING_PASSWORD 3

LiquidCrystal lcd(8,9,4,5,6,7); 
DFR_LCD_Keypad keypad(A0, &lcd);

int led=13;
int last_key, key;
int selection_list;
int final_selection;
int final_jumping_selection;

bool accessGame = true;
bool accessMenu = true;
bool finalChoice =  false;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("HELLO ^-^!");
  pinMode(led, OUTPUT);
  delay(1000);
  lcd.clear();
  cli();
  // Setup Pin Change Interrupt for Buttons
  PCICR =0x02;                  // Enable 'PCIE1' bit of PCICR Pin Change Interrupt the PCINT1 interrupt
  PCMSK1 = 0b00000001;          // Pin Change Interrupt Mask ( NA, RESET, A5, A4, A3, A2, A1, A0 ) - Activate A0 
  sei(); 
}


void loop()
{
  if(accessMenu) {
    do {
      //selection_menu();
      main_menu();
    } while(!finalChoice);
    finalChoice = false;
    accessMenu = false;
  }
  switch (final_selection) {
    case 1:
      if(accessGame == true) {
        accessMenu = true;
        accessGame = false;
      }
      jumping_game_init();
      break;
    case 2:
      if(accessGame == true) {
        pacman_setup();
        accessGame = false;
      }
      pacman_loop();
      break;
  }
}
