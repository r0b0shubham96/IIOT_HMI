void write_eeprom(long time_duration, int work_time) {
  int w_addr = 0;

  while(read_write_eeprom(w_addr) != 255) {
    w_addr += 5;
    if(w_addr >= 512) {
      EEPROM.commit();
      return;
    }
  }
  
  int rem_value = time_duration;
  int write_value = rem_value % 255;
  EEPROM.write(w_addr+2, (write_value));

  rem_value = (rem_value - write_value)/255;
  write_value = rem_value % 255;
  EEPROM.write(w_addr+1, (write_value));

  rem_value = (rem_value - write_value)/255;
  write_value = rem_value % 255;
  EEPROM.write(w_addr, (write_value));

  rem_value = work_time;
  write_value = rem_value % 255;
  EEPROM.write(w_addr+4, (write_value));

  rem_value = (rem_value - write_value)/255;
  write_value = rem_value % 255;
  EEPROM.write(w_addr+3, (write_value));
}

void delete_eeprom(int d_addr) {
  EEPROM.write(d_addr, 255);
}
