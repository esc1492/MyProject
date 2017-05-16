// BT210 bluetooth string test code
// for testing BT210 bluetooth

#include <string.h>
#include <stdio.h>

void setup()
{
  Serial2.begin(57600);  
  Serial2.print("BT210 connect!");
  pinMode(BOARD_LED_PIN, OUTPUT);
  toggleLED();
}

void loop()
{
  char string[32];

  int i = 0;
#if 0  
  while(SerialUSB.available() > 0)
  {
    char ch = SerialUSB.read();  //send data coming from USB to Serial2
    string[i++] = ch;
   }
  
  string[i] = '\0';
 
  Serial2.write(string);  //send data coming from USB to Serial2

  i = 0;
 #endif
 
  while(Serial2.available() > 0)
  {
    char ch = Serial2.read();
    string[i++] = ch;
  }
  
  string[i] = '\0';
  
  //SerialUSB.write(string); //send data coming from Serial2 to USB(PC)
  //Serial2.write(string); //send data coming from Serial2 to USB(PC)
  
  delay(5);

  if (strstr(string, "go") != NULL)
  {
    toggleLED(); delay(1000);
    toggleLED(); delay(1000); toggleLED();
  }
  else if (strstr(string, "back") != NULL)
  {
    toggleLED(); delay(500);
    toggleLED(); delay(500); toggleLED();
  }
  else if (strstr(string, "left") != NULL)
  {
    toggleLED(); delay(500);
    toggleLED(); delay(1000); toggleLED();
  }
  else if (strstr(string, "right") != NULL)
  {
    toggleLED(); delay(1000);
    toggleLED(); delay(500); toggleLED();
  }  
}


