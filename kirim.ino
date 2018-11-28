void kirim()
{
  pintu = digitalRead(14);
  jendela = digitalRead(12);
  
//  if (pintu == 0 && security == 1 || jendela == 0 && security == 1)
//  {
//    alarm = 1; digitalWrite(13, 1);
//  }
  if (security == 1){
    if(jendela == 0){
      alarm = 1; 
      digitalWrite(13, 1);
    }
    if(pintu == 0){
      alarm = 1;
      digitalWrite(13, 1);
    }
  }
  else {
    alarm = 0; digitalWrite(13, 0);
  }

  Serial.print("jendela=");
  Serial.print(jendela);
  Serial.print("pintu=");
  Serial.println(pintu);
  if (WiFi.status() == WL_CONNECTED) {
    String link = "http://smartkost.esy.es/kendali.php?jendela=";
    link += jendela;
    link += "&pintu=";
    link += pintu;
    link += "&humidity=";
    link += humidity;
    link += "&temperatur=";
    link += temperature;
    link += "&alarm=";
    link += alarm;

    HTTPClient http;
    http.begin(link);
    int httpCode = http.GET();
  }

}
