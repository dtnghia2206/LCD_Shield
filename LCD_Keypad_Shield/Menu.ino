void selection_menu() {
  cli();
  last_key = keypad.get_last_key();
  key      = keypad.read_key();
  if (key != last_key) {
    switch (key) {
      case KEY_RIGHT:
        btnRightPressed = true;
        break;
        
      case KEY_LEFT:
        btnLeftPressed = true;
        break;
        
      case KEY_DOWN:
        btnDownPressed = true;
        break;
        
      case KEY_UP:
        btnUpPressed = true;
        break;
        
      case KEY_SELECT:
        btnUpPressed = true;
        break;
        
      default:
        lcd.print("NONE");
        break;
    }
  }
  sei(); 
}

void main_menu() {
  if (selection_list > 4 || selection_list < 1) {
    selection_list == 1;
  }
  if (btnRightPressed) {
    selection_list++;
    btnRightPressed = false;
  }
  if (btnLeftPressed) {
    selection_list--;
    btnLeftPressed = false;
  }
  lcd.clear();
  switch (selection_list) {
    case 1:
      lcd.setCursor(0,0);
      lcd.print("GAME 1:");
      lcd.setCursor(0,1);
      lcd.print("< JUMPING MAN >");
      delay(500);
      if(btnUpPressed) {
        final_selection = 1;
        btnUpPressed = false;
        finalChoice = true;
      } 
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("GAME 2:");
      lcd.setCursor(0,1);
      lcd.print("<    PACMAN    >");
      delay(500);
      if(btnUpPressed) {
        final_selection = 2;
        btnUpPressed = false;
        finalChoice = true;
      }
      break;
    default: selection_list = 1;
      break;
  }
}

void jumping_game_menu() {
  if (selection_list > 4 || selection_list < 1) {
    selection_list == 1;
  }
  if (btnRightPressed) {
    selection_list++;
    btnRightPressed = false;
  }
  if (btnLeftPressed) {
    selection_list--;
    btnLeftPressed = false;
  }
  lcd.clear();
  switch (selection_list) {
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Select mode:");
      lcd.setCursor(0,1);
      lcd.print("<     Easy     >");
      delay(500);
      if(btnUpPressed) {
        final_jumping_selection = 1;
        btnUpPressed = false;
        finalChoice = true;
      } 
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("Select mode:");
      lcd.setCursor(0,1);
      lcd.print("<    Medium    >");
      delay(500);
      if(btnUpPressed) {
        final_jumping_selection = 2;
        btnUpPressed = false;
        finalChoice = true;
      }
      break;

    case 3:
      lcd.setCursor(0,0);
      lcd.print("Select mode:");
      lcd.setCursor(0,1);
      lcd.print("<     Hard     >");
      delay(500);
      if(btnUpPressed) {
        final_jumping_selection = 3;
        btnUpPressed = false;
        finalChoice = true;
      }
      break;
      
    case 4:
      lcd.setCursor(0,0);
      lcd.print("Select mode:");
      lcd.setCursor(0,1);
      lcd.print("<  impossible  >");
      delay(500);
      if(btnUpPressed) {
        final_jumping_selection = 4;
        btnUpPressed = false;
        finalChoice = true;
      }
      break; 
      
    default: selection_list = 1;
      break;
  }
}
