MCAL Library for ARM/STM32 Microcontrollers
============================================

Overview
---------

This project provides a Microcontroller Abstraction Layer (MCAL) for programming ARM/STM32 microcontrollers. The MCAL layer is designed to simplify the interaction with the hardware by abstracting low-level functionalities, making embedded development easier and more modular. It contains drivers and utilities for handling GPIO, EXTI, and other peripherals.

Features
--------

- GPIO Management: Functions to configure and control General Purpose Input/Output (GPIO) pins.
- External Interrupt (EXTI) Handling: Configuration and management of external interrupts.
- Timer Management: Functions for configuring and managing hardware timers.
- SysTick Management: Setup and configuration for the SysTick timer, commonly used for timekeeping and delays.

Requirements
------------

- Development Board: STM32Fxxx series or any compatible ARM Cortex-M microcontroller.
- Toolchain: ARM GCC Toolchain or similar toolchain for building ARM/STM32 projects (e.g., STM32CubeIDE).
- STM32 HAL Library: This library assumes some familiarity with the HAL (Hardware Abstraction Layer) but builds   on a lower-level MCAL approach for more control.
