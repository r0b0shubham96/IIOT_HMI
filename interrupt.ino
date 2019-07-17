void setup_interrupt() {
  Serial.println("SI");
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, RISING);
}

//void handleInterrupt() {
////  Serial.println("handleInterrupt:");
////  Serial.println(interrupt_flag);
//  if (interrupt_flag == 0) {
//    interrupt_flag = 1;
//    diff_sec = 0;
//    total_sec = now_second();
//  } else if (interrupt_flag == 1){
//    interrupt_flag = 2;
//    diff_sec = now_second() - total_sec;
////    update_firebase(now_dateTime(), now_second(), diff_sec);
//  }
////  update_firebase();
//}

void handleInterrupt() {
  detachInterrupt(digitalPinToInterrupt(interruptPin));

  delayMicroseconds(4000);
  int interr_count = 0;
  while (interr_count < 1000 && interr_count > -1000) {
    if (digitalRead(interruptPin) == LOW) {
      interr_count++;
    } else {
      interr_count--;
    }
    delayMicroseconds(100);
  }

//  delayMicroseconds(15000);
//  delay(150);
  
  if (interrupt_flag == 0) {
    interrupt_flag = 1;
    diff_sec = 0;
    total_sec = now_second();
//    int_diff_sec0 = 
//    if((now_second() - int_diff_sec0) < 3) {
//      interrupt_flag = 0;
////      diff_sec = 0;
//    }
  } else if (interrupt_flag == 1){
    interrupt_flag = 2;
//    int_diff_sec0 = now_second();
    diff_sec = now_second() - total_sec;
    total_sec = now_second();
//    int int_diff_sec1 = diff_sec;
//    if(int_diff_sec1 < 3) {
//      interrupt_flag = 1;
//      diff_sec = 0;
//    }
//    update_firebase(now_dateTime(), now_second(), diff_sec);
  }
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, RISING);
}
