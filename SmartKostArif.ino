#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SimpleDHT.h>

int pinDHT22 = 10;
SimpleDHT22 dht22;

const char* ssid = "MERANGSANG";
const char* password = "juhpattu";

int lampu1, lampu2, kipas, kunci;
int pintu = 0;
int jendela = 0;
bool alarm = 1;
float temperature = 0;
float humidity = 0;
int security;

void setup () {

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(5, OUTPUT); pinMode(4, OUTPUT); pinMode(0, OUTPUT); pinMode(2, OUTPUT);
  pinMode(14, INPUT); pinMode(12, INPUT); pinMode(13, OUTPUT);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print("..");
  }

}

void loop() {
  dht();
  kirim();
  terima();
}





