#include <stm32f4xx.h>
#include <system_stm32f4xx.h>
#include <mcalSysTick.h>

/* Makros */
/* @ingroup sysTick1 */
#define DECREMENT_TIMER( timer )   \
    ( {                            \
        if ( timer > 0 )           \
            --timer;               \
    } )


/**
 * @ingroup sysTick2
 * Initialization of the SysTick timer
 *
 * @param  divisor : Setting the prescaler of the SysTick timer
 */
void systickInit (uint32_t divisor)
{
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / divisor);
}

/**
 * @ingroup sysTick2
 * Sets the tick interval of the software timer based on the initial timebase of the systick timer set with
 * systickInit().
 *
 * @param  *timer    : Pointer to the software timer
 * @param   ticktime : Tick time of the software timer in milliseconds
 */
void systickSetTicktime (uint32_t *timer, uint32_t tickTime)
{
    *timer = tickTime;
}

/**
 * @ingroup sysTick2
 * Returns *true* if the given timer is expired, otherwise *false*. Can
 * be used for multiple software timers which all depend on the Systick timer.
 *
 * @param   timer : This is a software timer.
 */
bool isSystickExpired(uint32_t timer)
{
	bool timerState = false;

	if (0 == timer)
	{
		timerState = true;
	}

	return timerState;
}

/**
 * @ingroup sysTick2
 * Interrupt service handler (ISR) for the SysTick timer
 *
 * @note
 * Provide a globally defined boolean variable with exactly the name "timerTrigger".
 */
void SysTick_Handler(void)
{
	timerTrigger = true;
}

/**
 * @ingroup sysTick2
 * Updates the given timer.
 *
 * @param *timer : A pointer to the variable representing this timer.
 */
void systickUpdateTimer(uint32_t *timer)
{
    DECREMENT_TIMER(*timer);
    timerTrigger = false;
}

