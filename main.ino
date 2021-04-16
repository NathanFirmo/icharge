#include <SPI.h>      
#include <Ethernet.h>


byte mac[] = {0xDe, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

unsigned short int ldrValor = 0;

//IPAddress ip(10, 33, 250, 117); 
IPAddress ip(192, 168, 0, 105);   // Here, you must put the Arduino's IP 

#define Led1  7
#define ldrPin  A0

EthernetServer server(80);

int pinLed1 = 8;
int led = 0;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(ldrPin, INPUT);
  digitalWrite(Led1, LOW);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  if (digitalRead(pinLed1) == HIGH) led = 1;
  else if (digitalRead(pinLed1) == LOW) led = 0;

  pinMode(pinLed1, OUTPUT);

  digitalWrite(pinLed1, LOW);

  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
}

void loop()
{
  EthernetClient client = server.available();
  if (client) {
    Serial.println("New client");
    boolean currentLineIsBlank = true;
    String DatEth;
    while (client.connected()) {
      if (client.available()) {

        char c = client.read();
        Serial.write(c);

        DatEth.concat(c);
        if (DatEth.endsWith("/&ON")) {
          led = 1;
        }
        if (DatEth.endsWith("/&OFF")) {
          led = 0;
        }

        if (c == '\n' && currentLineIsBlank) {
          ldrValor = analogRead(ldrPin);
          Serial.println(ldrValor);
          if (ldrValor <= 50 && digitalRead(Led1) == LOW)
          {
            digitalWrite(Led1, HIGH);
          }
          delay (2);
          if (ldrValor > 50 && digitalRead(Led1) == HIGH)
          {
            digitalWrite(Led1, LOW);
          }
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 1");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          if (digitalRead(Led1) == HIGH)
          {
            client.println("<center><h1>\n"
                           "Estado do LED SENSOR <span style='background: #00FF00; border-radius:5px; padding:5px'>"
                           "ON</span>.\n"
                           "</h1></center>\n");
          }
          else
          {
            client.println("<center><h1>\n"
                           "Estado do LED SENSOR <span style='background: #FF0000 ; border-radius:5px; padding:5px'>"
                           "OFF</span>.\n"
                           "</h1></center>\n");
          }
          if (led == 1)
          {
            client.println("</br><center><h1>\n"
                           "Estado do LED HTML <span style='background: #00FF00; border-radius:5px; padding:5px'>"
                           "ON</span>.\n"
                           "</h1></center>\n");
          }
          else
          {
            client.println("</br><center><h1>\n"
                           "Estado do LED HTML <span style='background: #FF0000 ; border-radius:5px; padding:5px'>"
                           "OFF</span>.\n"
                           "</h1></center>\n");
          }
          client.println("<center><form method='get' action='/&ON'><button type='submit'>Ligar LED HTML</button></form></center>"
                         "</br>"
                         "<center><form method='get' action='/&OFF'><button type='submit'>Desligar LED HTML</button></form></center>"
                         ""
                         "");

          client.println("</html>");

          if (led == 1) {
            digitalWrite(pinLed1, HIGH);
          }

          if (led == 0) {
            digitalWrite(pinLed1, LOW);
          }

          break;
        }

        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }

      }

    }

    delay(1);

    client.stop();
    Serial.println("Client disconnected");

  }
  ldrValor = analogRead(ldrPin);
  Serial.println(ldrValor);
  if (ldrValor <= 50 && digitalRead(Led1) == LOW)
  {
    digitalWrite(Led1, HIGH);
  }
  delay (2);
  if (ldrValor > 50 && digitalRead(Led1) == HIGH)
  {
    digitalWrite(Led1, LOW);
  }
}
