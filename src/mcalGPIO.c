#include <stdint.h>
#include <stdbool.h>

#include <mcalGPIO.h>

/**
 * Function to verify the integrity of the **port** parameter.
 *
 * @param *port : Pointer to the GPIO port
 */
bool gpioVerifyPort(GPIO_TypeDef *port)
{
    if ((GPIOA == port) || (GPIOB == port) || (GPIOC == port) ||
        (GPIOD == port) || (GPIOE == port) || (GPIOF == port) ||
        (GPIOG == port) || (GPIOH == port))
    {
        return true;
    }
    return false;
}

/**
 * Function to verify the integrity of the **pin** parameter.
 *
 * @param pin : The pin number of any of the GPIO ports
 */
bool gpioVerifyPin(PIN_NUM_t pin)
{
    if ((PIN0  == pin) || (PIN1  == pin) || (PIN2  == pin) || (PIN3  == pin) ||
        (PIN4  == pin) || (PIN5  == pin) || (PIN6  == pin) || (PIN7  == pin) ||
        (PIN8  == pin) || (PIN9  == pin) || (PIN10 == pin) || (PIN11 == pin) ||
        (PIN12 == pin) || (PIN13 == pin) || (PIN14 == pin) || (PIN15 == pin))
    {
        return true;
    }
    return false;
}

/**
 * Function to verify the integrity of the **pinMode** parameter.
 *
 * @param pinMode : The operational mode in which the GPIO pin shall work.
 */
bool gpioVerifyPinMode(PIN_MODE_t pinMode)
{
    if ((INPUT == pinMode) || (OUTPUT == pinMode) || (ALTFUNC == pinMode) || (ANALOG == pinMode))
    {
        return true;
    }

    return false;
}

/**
 * Function to verify the integrity of the **outType** parameter.
 *
 * @param outType : Verifies whether the passed value is PUSHPULL or OPENDRAIN.
 */
bool gpioVerifyOutputType(OUTPUT_TYPE_t outType)
{
    if ((PUSHPULL == outType) || (OPENDRAIN == outType))
    {
        return true;
    }

    return false;
}

/**
 * Function to verify the integrity of the Pullup/Pulldown parameter.
 *
 * @param mode : Verifies the Pullup/Pulldown mode
 */
bool gpioVerifyPushPullMode(PUPD_MODE_t mode)
{
    if ((NO_PULLUP_PULLDOWN == mode) || (PULLUP == mode) || (PULLDOWN == mode))
    {
        return true;
    }
    return false;
}

/**
 * Function to verify the speed parameter.
 *
 * @param speed : Verification of the speed parameter
 */
bool gpioVerifyOutputSpeed(GPIO_SPEED_t speed)
{
    if ((LOW_SPEED == speed) || (MEDIUM_SPEED == speed) || (FAST_SPEED == speed) || (HIGH_SPEED == speed))
    {
        return true;
    }

    return false;
}


/**
 * @ingroup gpio1
 * This function is used to activate the bus clock of the port. It verifies the
 * validity of the given GPIO port. 
 *
 * @param
 * *port : Pointer to the GPIO port
 *
 * @return GPIO_RETURN_CODE_t
 *
 */
GPIO_RETURN_CODE_t gpioSelectPort(GPIO_TypeDef *port)
{
    if (gpioVerifyPort(port) != true)
    {
        return GPIO_INVALID_PORT;
    }

    if (GPIOA == port)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    }
    else if (GPIOB == port)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    }
    else if (GPIOC == port)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    }
    else if (GPIOD == port)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    }
    else if (GPIOE == port)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    }
    else if (GPIOF == port)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
    }
    else if (GPIOG == port)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
    }
    else if (GPIOH == port)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
    }
    return GPIO_OK;
}

/**
 * @ingroup gpio1
 * Deselecting a GPIO port when it is not longer used.
 *
 * @param
 * *port : Pointer to the GPIO port
 *
 * @return GPIO_RETURN_CODE_t
 *
 */
