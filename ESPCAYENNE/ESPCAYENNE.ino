#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space

#include <CayenneDefines.h>
#include <BlynkSimpleEsp8266.h>
#include <CayenneWifiClient.h>

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "qii6v5ffep"; //El Diabla
char ssid[] = "SINKHOLE-C";
char password[] = "tecumseh";

void setup()
{
  Serial.begin(9600);  
  
  Cayenne.begin(token, ssid, password);
}

void loop()
{
  Cayenne.run();
}
