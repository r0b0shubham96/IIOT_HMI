void setup_clear_eeprom() {
  for (int i = 0; i < 512; i++) {
    EEPROM.write(i, 255);
  }
}