GPIO_RETURN_CODE_t gpioDeselectPort(GPIO_TypeDef *port)
{
    if (gpioVerifyPort(port) != true)
    {
        return GPIO_INVALID_PORT;
    }

    if (GPIOA == port)
    {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN_Msk;
    }
    else if (GPIOB == port)
    {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN_Msk;
    }
    else if (GPIOC == port)
    {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN_Msk;
    }
    else if (GPIOD == port)
    {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN_Msk;
    }
    else if (GPIOE == port)
    {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN_Msk;
    }
    else if (GPIOF == port)
    {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN_Msk;
    }
    else if (GPIOG == port)
    {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN_Msk;
    }
    else if (GPIOH == port)
    {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN_Msk;
    }
    return GPIO_OK;
}

/**
 * @ingroup gpio1
 * Initializes the operational mode of a GPIO pin. Returns GPIO_OK if all parameters are valid.
 *
 * @param  *port : Pointer to the GPIO port
 * @param   pin  : Number of the pin
 * @param   mode : Operational mode of the pin
 * @return GPIO_RETURN_CODE_t
 *
 */
GPIO_RETURN_CODE_t gpioSelectPinMode(GPIO_TypeDef *port, PIN_NUM_t pin, PIN_MODE_t mode)
{
    if (gpioVerifyPort(port) != true)
    {
        return GPIO_INVALID_PORT;
    }
    if (gpioVerifyPin(pin) != true)
    {
        return GPIO_INVALID_PIN;
    }
    if (gpioVerifyPinMode(mode) != true)
    {
        return GPIO_INVALID_PINMODE;
    }

    // Set pin to default (INPUT)
	port->MODER &= ~(0b11 << (pin * 2));

	// If mode is not INPUT --> Select other setting
	if (INPUT != mode)
	{
		port->MODER |= (mode << (pin * 2));
	}

	return GPIO_OK;
}

/**
 * @ingroup gpio1
 * Sets the GPIO pin to High level. Verifies the integrity of the port and pin.
 *
 * @param  *port : Pointer to the GPIO port
 * @param   pin  : Number of the GPIO pin
 * @return GPIO_RETURN_CODE_t
 *
 */
GPIO_RETURN_CODE_t gpioSetPin(GPIO_TypeDef *port, PIN_NUM_t pin)
{
    if (gpioVerifyPort(port) != true)
    {
        return GPIO_INVALID_PORT;
    }
    if (gpioVerifyPin(pin) != true)
    {
        return GPIO_INVALID_PIN;
    }

	port->BSRR = 1 << pin;

	return GPIO_OK;
}

/**
 * @ingroup gpio1
 * Resets the GPIO pin to low level. Verifies the integrity of the port and pin.
 *
 * @param  *port : Pointer to the GPIO port
 * @param   pin  : Number of the GPIO pin
 * @return GPIO_RETURN_CODE_t
 *
 */
GPIO_RETURN_CODE_t gpioResetPin(GPIO_TypeDef *port, PIN_NUM_t pin)
{
    if (gpioVerifyPort(port) != true)
    {
        return GPIO_INVALID_PORT;
    }
    if (gpioVerifyPin(pin) != true)
    {
        return GPIO_INVALID_PIN;
    }

	port->BSRR = (1 << (pin + 16));

	return GPIO_OK;
}

/**
 * @ingroup gpio1
 * Toggles the state of the GPIO pin. Verifies the integrity of the port and pin.
 *
 * @param  *port : Pointer to the GPIO port
 * @param   pin  : Number of the GPIO pin
 * @return GPIO_RETURN_CODE_t
 *
 */
GPIO_RETURN_CODE_t gpioTogglePin(GPIO_TypeDef *port, PIN_NUM_t pin)
{
    if (gpioVerifyPin(pin) != true)
    {
        return GPIO_INVALID_PIN;
    }
    if (gpioGetPinState(port, pin))
    {
       gpioResetPin(port, pin);
    }
    else
    {
        gpioSetPin(port, pin);
    }

    return GPIO_OK;
}

/**
 * @ingroup gpio1
 * Sets bits 0 to 15 of the GPIO. 
 *
 * @param  *port : Pointer to the GPIO port
 * @param   word : Sets bits 0 to 15 according to the value of byte
 * @return GPIO_RETURN_CODE_t
 *
 */
GPIO_RETURN_CODE_t gpioSetWord(GPIO_TypeDef *port, uint16_t word)
{
    port->ODR = word;
    return GPIO_OK;
}

/**
 * @ingroup gpio1
 * Sets the output type of the GPIO pin either as PUSHPULL or Open Drain. Verifies the
 * port, pin and the output type.
 *
 * @param  *port    : Pointer to the GPIO port
 * @param   pin     : Number of the GPIO pin
 * @param   outType : Selects between Push/Pull or Open Drain
 * @return GPIO_RETURN_CODE_t
 *
 */
