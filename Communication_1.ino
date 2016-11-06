/*
 * Communication 1
 *
 * Will take input from the USB connection and will change the display depending on what is sent.
 *   0  clears display
 *   1  disply fusion
 *   2  rain
 */


#include <Rainbowduino.h>

// HSV to RGB array

int keyed  = 0;

unsigned char RED[64] = {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,238,221,204,188,171,154,137,119,102,85,
68,51,34,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,35,52};

unsigned char GREEN[64] = {0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,238,221,204,188,170,154,136,120,102,86,68,52,34,18,0,0,0,0};

unsigned char BLUE[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,34,52,68,86,102,120,136,154,170,188,
204,221,238,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};

unsigned char plasma[4][4][4];

unsigned char x,y,z,colorshift=0;
int red = 0x00;
int green =0x00;
int blue = 0xFF;
int ltblue = 0x68;
int lterblue = 0x30;
unsigned int oldx,oldy,olderx,oldery,oldestx,oldesty;
void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Rb.init(); //initialize Rainbowduino driver
  
  for(unsigned char x = 0; x < 4; x++)
  {
    for(unsigned char y = 0; y < 4; y++)
    {
      for(unsigned char z = 0; z < 4; z++)
       {
        int color = int(32.0 + (32.0 * sin(x / 1.0))+ 32.0 + (32.0 * sin(y / 1.0)) + 32.0 + (32.0 * sin(z / 1.0))) / 3;
        plasma[x][y][z] = color;      
       }   
    }
  }
}



void loop()                       // run over and over again
{
  if (Serial.available() > 0) {
  Serial.println("Hello world!");  // prints hello with ending line break
  keyed = Serial.read();
  Serial.print("You entered");
  Serial.println(keyed);
   }
if (keyed == 48){
  Rb.blankDisplay();
  keyed = 0;
   }
if (keyed == 49){
  fusion();
  }
if (keyed == 50){
  rain();
  }
}


void rain() {
     x = random(4);
     y = random(4);
    
 
     //Paint random colors
     Rb.setPixelZXY(3,x,y,red,green,blue); //uses R, G and B color bytes
     Rb.setPixelZXY(3,oldx,oldy,0x00,0x00,ltblue); //uses R, G and B color bytes
     delay(50);
     Rb.setPixelZXY(2,x,y,red,green,blue); //uses R, G and B color bytes
     Rb.setPixelZXY(2,oldx,oldy,0x00,0x00,ltblue); //uses R, G and B color bytes
     delay(50);
     Rb.setPixelZXY(1,x,y,red,green,blue); //uses R, G and B color bytes
     Rb.setPixelZXY(1,oldx,oldy,0x00,0x00,ltblue); //uses R, G and B color bytes

     delay(50);
     Rb.setPixelZXY(0,x,y,red,green,blue); //uses R, G and B color bytes
     Rb.setPixelZXY(0,oldx,oldy,0x00,0x00,ltblue); //uses R, G and B color bytes
     
     Rb.setPixelZXY(3,olderx,oldery,0x00,0x00,lterblue); //uses R, G and B color bytes
     Rb.setPixelZXY(2,olderx,oldery,0x00,0x00,lterblue); //uses R, G and B color bytes
     Rb.setPixelZXY(1,olderx,oldery,0x00,0x00,lterblue); //uses R, G and B color bytes
     Rb.setPixelZXY(0,olderx,oldery,0x00,0x00,lterblue); //uses R, G and B color bytes
     
     Rb.setPixelZXY(3,olderx,oldesty,0x00,0x00,0x00); //uses R, G and B color bytes
     Rb.setPixelZXY(2,olderx,oldesty,0x00,0x00,0x00); //uses R, G and B color bytes
     Rb.setPixelZXY(1,olderx,oldesty,0x00,0x00,0x00); //uses R, G and B color bytes
     Rb.setPixelZXY(0,olderx,oldesty,0x00,0x00,0x00); //uses R, G and B color bytes

     oldestx = olderx;
     oldesty = oldery;
     olderx = oldx;
     oldery = oldy;
     oldx = x;
     oldy = y;
     

  
}


void fusion() {
 for(x=0;x<4;x++)  
{
 for(y=0;y<4;y++)  
 {
  for(z=0;z<4;z++)
    {
     Rb.setPixelZXY(z,x,y,(RED[plasma[x][y][z] + colorshift]) % 256,(GREEN[plasma[x][y][z] + colorshift]) % 256,(BLUE[plasma[x][y][z] + colorshift]) % 256); //uses R, G and B color bytes
    }
 }
}
 delay(100);
 colorshift=  colorshift + 1;
  }

