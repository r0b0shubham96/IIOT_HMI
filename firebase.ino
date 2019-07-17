void setup_firebase() {
  Serial.println("sf");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void update_firebase(String dt, int tsec, int time_diff) {
  Serial.println("uf");
  Firebase.pushString("Data/dt", dt);
  
  Firebase.pushInt("Data/milli", tsec);
  
  Firebase.pushInt("Data/time_diff", time_diff);
}

void update_firebase_eep(int tsec, int time_diff) {
  Serial.println("uf");
  Firebase.pushInt("Data/milli", tsec);
  
  Firebase.pushInt("Data/time_diff", time_diff);
}