GPIO_RETURN_CODE_t gpioSetOutputType(GPIO_TypeDef *port, PIN_NUM_t pin, OUTPUT_TYPE_t outType)
{
    if (gpioVerifyPort(port) != true)
    {
        return GPIO_INVALID_PORT;
    }
    if (gpioVerifyPin(pin) != true)
    {
        return GPIO_INVALID_PIN;
    }
    if (gpioVerifyOutputType(outType) != true)
    {
        return GPIO_INVALID_OUTPUT_TYPE;
    }

    port->OTYPER &= ~(1 << pin);   
    if (OPENDRAIN == outType)
    {
        port->OTYPER |= (1 << pin);
	}

	return GPIO_OK;
}

/**
 * @ingroup gpio1
 * This function selects the push/pull resistor type. Valid values are
 * *NO_PULLUP_PULLDOWN*, *PULLUP*, and *PULLDOWN*.
 *
 * @param  *port : Pointer to the GPIO port
 * @param   pin  : Number of the GPIO pin
 * @param   pupd : Different pull-up/pull-down settings
 * @return GPIO_RETURN_CODE_t
 *
 */
GPIO_RETURN_CODE_t gpioSelectPushPullMode(GPIO_TypeDef *port, PIN_NUM_t pin, PUPD_MODE_t pupd)
{
    if (gpioVerifyPort(port) != true)
    {
        return GPIO_INVALID_PORT;
    }
    if (gpioVerifyPin(pin) != true)
    {
        return GPIO_INVALID_PIN;
    }
    if (gpioVerifyPushPullMode(pupd) != true)
    {
        return GPIO_INVALID_PUSH_PULL_MODE;
    }

    port->PUPDR &= ~(0x03 << (pin * 2));        // Disable PU/PD

    if (port->OTYPER == PUSHPULL)
	{
		if (PULLUP == pupd)
		{
			port->PUPDR |= (PULLUP << (pin *2));
		}
		else if (PULLDOWN == pupd)
		{
			port->PUPDR |= (PULLDOWN << (pin *2));
		}
	}

    return GPIO_OK;
}

/**
 * @ingroup gpio1
 * Sets the speed of a GPIO output pin. 
 *
 * @param  *port  : Pointer to the GPIO port
 * @param   pin   : Number of the GPIO pin
 * @param   speed : Speed setting
 * @return nothing
 *
 */
GPIO_RETURN_CODE_t gpioSetOutputSpeed(GPIO_TypeDef *port, PIN_NUM_t pin, GPIO_SPEED_t speed)
{
    if (gpioVerifyPort(port) != true)
    {
        return GPIO_INVALID_PORT;
    }
    if (gpioVerifyPin(pin) != true)
    {
        return GPIO_INVALID_PIN;
    }
    if (gpioVerifyOutputSpeed(speed) != true)
    {
        return GPIO_INVALID_OUTPUT_SPEED;
    }

    port->OSPEEDR &= (LOW_SPEED << (pin * 2));	// Default: Low speed

	if (MEDIUM_SPEED == speed)
	{
		port->OSPEEDR |= (MEDIUM_SPEED << (pin * 2));
	}
	else if (FAST_SPEED == speed)
	{
		port->OSPEEDR |= (FAST_SPEED << (pin * 2));
	}
	else if (HIGH_SPEED == speed)
	{
		port->OSPEEDR |= (HIGH_SPEED << (pin * 2));
	}

	return GPIO_OK;
}

/**
 * @ingroup gpio1
 * This function is used to obtain the current state of the given pin. 
 *
 * @param  *port     : Pointer to the GPIO port
 * @param   pin      : Number of the GPIO pin
 * @return bool
 *
 */
bool gpioGetPinState(GPIO_TypeDef *port, PIN_NUM_t pin)
{
    return (port->IDR & (1 << pin)) == (1<<pin);
}

/**
 * @ingroup gpio1
 * This function is used to obtain the current state of the given port.
 *
 * @param  *port    : Pointer to the GPIO port
 * @return uint16_t
 *
 */
uint16_t gpioGetPortVal(GPIO_TypeDef *port)
{
	return (port->IDR);
}

