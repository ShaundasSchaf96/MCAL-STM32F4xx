#ifndef MCALGPIO_H_
#define MCALGPIO_H_

#include <stm32f4xx.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup gpio2
 * @{
 */

typedef enum
{
    GPIO_OK                     =  0,
    GPIO_INVALID_PORT           = -1,
    GPIO_INVALID_PIN            = -2,
    GPIO_INVALID_ALTFUNC        = -3,
    GPIO_INVALID_OUTPUT_TYPE    = -4,
    GPIO_INVALID_RESISTOR_TYPE  = -5,
    GPIO_INVALID_PINMODE        = -6,
    GPIO_INVALID_PUSH_PULL_MODE = -7,
    GPIO_INVALID_OUTPUT_SPEED   = -8
} GPIO_RETURN_CODE_t;

/**
 * @brief Enumeration of GPIO pins
 */
typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
} PIN_NUM_t;

/**
 * @brief Enumeration of GPIO pin modes
 */
typedef enum
{
	INPUT = 0,
	OUTPUT,
	ALTFUNC,
	ANALOG
} PIN_MODE_t;

/**
 * @brief Enumeration of output types
 */
typedef enum
{
	PUSHPULL = 0,
	OPENDRAIN
} OUTPUT_TYPE_t;

/**
 * @brief Enumeration of pull-up or pull-down configurations
 */
typedef enum
{
	NO_PULLUP_PULLDOWN = 0,
	PULLUP,
	PULLDOWN,
} PUPD_MODE_t;

/**
 * @brief Enumerations of output speeds
 */
typedef enum
{
	LOW_SPEED = 0,
	MEDIUM_SPEED,
	FAST_SPEED,
	HIGH_SPEED
} GPIO_SPEED_t;

/**
 * @brief Function prototypes 
 */


extern GPIO_RETURN_CODE_t gpioSelectPinMode(GPIO_TypeDef *port, PIN_NUM_t pin, PIN_MODE_t mode);
extern GPIO_RETURN_CODE_t gpioSetPin(GPIO_TypeDef *port, PIN_NUM_t pin);
extern GPIO_RETURN_CODE_t gpioResetPin(GPIO_TypeDef *port, PIN_NUM_t pin);
extern GPIO_RETURN_CODE_t gpioTogglePin(GPIO_TypeDef *port, PIN_NUM_t pin);
extern GPIO_RETURN_CODE_t gpioSelectPort(GPIO_TypeDef *port);
extern GPIO_RETURN_CODE_t gpioDeselectPort(GPIO_TypeDef *port);
extern GPIO_RETURN_CODE_t gpioSelectPushPullMode(GPIO_TypeDef *port, PIN_NUM_t pin, PUPD_MODE_t pupd);
extern GPIO_RETURN_CODE_t gpioSetOutputType(GPIO_TypeDef *port, PIN_NUM_t pin, OUTPUT_TYPE_t outType);
extern GPIO_RETURN_CODE_t gpioSetOutputSpeed(GPIO_TypeDef *port, PIN_NUM_t pin, GPIO_SPEED_t speed);

extern GPIO_RETURN_CODE_t gpioSetWord(GPIO_TypeDef *port, uint16_t word);

extern bool               gpioGetPinState(GPIO_TypeDef *port, PIN_NUM_t pin);
extern uint16_t           gpioGetPortVal(GPIO_TypeDef *port);


extern bool gpioVerifyPort(GPIO_TypeDef *port);
extern bool gpioVerifyPin(PIN_NUM_t pin);
extern bool gpioVerifyPinMode(PIN_MODE_t pinMode);
extern bool gpioVerifyOutputType(OUTPUT_TYPE_t outType);
extern bool gpioVerifyPushPullMode(PUPD_MODE_t mode);
extern bool gpioVerifyOutputSpeed(GPIO_SPEED_t speed);

#ifdef __cplusplus
}
#endif


#endif /* MCALGPIO_H_ */
