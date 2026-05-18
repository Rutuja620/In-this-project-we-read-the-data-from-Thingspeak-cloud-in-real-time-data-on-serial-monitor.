#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "realme 9i";
const char* pass = "12344321";

WiFiClient client;

unsigned long myChannelNumber = 3386939;

const char* myReadAPIKey = "PKUPYA7PBODUW43E";

const unsigned int FieldToMonitor = 1;

long count;

void setup() {

    Serial.begin(115200);

    ThingSpeak.begin(client);

    connectToWiFi();
}

void loop() {

    count = ThingSpeak.readLongField(myChannelNumber,
                                     FieldToMonitor,
                                     myReadAPIKey);

    if (ThingSpeak.getLastReadStatus() == 200) {

        Serial.println("Read: " + String(count));

    } else {

        Serial.println("Error reading channel");
    }

    delay(15000);
}

void connectToWiFi() {

    Serial.print("Connecting to WiFi...");

    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {

        delay(2000);

        Serial.print(".");
    }

    Serial.println("\nConnected!");
}
