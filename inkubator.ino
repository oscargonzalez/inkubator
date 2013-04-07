/*
  Inkubator v1.0
  Oscar Gonzalez - March 2013
  www.bricogeek.com
*/

#include <SoftwareSerial.h>
#include <Picaso_Const4D.h>
#include <Picaso_Serial_4DLib.h>

#define LCD_RESET  12
#define LED_PIN    13
SoftwareSerial mySerial(2,3) ; // pin 2 = TX of display, pin3 = RX
Picaso_Serial_4DLib Display(&mySerial);

void LCD_reset()
{
   digitalWrite(LCD_RESET, HIGH); 
   delay(200);
   digitalWrite(LCD_RESET, LOW); 
   delay(200);
}

void setup()
{
  
  LCD_reset();
  
  delay(1000);
  
  mySerial.begin(9600);
  
  Display.TimeLimit4D   = 2000 ; // 2 second timeout on all commands
  Display.Callback4D = NULL;

  Display.gfx_Cls() ;  
  /*
  Display.txt_Attributes(BOLD) ;
  Display.txt_Xgap(3) ;
  Display.txt_Ygap(3) ;
  */
  Display.txt_BGcolour(BLACK) ;
  Display.txt_FGcolour(WHITE) ;

  // Inkubato LCD
  Display.txt_FontID(FONT1) ;
  Display.txt_MoveCursor(0, 0) ;
  Display.txt_Height(2);
  Display.txt_Width(2);
  Display.putstr("INKUBATOR") ;
  
  // Date and time
  Display.txt_FontID(FONT3) ;
  Display.txt_MoveCursor(0, 27) ;
  Display.txt_Height(1);
  Display.txt_Width(1);
  Display.putstr("14:23") ;  
  
  Display.txt_MoveCursor(1, 49) ;
  Display.txt_Height(1);
  Display.txt_Width(1);
  Display.putstr("30/03/2013") ;    
  
  Display.gfx_Line(0, 25, 480, 25, YELLOW);
  
  // -----------

  // Temperatura
  Display.txt_FGcolour(YELLOW) ;  
  Display.txt_FontID(FONT3) ;
  Display.gfx_MoveTo(50, 60);
  Display.txt_Height(1);
  Display.txt_Width(1);
  Display.putstr("Temperatura") ;      
    
  Display.txt_FGcolour(YELLOW) ;  
  Display.txt_FontID(FONT1) ;
  Display.gfx_MoveTo(170, 80) ;
  Display.txt_Height(3);
  Display.txt_Width(3);
  Display.putstr("Cº") ;        
  
  // Humedad
  Display.txt_FGcolour(YELLOW) ;  
  Display.txt_FontID(FONT3) ;
  Display.gfx_MoveTo(290, 60);
  Display.txt_Height(1);
  Display.txt_Width(1);
  Display.putstr("Humedad") ;      
  
  
  Display.txt_FGcolour(YELLOW) ;  
  Display.txt_FontID(FONT1) ;
  Display.gfx_MoveTo(410, 80) ;
  Display.txt_Height(3);
  Display.txt_Width(3);
  Display.putstr("%") ;  

  // ---------------------
  Display.gfx_Line(0, 160, 480, 160, YELLOW);  
  
  // Sinus test
  
  for (int i=0 ; i<480 ; i++)
  {
     // 480x272 
     Display.gfx_PutPixel(i, 271, BLUE);
  }

}

void loop()
{
    int i = 0;
    char buf[20];
    
    i = random(3, 50);    
    sprintf(buf, "%02d", i);
  
  Display.txt_FGcolour(YELLOW) ;  
  Display.txt_FontID(FONT1) ;
  Display.gfx_MoveTo(40, 80);
  Display.txt_Height(8);
  Display.txt_Width(8);
  Display.putstr(buf) ;   
  
  // Decimales
  Display.txt_FGcolour(YELLOW) ;  
  Display.txt_FontID(FONT1) ;
  Display.gfx_MoveTo(150, 122);
  Display.txt_Height(2);
  Display.txt_Width(2);
  Display.putstr(".6") ;     
  
    i = random(3, 50);    
    sprintf(buf, "%02d", i);  

  Display.txt_FGcolour(YELLOW) ;  
  Display.txt_FontID(FONT1) ;
  Display.gfx_MoveTo(280, 80);
  Display.txt_Height(8);
  Display.txt_Width(8);
  Display.putstr(buf);        
  
  delay(1000);
}
