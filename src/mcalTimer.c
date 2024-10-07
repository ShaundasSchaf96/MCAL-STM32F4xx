#include <mcalTimer/mcalTimer.h>


/**
 * @ingroup tim1
 * This function selects a timer and turns the corresponding bus clock on.
 *
 * @param   *tim : Pointer to the timer
 *
 */
void timerSelectTimer(TIM_TypeDef *tim)
{
    if (TIM1 == tim)
    {
        RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    }
    else if (TIM2 == tim)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    }
    else if (TIM3 == tim)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    }
    else if (TIM4 == tim)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    }
    else if (TIM5 == tim)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
    }
    else if (TIM6 == tim)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
    }
    else if (TIM7 == tim)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
    }
    else if (TIM8 == tim)
    {
        RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
    }
    else if (TIM9 == tim)
    {
        RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
    }
    else if (TIM10 == tim)
    {
        RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
    }
    else if (TIM11 == tim)
    {
        RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
    }
    else if (TIM12 == tim)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM12EN;
    }
    else if (TIM13 == tim)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM13EN;
    }
    else if (TIM14 == tim)
    {
        RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
    }
    tim->CR1 = 0;  
    tim->CR2 = 0;  
}

/**
 * @ingroup tim1
 * @brief Deselects the desired timer
 *
 * This function deselects a timer and turns the corresponding bus clock off. It also clears the corresponding
 *
 * @param   *tim : Pointer to the timer
 *
 */
void timerDeselectTimer(TIM_TypeDef *tim)
{
    if (TIM1 == tim)
    {
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN_Msk;
    }
    else if (TIM2 == tim)
    {
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN_Msk;
    }
    else if (TIM3 == tim)
    {
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN_Msk;
    }
    else if (TIM4 == tim)
    {
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM4EN_Msk;
    }
    else if (TIM5 == tim)
    {
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM5EN_Msk;
    }
    else if (TIM6 == tim)
    {
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM6EN_Msk;
    }
    else if (TIM7 == tim)
    {
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM7EN_Msk;
    }
    else if (TIM8 == tim)
    {
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM8EN_Msk;
    }
    else if (TIM9 == tim)
    {
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM9EN_Msk;
    }
    else if (TIM10 == tim)
    {
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM10EN_Msk;
    }
    else if (TIM11 == tim)
    {
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM11EN_Msk;
    }
    else if (TIM12 == tim)
    {
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM12EN_Msk;
    }
    else if (TIM13 == tim)
    {
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM13EN_Msk;
    }
    else if (TIM14 == tim)
    {
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM14EN_Msk;
    }
    tim->CR1 = 0;  // Reset all bits of TIMx_CR1
    tim->CR2 = 0;  // Reset all bits of TIMx_CR2
}

/**
 * @ingroup tim1
 * Enables the timer preload mode.
 *
 * @param   *tim : Pointer to the timer
 * @return  TIMER_RETURN_CODE_t
 *
 */
TIMER_RETURN_CODE_t timerEnableAutoReloadPreload(TIM_TypeDef *tim)
{
    tim->CR1 |= TIM_CR1_ARPE;

    return TIMER_OK;
}

/**
 * @ingroup tim1
 * Disables the timer preload mode.
 *
 * @param   *tim : Pointer to the timer
 * @return  TIMER_RETURN_CODE_t
 *
 */
TIMER_RETURN_CODE_t timerDisableAutoReloadPreload(TIM_TypeDef *tim)
{
    tim->CR1 &= ~TIM_CR1_ARPE_Msk;

    return TIMER_OK;
}

/**
 * @ingroup tim1
 * Sets the prescaler register (PSC) of the timer.
 *
 * @param   *tim : Pointer to the timer tim
 * @param    psc : New prescaler value. Range: 1 ... 65536
 *
 */
void timerSetPrescaler(TIM_TypeDef *tim, uint32_t psc)
{
    psc -= 1;
    if (psc > TIMER_MAX_PRESCALER)
    {
        psc = TIMER_MAX_PRESCALER;
    }
    tim->PSC = psc;
}

/**
 * @ingroup tim1
 * Returns the currently set prescaler value.
 *
 * @param   *tim : Pointer to the timer
 * @return  psc : The content of the PSC register
 *
 */
uint32_t timerGetPrescaler(TIM_TypeDef *tim)
{
    return tim->PSC & 0xFFFFUL;
}

/**
 * @ingroup tim1
 * Sets the auto-reload register (ARR) of the timer.
 *
 * @param   *tim    : Pointer to the timer tim
 * @param    reload : New reload value for the timer
 *
 */
void timerSetAutoReloadValue(TIM_TypeDef *tim, uint32_t reload)
{
    reload -= 1;

    // 32-bit reload values are only valid for TIM2 and TIM5.
    if ((TIM2 == tim) || (TIM5 == tim))
    {
        tim->ARR = reload;
    }
    else
    {
        // For other timers: Check that reload does not exceed UIN16_MAX.
        if (reload > UINT16_MAX)
        {
            reload = 0;  // Set to 0 to avoid overflow
                        
        }
        tim->ARR = reload;
    }
}

/**
 * @ingroup tim1
 * Returns the current value of the Auto-reload Register (ARR).
 *
 * @param   *tim : Pointer to the timer
 * @return  arr : The content of the ARR
 *
 */
uint32_t timerGetAutoReloadValue(TIM_TypeDef *tim)
{
    if ((TIM2 == tim) || (TIM5 == tim))
    {
        return tim->ARR;
    }

    return ((tim->ARR) & 0xFFFFUL);
}

/**
 * @ingroup tim1
 * @brief   Starts the desired timer.
 * @details All timer settings must be finished before starting the timer.
 *
 * @param   *tim : Pointer to the timer tim
 *
 */
void timerStartTimer(TIM_TypeDef *tim)
{
    tim->CR1 |= TIM_CR1_CEN;
}

/**
 * @ingroup tim1
 * @brief   Stops the desired timer.
 *
 * @param   *tim : Pointer to the timer tim
 *
 */
void timerStopTimer(TIM_TypeDef *tim)
{
    tim->CR1 &= ~TIM_CR1_CEN_Msk;
}

/**
 * @ingroup tim1
 * Sets the starting value of the counter.
 *
 * @param  *tim : Pointer to the timer
 * @param   cnt : Start value of the counter
 *
 */
void timerSetCounter(TIM_TypeDef *tim, uint32_t cnt)
{
    if ((TIM2 == tim) || (TIM5 == tim))
    {
        tim->CNT = cnt;
    }
    else
    {
        tim->CNT = cnt & 0xFFFFUL;
    }
}

/**
 * @ingroup tim1
 * Returns the current value of the CNT register
 *
 * @param   *tim : Pointer to the timer
 * @return  cnt : The current value of the CNT register
 *
 */
uint32_t timerGetCounter(TIM_TypeDef *tim)
{
    if ((TIM2 == tim) || (TIM5 == tim))
    {
        return tim->CNT;
    }

    return ((tim->CNT) & 0xFFFFUL);
}

/**
 * @ingroup tim1
 * Resets the CNT register
 *
 * @param   *tim  : Pointer to the timer
 *
 */
void timerResetCounter(TIM_TypeDef *tim)
{
    tim->CNT = 0;
}


/* EOF */
