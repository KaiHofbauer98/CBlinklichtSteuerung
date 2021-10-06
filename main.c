/*
 * GccApplication1.c
 *
 * Created: 22.09.2021 12:12:45
 * Author : kai.hofbauer
 */ 

#include <avr/io.h> // include = Einbinden von io = input/output-Bib-> wird für Bezeichungen benötigt, damit wir lesbare befehle eingeben können
#include <avr/delay.h>

int main(void) //Hauptfunktion: hier springt das Programm rein
{
    //Port B als Ausgabe
    DDRB = 0xff;
	PORTB = 0x00;
	
	//Port A als eingabe
	DDRA = 0x00;
	PORTA = 0xFF;
	
	
	
	
	
	
    int counterArray = 0;
	int counterBlinkGeschw = 0;
	
	int blinkWiederholungen = 1;
	int angesprocheneLEDs = 4; //wert zwischen 1 und 8!!!
	int blinkDauerMS = 50;
	int multiplicator = 1;
	int ms = 0;
	
	unsigned char arr[8] = {0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000}; //Array_fuer_die_LEDs

/*int ms(void){
		int mswert = blinkDauerMS;
		if(PINA = 0b01111111){
			mswert++;
		}else{
			if (PINA = 0b11111110)
			{
				mswert = mswert - 1;
			}else{
				return mswert;
			}
		}
		return mswert;
	}*/

void my_delay_ms(){
	ms = (blinkDauerMS + multiplicator);
if(ms < 15){blinkDauerMS = 15; ms = 15; multiplicator = 1;}else{
	while (0 < ms)
	{
		_delay_ms(1);
		ms = ms - 1;
	}
	}
}

void taster(){
_delay_ms(1);
	if(PINA == 0b01111111){
		multiplicator = multiplicator + 10;
	}
	if(PINA == 0b11111110){
		multiplicator = multiplicator - 10;
	}


if(PINA == 0b10111111){
		blinkWiederholungen++;
	}

	if(PINA == 0b11111101){
		if(blinkWiederholungen <= 1){
		blinkWiederholungen = 1;
	}else{
	blinkWiederholungen = blinkWiederholungen - 1;
	}
}


	if(PINA == 0b11011111){
		if(angesprocheneLEDs >= 8){
			angesprocheneLEDs = 8;
		}else{
			angesprocheneLEDs ++;
		}
	}
	if(PINA == 0b11111011){
		if(angesprocheneLEDs <= 2){
			angesprocheneLEDs = 2;
}else{
	angesprocheneLEDs = angesprocheneLEDs -1;
}
	}

if(PINA == 0b11100111){
	PORTB = 0xff;
}else{

	if(PINA == 0b11101111){
		    DDRB = 0xff;
			PORTB = 0x00;
	}
	if(PINA == 0b11110111){
		    while(1){
PORTB = 0x00;
			//_delay_ms(25);
			if(PINA == 0b11101111){break;}
}
	}
}



_delay_ms(1);
}



	while(1) {
		if (counterArray < angesprocheneLEDs){
			while(counterBlinkGeschw < blinkWiederholungen){
				PORTB = 0x00; //Ausg. kein Blinklicht an Port B
				my_delay_ms();
				PORTB = arr[counterArray]; //Ausg. aktueller Zaehlerst. an Port B
				taster();
				my_delay_ms();
				taster();
				counterBlinkGeschw++;
			}
			counterBlinkGeschw = 0;
			counterArray++;
		}else{
			counterArray = counterArray - 2;
			while(counterArray > 0){
				while(counterBlinkGeschw < blinkWiederholungen){
					PORTB = 0x00; //Ausg. kein Blinklicht an Port B
					my_delay_ms();
					PORTB = arr[counterArray]; //Ausg. aktueller Zaehlerst. an Port B
					taster();
					my_delay_ms();
					taster();
					counterBlinkGeschw++;
				}
				counterBlinkGeschw = 0;
				counterArray = counterArray - 1;
			}
			counterArray = 0;
		}
		}
	
}

