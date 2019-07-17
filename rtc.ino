void setup_rtc() {
  Serial.println("sr");
    Rtc.Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    if (!Rtc.IsDateTimeValid()) 
    {
        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    RtcDateTime now = Rtc.GetDateTime();
    
    Rtc.Enable32kHzPin(false);
    Rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone);
}

int now_second() {
  Serial.println("ns");
  RtcDateTime now = Rtc.GetDateTime();

  return now.TotalSeconds();
}

String now_dateTime() {
  Serial.println("ndt");
  RtcDateTime now = Rtc.GetDateTime();

  String dateTime = String(now.Day()) + "/" + String(now.Month()) + "/" + String(now.Year()) + "   " + String(now.Hour()) + ":" + String(now.Minute()) + ":" + String(now.Second());
  return dateTime;
}

int today_second() {
  RtcDateTime now = Rtc.GetDateTime();

  int today_sec = ((now.Hour() * 3600) + (now.Minute() * 60) + (now.Second()));
  return today_sec;
}
