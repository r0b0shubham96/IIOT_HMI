byte read_write_eeprom(int w_addr) {
  byte value;
  value = EEPROM.read(w_addr);
  return value; 
}

void read_eeprom() {
  int r_addr = 0;
  byte value;
  for(r_addr = 0; r_addr < 512; r_addr += 5){
    value = EEPROM.read(r_addr);
    if (value != 255) {
      int tt = 0;
      int td = 0;
      for (int i = 0; i < 5; i++) {
        value = EEPROM.read((r_addr+i));
        if (i == 0) {
          tt = tt + value * 255 * 255;
        } else if(i == 1) {
          tt = tt + value * 255;
        } else if(i == 2) {
          tt = tt + value;
        } else if(i == 3) {
          td = td + value * 255;
        } else if(i == 4) {
          td = td + value;
        }
        Serial.print((r_addr+i));
        Serial.print("\t");
        Serial.print(value, DEC);
        Serial.println();
      }
      if (isWifiConnected()) {
//        update_firebase_eep(tt, td);
        delete_eeprom(r_addr);
      } else {
        break;
      }
//      update_firebase(tt, td);
//      delete_eeprom(r_addr);
    }
  }
}
