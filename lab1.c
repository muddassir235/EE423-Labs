//Start of the program include Library
#include "REGX52.h"

void sdelay(int);
void turn_all_on();
void turn_all_off();
void change(char,int,int);


//Initialize Pins
sbit r1 =    P1^2;
sbit y1  =   P1^3;
sbit g1  =   P1^4;

sbit r2  =   P1^5;
sbit y2  =   P1^6;
sbit g2  =   P1^7;

sbit r3  =   P2^2;
sbit y3  =   P2^1;
sbit g3  =   P2^0;

sbit r4  =   P2^5;
sbit y4  =   P2^4;
sbit g4  =   P2^3;

int x;

int g_delay=5;
int y_delay=2;

void main()
{
	//initialize port
	P1=0;
	P2=0;
	
	//test pins

	turn_all_on();
	
	
	sdelay(1);
	
	turn_all_off();
	
	sdelay(1);
	

	while(1)
	{
		//Light 0 On
		
		change('y',0,y_delay);
		//sdelay(y_delay);
		
		change('g',0,g_delay);
		//sdelay(g_delay);
		
		change('y',0,y_delay);
		//sdelay(y_delay);

		//Light 1 On
		change('y',1,y_delay);
		//sdelay(y_delay);
		
		change('g',1,g_delay);
		//sdelay(g_delay);
		
		change('y',1,y_delay);
		//sdelay(y_delay);
		
		//Light 2 On
		change('y',2,y_delay);
		//sdelay(y_delay);
		
		change('g',2,g_delay);
		//sdelay(g_delay);
		
		change('y',2,y_delay);
		//sdelay(y_delay);
		
		//Light 3 On
		change('y',3,y_delay);
		//sdelay(y_delay);
		
		change('g',3,g_delay);
		//sdelay(g_delay);
		
		change('y',3,y_delay);
		//sdelay(y_delay);

		
	}
	
}

void sdelay(int i)
{
	i*=40;
	for(x=0;x<i;x++)
	{TMOD=0x10;
	TL1=0xFE;
	TH1=0xA5;
	TR1=1;
	while(TF1==0);
	TR1=0;
	TF1=0;}
}

void change(char color, int light_number,int seconds){
	switch(light_number){
		case 0:{
			if(color == 'r'){
				r1=1;r2=1;r3=1;r4=1;
				y1=0;y2=0;y3=0;y4=0;
				g1=0;g2=0;g3=0;g4=0;
			}else if(color == 'y'){
				r1=0;r2=1;r3=1;r4=1;
				y1=1;y2=0;y3=0;y4=0;
				g1=0;g2=0;g3=0;g4=0;
			}else if(color == 'g'){
				r1=0;r2=1;r3=1;r4=1;
				y1=0;y2=0;y3=0;y4=0;
				g1=1;g2=0;g3=0;g4=0;
			}
		}break;
		case 1:{
			if(color == 'r'){
				r1=1;r2=1;r3=1;r4=1;
				y1=0;y2=0;y3=0;y4=0;
				g1=0;g2=0;g3=0;g4=0;
			}else if(color == 'y'){
				r1=1;r2=0;r3=1;r4=1;
				y1=0;y2=1;y3=0;y4=0;
				g1=0;g2=0;g3=0;g4=0;
			}else if(color == 'g'){
				r1=1;r2=0;r3=1;r4=1;
				y1=0;y2=0;y3=0;y4=0;
				g1=0;g2=1;g3=0;g4=0;
			}
		}break;
		case 2:{
			if(color == 'r'){
				r1=1;r2=1;r3=1;r4=1;
				y1=0;y2=0;y3=0;y4=0;
				g1=0;g2=0;g3=0;g4=0;
			}else if(color == 'y'){
				r1=1;r2=1;r3=0;r4=1;
				y1=0;y2=0;y3=1;y4=0;
				g1=0;g2=0;g3=0;g4=0;
			}else if(color == 'g'){
				r1=1;r2=1;r3=0;r4=1;
				y1=0;y2=0;y3=0;y4=0;
				g1=0;g2=0;g3=1;g4=0;
			}
		}break;
		case 3:{
			if(color == 'r'){
				r1=1;r2=1;r3=1;r4=1;
				y1=0;y2=0;y3=0;y4=0;
				g1=0;g2=0;g3=0;g4=0;
			}else if(color == 'y'){
				r1=1;r2=1;r3=1;r4=0;
				y1=0;y2=0;y3=0;y4=1;
				g1=0;g2=0;g3=0;g4=0;
			}else if(color == 'g'){
				r1=1;r2=1;r3=1;r4=0;
				y1=0;y2=0;y3=0;y4=0;
				g1=0;g2=0;g3=0;g4=1;
			}
		}break;
		default:{
			// do nothing
		}
	}
	sdelay(seconds);
}

void turn_all_on(){
	r1=1;r2=1;r3=1;r4=1;
	y1=1;y2=1;y3=1;y4=1;
	g1=1;g2=1;g3=1;g4=1;
}

void turn_all_off(){
	r1=0;r2=0;r3=0;r4=0;
	y1=0;y2=0;y3=0;y4=0;
	g1=0;g2=0;g3=0;g4=0;
}
