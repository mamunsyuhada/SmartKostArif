void terima()
{
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;                                   
    http.begin("http://smartkost.esy.es/status.php"); //0 0 0 0 1 1 0 70 29 *1
    int httpCode = http.GET();                                                                  //Send the request

    if (httpCode > 0) {
      String payload = http.getString();

      String lampu1string = payload.substring(0, 1);
      String lampu2string = payload.substring(2, 3);
      String kipasstring = payload.substring(4, 5);
      String kuncistring = payload.substring(6, 7);


      int posisisec = payload.indexOf('*');
      String securitystring = payload.substring(posisisec + 1, payload.length());

      lampu1 = lampu1string.toInt();
      lampu2 = lampu2string.toInt();
      kipas = kipasstring.toInt();
      kunci = kuncistring.toInt();
      security = securitystring.toInt();

      Serial.println(lampu1string);

      Serial.println(lampu2string);
      Serial.println(kipasstring);
      Serial.println(kuncistring);
      Serial.println(security);
      Serial.println("--------------");

      digitalWrite(5, !lampu1);
      digitalWrite(4, !lampu2);
      digitalWrite(0, !kipas);
      digitalWrite(2, !kunci);

    }

    http.end();

  }
}
