void setup_wifi(char* ssid, char* psd) {
  WiFi.begin(ssid, psd);
  Serial.println(ssid);
  Serial.println(psd);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    wifiOrHotspot++;
    if(wifiOrHotspot > 60) {
      wifi_ssid = "";
      wifi_password = "";
      setup_hotspot();
      wifiOrHotspot = 0;
//      break;
    }   
  }

  wifi_ssid = ssid;
  wifi_password = psd;

  Serial.println();
  Serial.println(ssid);
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
}

boolean isWifiConnected() {
  if ((WiFi.status() != WL_CONNECTED)) {
    return false;
  }
  return true;
}
