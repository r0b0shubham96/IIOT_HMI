char* ssd = "";
char* psd = "";

int z = 0;

void handleRoot() {
//  <meta http-equiv='refresh' content='5'/>\

server.send(200, "text/html", "<html>\
  <head>\
    <title>ESP8266 Demo</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Hello from ESP8266!</h1>\
     <form action=\"/action_page.php\" method=\"get\">\
  Wifi Name:<br>\
  <input type=\"text\" name=\"SSID\"><br>\
  Password:<br>\
  <input type=\"text\" name=\"Password\"><br><br>\
  <input type=\"submit\" value=\"Submit\">\
</form> \
  </body>\
</html>");

}

void onLed() {
  server.send(200, "text/html", page);
//  digitalWrite(led, !digitalRead(led));
    ssd = "";
    psd = "";
  if (server.args() > 0) {
    for ( uint8_t i = 0; i < server.args(); i++) {
      if (server.argName(i) == "SSID") {
        Serial.println(server.argName(i));
        Serial.println(server.arg(i));
        ssd = string2char(String(server.arg(i)));
        Serial.println(string2char(String(server.arg(i))));
        z = i;
     }
      if (server.argName(i) == "Password") {
        Serial.println(server.argName(i));
        Serial.println(server.arg(i));
        psd = string2char(String(server.arg(i)));
        Serial.println(string2char(String(server.arg(i))));
        wifi_ssid = "";
        wifi_password = "";
        setup_wifi(string2char(String(server.arg(z))), string2char(String(server.arg(i))));        
      }
      
    }
//    Serial.println(server.arg(1));
  }
}

void setup_hotspot() {
  Serial.println("hotspot started");
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/action_page.php", onLed);
  server.begin();

  ssd = "";
  psd = "";
  
  start_hotspot();
  
//  while(strlen(wifi_ssid) == 0 && strlen(wifi_password) == 0) {
//    start_hotspot();
//  }

  while(server.args() < 2) {
    start_hotspot();
  }
  while (String(server.arg(0)).length() == 0 && String(server.arg(1)) == 0) {
    start_hotspot();
  }
}

void start_hotspot() {
  server.handleClient();
}
