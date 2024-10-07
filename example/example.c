/*EXTI-Projekt mit einem Taster und einer LED*/

#ifdef MCAL
#include <mcalGPIO.h>
#include <mcalEXTI.h>
#endif

int main(void)
{
#ifdef MCAL 

   gpioSelectPort(GPIOA);

   RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; // SYSCFG: Clock aktivieren

   /**
    * Konfiguration von GPIOA PA0 und PA4
    */
   gpioSelectPinMode(GPIOA, PIN0, INPUT);
   gpioSelectPinMode(GPIOA, PIN4, OUTPUT);
   gpioSetOutputType(GPIOA, PIN4, PUSHPULL);
   gpioSelectPushPullMode(GPIOA, PIN4, NO_PULLUP_PULLDOWN);

   extiInit();
   extiConfigIrq(GPIOA, PIN0);
   extiEnableIrq(EXTI_PIN0);
   extiSetTriggerEdge(EXTI_PIN0, FALLING_EDGE);

#endif 
}
