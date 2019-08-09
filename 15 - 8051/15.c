#include< reg52.h>

sbit rs=P3^5;  //Lcd controlling pins
sbit rw=P3^6;
sbit en=P3^7;
sbit Switch1=P1^0;
sbit Switch2=P1^1;
sbit Switch3=P1^2;

void delay()
{
unsigned int i,j;
for(i=0;i<1000;i++)
for(j=0;j<5;j++);
}

void command(unsigned int comand) //Sending initialing commands to lcd
{
P2=comand; rw=0; rs=0; en=0;
delay();
en=1;
delay();
en=0;
}

void lcddata(char value) //Sending data to be displayed on lcd screen
{
P2=value; rw=0; rs=1; en=0;
delay();
en=1;
delay();
en=0;
}

void lcd() //Initialing lcd
{
delay(); command(0x30); delay(); command(0x30); delay(); command(0x30);
delay(); command(0x38); delay(); command(0x01); delay(); command(0x0F);
delay(); command(0x0C); delay(); 
command(0x80); //Lcd rirst row selected for data printing
delay();
}

void main()
{
	while(1)
	{
		if (Switch1==0)
		{
lcd(); //First initialize 16x2 lcd, 5x7 matrix display, cursor off

lcddata('S'); delay(); lcddata('W'); delay(); lcddata('I'); delay(); lcddata('T');
delay(); lcddata('C'); delay(); lcddata('H'); delay(); lcddata(' ');
delay(); lcddata('1'); delay(); lcddata(' '); delay(); lcddata('P');
delay(); lcddata('r'); delay(); lcddata('e'); delay(); lcddata('s');
delay(); lcddata('s'); delay(); lcddata('e');delay(); lcddata('d');delay();
	}
				if (Switch2==0)
		{
lcd(); //First initialize 16x2 lcd, 5x7 matrix display, cursor off

lcddata('S'); delay(); lcddata('W'); delay(); lcddata('I'); delay(); lcddata('T');
delay(); lcddata('C'); delay(); lcddata('H'); delay(); lcddata(' ');
delay(); lcddata('2'); delay(); lcddata(' '); delay(); lcddata('P');
delay(); lcddata('r'); delay(); lcddata('e'); delay(); lcddata('s');
delay(); lcddata('s'); delay(); lcddata('e');delay(); lcddata('d');delay();
	}
				if (Switch3==0)
		{
lcd(); //First initialize 16x2 lcd, 5x7 matrix display, cursor off

lcddata('S'); delay(); lcddata('W'); delay(); lcddata('I'); delay(); lcddata('T');
delay(); lcddata('C'); delay(); lcddata('H'); delay(); lcddata(' ');
delay(); lcddata('3'); delay(); lcddata(' '); delay(); lcddata('P');
delay(); lcddata('r'); delay(); lcddata('e'); delay(); lcddata('s');
delay(); lcddata('s'); delay(); lcddata('e');delay(); lcddata('d');delay();
	}
		if (Switch1==1 && Switch2==1 && Switch3==1)
		{
lcd(); //First initialize 16x2 lcd, 5x7 matrix display, cursor off

lcddata(' '); delay(); lcddata(' '); delay(); lcddata(' '); delay(); lcddata('W');
delay(); lcddata('E'); delay(); lcddata('L'); delay(); lcddata('C');
delay(); lcddata('O'); delay(); lcddata('M'); delay(); lcddata('E');
delay(); lcddata(' '); delay(); lcddata(' '); delay(); lcddata(' ');
delay(); 
	}
}
}