/*

 Rain procedure

 Will make a blue stream progress from the top to bottom
*/

#include <Rainbowduino.h>


void setup()
{
  Rb.init(); //initialize Rainbowduino driver
  
}

unsigned int z,x,y;

void loop()
{

  ShowItRaining(50,0,66);
}


void ShowItRaining(int speed,int lightning,int temperature)
{
  int rainDropPosition[3] = {random(16),random(16),random(16)};
  int timedelay = 50;// Will tell weather it is heavy or light rain.
  int numberOfIterations = 20000;
  int x;
  for (x=1;x<numberOfIterations;x++)
  {
  for(z=3;z<-1;z--)
    { 
     Rb.setPixelZXY(z,abs(rainDropPosition[0]/4),(rainDropPosition[0]%4),0x0000FF); //uses 24bit color mode
     Rb.setPixelZXY(z,abs(rainDropPosition[1]/4),(rainDropPosition[1]%4),0x000038); //uses 24bit color mode
     Rb.setPixelZXY(z,abs(rainDropPosition[2]/4),(rainDropPosition[2]%4),0x000000); //uses 24bit color mode
     delay(timedelay);
    }
  rainDropPosition[2] = rainDropPosition[1];
  rainDropPosition[1] = rainDropPosition[0];
  rainDropPosition[0]= random(16);
  }  
  Rb.blankDisplay(); //Clear the LEDs (make all blank)
}

