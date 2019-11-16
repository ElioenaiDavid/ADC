/*
 * el adc 8 mide en el puerto B0
 * el adce 9 mide en el puerto B1
 * el adc 14 mide en el puerto C0
 * el adce 15 mide en el puerto C1
 * el adce 23 mide en el puerto E30
 *
 *
*/
#include <MKL25Z4.h>
#include "adc.h"
int main (void)
{
short int result;
ADC0_init();
while (1) {
result=mesure(15);
}
}
