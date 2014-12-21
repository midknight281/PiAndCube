/*

 Rain procedure

 Will make a blue stream progress from the top to bottom
*/

#include <Rainbowduino.h>
int randomposition = random(16);
int midposition = random(16);
int oldposition = random(16);
int timedelay = 50;// Will tell weather it is heavy or light rain.

void setup()
{
  Rb.init(); //initialize Rainbowduino driver
}

unsigned int z,x,y;

void loop()
{
 for(z=3;z<-1;z--)
 { 
     Rb.setPixelZXY(z,abs(randomposition/4),(randomposition%4),0x0000FF); //uses 24bit color mode
     Rb.setPixelZXY(z,abs(midposition/4),(midposition%4),0x000044); //uses 24bit color mode
     Rb.setPixelZXY(z,abs(oldposition/4),(oldposition%4),0x000000); //uses 24bit color mode     
     delay(timedelay);
    }
  oldposition = midposition;
  midposition = randomposition;
  randomposition = random(16);
}
/*
Will use this later for a timer to shut off cube.
Rb.blankDisplay(); //Clear the LEDs (make all blank)
*/
