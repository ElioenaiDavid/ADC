/*
 * adc.c
 *
 *  Created on: 14 nov. 2019
 *      Author: David
 */
#include <MKL25Z4.h>
#include "adc.h"


void ADC0_init(void)
{
SIM->SCGC5 |= 0x400; /* clock to PORTE */
PORTB->PCR[0] = 0; /* PTE20 analog input */
//SIM->SCGC5 |= 0x400; /* clock to PORTE */
PORTB->PCR[1] = 0; /* PTE20 analog input */
SIM->SCGC5 |= 0x2000; /* clock to PORTE */
PORTE->PCR[29] = 0; /* PTE20 analog input */
//SIM->SCGC5 |= 0x400; /* clock to PORTE */
PORTE->PCR[30] = 0; /* PTE20 analog input */
SIM->SCGC5 |= 0x800; /* clock to PORTE */
PORTC->PCR[0] = 0; /* PTE20 analog input */
PORTC->PCR[1] = 0; /* PTE20 analog input */
SIM->SCGC6 |= 0x8000000; /* clock to ADC0 */

ADC0->SC2 &= ~0x40; /* software trigger */
/* clock div by 4, long sample time, single ended 12 bit, bus clock */
ADC0->CFG1 = 0x40 | 0x10 | 0x04 | 0x00;
}
int mesure(int p){
	ADC0->SC1[0] = p; /* start conversion on channel 0 */
	while(!(ADC0->SC1[0] & 0x80)) { } /* wait for conversion complete */
	return ADC0->R[0];






}
