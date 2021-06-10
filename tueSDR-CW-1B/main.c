/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


/*
 * TO DO:
 * ------
 *
 * [x] - Setup project template and programming environment. Do blinky test.
 * [x] - LED BSP
 * [x] - Delay library
 * [ ] - Button BSP
 * [ ] - UART library
 * [ ] - Rotary Encoder BSP
 * [ ] - SPI library
 * [ ] - ILI9841 LCD BSP
 * [ ] - I2C library
 * [ ] - I2S library
 * [ ] - CODEC BSP
 * [ ] - Si5351 BSP
 * [ ] - SDR receiver
 * [ ] - SDR CW transimitter
 *
 */




#include <libopencm3/stm32/rcc.h>

#include "delay.h"
#include "led.h"


/*--------------------------------------------------------------------*/
static void clock_setup(void)
{
	rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);
}





/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
int main(void)
{
	clock_setup();
	led_setup();
	delay_setup();

	/* Blink the LED (PC8) on the board. */
	while (1) {
		led_test();
		delay_msleep(1000);
	}

	return 0;
}
