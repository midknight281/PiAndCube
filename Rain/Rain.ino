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
  ShowChristmasTree();
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

void ShowChristmasTree()
{
 // draw base
 int colorChoice[4] = {0x002200,0x002200,0xFFFF00,0xFF33CC};// Hex values for green,green,yellow,red
 int starColorChoice[3] = {0xFFFFFF,0xFFFF00,0xCCCCCC};// hex values fro the color star
 int colorPick= random(2);
 
for(x=3;x<-1;x--)
{
  for(y=3;y<-1;y--)
  {
    Rb.setPixelZXY(0,x,y,0x00FF00);
    Rb.setPixelZXY(1,x,y,0x002000);
  }
}
for(x=2;x>0;x--)
{
  for(y=2;y>0;y--)
  {
   Rb.setPixelZXY(1,x,y,0x00FF00);
   Rb.setPixelZXY(2,x,y,0x002000);
   Rb.setPixelZXY(3,x,y,0xFFFF00);
  }
}
// Need to switch between random colors around the base.
for (z=1;z=20000;z++)
{
    Rb.setPixelZXY(1,0,0,colorChoice[random(3)]);
    Rb.setPixelZXY(1,0,1,colorChoice[random(3)]);
    Rb.setPixelZXY(1,0,2,colorChoice[random(3)]);
    Rb.setPixelZXY(1,0,3,colorChoice[random(3)]);    
    Rb.setPixelZXY(1,1,0,colorChoice[random(3)]);
    Rb.setPixelZXY(1,1,3,colorChoice[random(3)]);
    Rb.setPixelZXY(1,2,0,colorChoice[random(3)]);
    Rb.setPixelZXY(1,2,3,colorChoice[random(3)]);
    Rb.setPixelZXY(1,3,0,colorChoice[random(3)]);
    Rb.setPixelZXY(1,3,1,colorChoice[random(3)]);
    Rb.setPixelZXY(1,3,2,colorChoice[random(3)]);
    Rb.setPixelZXY(1,3,3,colorChoice[random(3)]);


 for(x=1 ;x>0;x--)
{
  for(y=2;y>0;y--)
  {
   Rb.setPixelZXY(2,x,y,colorChoice[random(3)]);
   Rb.setPixelZXY(3,x,y,colorChoice[random(3)]);
  }
}
delay(1000);
}

}

