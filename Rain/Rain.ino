/*

 Rain procedure

 Will make a blue stream progress from the top to bottom
*/

#include <Rainbowduino.h>
int randomposition = random(12);
int oldposition = random(12);
int timedelay = 25;// Will tell weather it is heavy or light rain.

void setup()
{
  Rb.init(); //initialize Rainbowduino driver
}

unsigned int z,x,y;

void loop()
{
 for(z=3;z>0;z--)
 { 
     Rb.setPixelZXY(z,abs(randomposition/4),(randomposition%4),0x0000FF); //uses 24bit color mode
     Rb.setPixelZXY(z,abs(oldposition/4),(oldposition%4),0x000000); //uses 24bit color mode     
     delay(timedelay);
    }
  Rb.setPixelZXY(z,abs(randomposition/4),(randomposition%4),0x0000FF); //uses 24bit color mode
  Rb.setPixelZXY(z,abs(oldposition/4),(oldposition%4),0x000000); //uses 24bit color mode     
  oldposition = randomposition;
  randomposition = random(12);
}
/*
Will use this later for a timer to shut off cube.
Rb.blankDisplay(); //Clear the LEDs (make all blank)
*/
