#ifndef MCALTIMER_H_
#define MCALTIMER_H_

#include <stm32f4xx.h>
#include <stdint.h>
#include <stdbool.h>

#include <mcalTimer/typedefs.h>

#ifdef __cplusplus
extern "C" {
#endif


#define TIMER_MAX_PRESCALER         (65536)


/**
 * Function prototypes.
 */

extern void                 timerSelectTimer(TIM_TypeDef *tim);
extern void                 timerDeselectTimer(TIM_TypeDef *tim);
extern TIMER_RETURN_CODE_t  timerEnableAutoReloadPreload(TIM_TypeDef *tim);
extern TIMER_RETURN_CODE_t  timerDisableAutoReloadPreload(TIM_TypeDef *tim);
extern void                 timerSetPrescaler(TIM_TypeDef *tim, uint32_t psc);
extern uint32_t             timerGetPrescaler(TIM_TypeDef *tim);
extern void                 timerSetAutoReloadValue(TIM_TypeDef *tim, uint32_t reload);
extern uint32_t             timerGetAutoReloadValue(TIM_TypeDef *tim);
extern void                 timerStartTimer(TIM_TypeDef *tim);
extern void                 timerStopTimer(TIM_TypeDef *tim);
extern void                 timerSetCounter(TIM_TypeDef *tim, uint32_t cnt);
extern uint32_t             timerGetCounter(TIM_TypeDef *tim);
extern void                 timerResetCounter(TIM_TypeDef *tim);



#ifdef __cplusplus
}
#endif


#endif /* MCALTIMER_H_ */
