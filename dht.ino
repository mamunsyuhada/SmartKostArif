void dht()
{

  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(pinDHT22, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT22 failed, err="); Serial.println(err);
    delay(2000);
    return;
  }

  Serial.print("suhu=");
  Serial.print(temperature);
  Serial.print(" humidity=");
  Serial.println(humidity);
}
