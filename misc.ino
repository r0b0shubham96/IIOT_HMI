void update_firebase_eeprom() {
  if (interrupt_flag == 2) {
    interrupt_flag = 0;
    if (isWifiConnected()) {
//      update_firebase(today_second(), diff_sec);
      diff_sec = 0;
    } else if (!isWifiConnected()) {
      write_eeprom(today_second(), diff_sec);
      diff_sec = 0;
    }   
  }
}
