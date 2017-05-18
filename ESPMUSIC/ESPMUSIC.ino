#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space

#include <CayenneDefines.h>
#include <BlynkSimpleEsp8266.h>
#include <CayenneWifiClient.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <JQ6500_Serial.h>

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
//char token[] = "9wxsvo4cjv"; 
char token[] = "xs1d335k4z"; //ESP MUSIC
//char token[] = "9wxsvo4cjv";
char ssid[] = "SINKHOLE-C";
char password[] = "tecumseh";

// Create the mp3 module object, 
//   Arduino Pin 4 is connected to TX of the JQ6500
//   Arduino Pin 5 is connected to RX of the JQ6500
JQ6500_Serial mp3(4,5);

void setup()
{
  Serial.begin(9600);
  
  Cayenne.begin(token, ssid, password);

  mp3.begin(9600);
  mp3.reset();
  mp3.setVolume(20);
  mp3.setLoopMode(MP3_LOOP_ALL);
  mp3.play();  
}

void loop()
{
  Cayenne.run();
}

CAYENNE_IN(V0)
{
  int volume = getValue.asInt();

  //android widget hack
  if(volume <= 1024)
  {
    //android widget scales over 1024
    volume = 30*volume/1024;
  }
  else
  {
    //browser widget scales over set range * 1000
    volume /= 1000;
  }
    
  Serial.print("Volume:");
  Serial.println(volume);
  
  mp3.setVolume(volume);  
}


CAYENNE_IN(V1)
{
  mp3.prev();
}

CAYENNE_IN(V2)
{
  mp3.next();
}

CAYENNE_IN(V3)
{
  mp3.pause();
}

CAYENNE_IN(V4)
{
  mp3.play();
}

CAYENNE_IN(V5)
{
  mp3.playFileByIndexNumber(1);
}

CAYENNE_IN(V6)
{
  mp3.playFileByIndexNumber(2);
}

CAYENNE_IN(V7)
{
  mp3.playFileByIndexNumber(3);
}

CAYENNE_IN(V8)
{
  mp3.playFileByIndexNumber(4);
}

CAYENNE_IN(V9)
{
  mp3.playFileByIndexNumber(5);
}

