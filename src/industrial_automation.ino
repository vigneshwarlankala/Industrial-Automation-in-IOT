#define BLYNK_TEMPLATE_ID "TMPL31Aq7IPG0"
#define BLYNK_TEMPLATE_NAME "INDUSTRIAL AUTOMATION"

#ifdef ESP32
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#else
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#endif

#define BLYNK_PRINT Serial

// IMPORTANT: Replace these only in your local Arduino IDE.
// Do NOT commit your real credentials to GitHub.
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Device pins
#define device1 D1
#define device2 D2
#define device3 D3
#define buzzer D8

// Manual switch pins
#define sw1 D5
#define sw2 D6
#define sw3 D7

int sw1_sense, sw2_sense, sw3_sense;
int device1_data = 0;
int device2_data = 0;
int device3_data = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);

  pinMode(device1, OUTPUT);
  pinMode(device2, OUTPUT);
  pinMode(device3, OUTPUT);

  digitalWrite(device1, LOW);
  digitalWrite(device2, LOW);
  digitalWrite(device3, LOW);

  pinMode(D0, OUTPUT);
  digitalWrite(D0, LOW);

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  WiFi.begin(ssid, pass);

  Serial.print("Connecting to WiFi ..");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
  }

  Blynk.config(auth);

  Serial.println("READY");
  delay(1000);
}

void beep()
{
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(100);
}

BLYNK_CONNECTED()
{
}

BLYNK_WRITE(V0)
{
  device1_data = param.asInt();
}

BLYNK_WRITE(V1)
{
  device2_data = param.asInt();
}

BLYNK_WRITE(V2)
{
  device3_data = param.asInt();
}

void loop()
{
  Blynk.run();

  manual();

  digitalWrite(device1, device1_data);
  digitalWrite(device2, device2_data);
  digitalWrite(device3, device3_data);

  Blynk.virtualWrite(V0, device1_data);
  Blynk.virtualWrite(V1, device2_data);
  Blynk.virtualWrite(V2, device3_data);

  digitalWrite(2, HIGH);
  delay(300);
  digitalWrite(2, LOW);
  delay(200);
}

void manual()
{
  sw1_sense = digitalRead(sw1);
  sw1_sense = 1 - sw1_sense;

  sw2_sense = digitalRead(sw2);
  sw2_sense = 1 - sw2_sense;

  sw3_sense = digitalRead(sw3);
  sw3_sense = 1 - sw3_sense;

  if (sw1_sense == 1)
  {
    device1_data = !device1_data;
    beep();
  }
  else if (sw2_sense == 1)
  {
    device2_data = !device2_data;
    beep();
  }
  else if (sw3_sense == 1)
  {
    device3_data = !device3_data;
    beep();
  }
}
