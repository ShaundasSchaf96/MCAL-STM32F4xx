#ifndef MCALTIMER_TYPEDEFS_H_
#define MCALTIMER_TYPEDEFS_H_

#ifdef __cplusplus
extern "C" {
#endif


typedef enum
{
    TIMER_OK                                  =   0,
    TIMER_INVALID_TIMER                       = -40,
    TIMER_INVALID_CHANNEL                     = -41,
    TIMER_INVALID_CHANNEL_TYPE                = -42,
    TIMER_INVALID_IRQ_TYPE                    = -43,
    TIMER_CAPCOMP_NOT_SUPPORTED               = -44,
    TIMER_REPETITION_NOT_SUPPORTED            = -45,
    TIMER_BDTR_NOT_SUPPORTED                  = -46,
    TIMER_INVALID_DMA_ASSIGNMENT              = -47,
    TIMER_ONE_SHOT_NOT_SUPPORTED              = -48,
    TIMER_INVALID_TIMER_CHANNEL_ASSIGNMENT    = -49,
    TIMER_INVALID_MASTER_SLAVE_MODE_TYPE      = -50,
    TIMER_INVALID_TRIGGER                     = -51,
    TIMER_INVALID_TRIGGER_ACTION              = -52,
    TIMER_INVALID_EXT_TRIGGER_FILTER          = -53,
    TIMER_INVALID_CLOCK_DIVIDER               = -54,
    TIMER_CLOCK_DIVISION_NOT_SUPPORTED        = -55,
    TIMER_INVALID_REGISTER_OFFSET             = -56,
    TIMER_INVALID_DMA_BURST_STARTING_REGISTER = -57,
    TIMER_INVALID_DMA_BURST_LENGTH            = -58
} TIMER_RETURN_CODE_t;


/**
 * @}
 */

#ifdef __cplusplus
}
#endif


#endif /* MCALTIMER_TYPEDEFS_H_ */
