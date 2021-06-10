#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "led.h"

enum rcc_periph_clken clken[3] = {};
uint32_t gpio_port[3]          = {GPIOB, GPIOB, GPIOC}; 
uint16_t gpios[3]              = {GPIO1, GPIO2, GPIO13};


void led_setup (void)
{
	/* Enable GPIOB and GPIOC clock. */
	/* Manually: */
	// RCC_AHB1ENR |= RCC_AHB1ENR_IOPDEN;
	/* Using API functions: */
	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_GPIOC);

	/* Set GPIO1 and GPIO2 (in GPIO port B), GPIO13 (in GPIO port C) to 'output push-pull'. */
	/* Manually: */
	// GPIOD_CRH = (GPIO_CNF_OUTPUT_PUSHPULL << (((8 - 8) * 4) + 2));
	// GPIOD_CRH |= (GPIO_MODE_OUTPUT_2_MHZ << ((8 - 8) * 4));
	/* Using API functions: */
	gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO1 | GPIO2);
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);

}

void led_toggle (enum led_nr led)
{
	if (led < LED_END) {
		gpio_toggle(gpio_port[led], gpios[led]);
	}
}

void led_on (enum led_nr led)
{
	if (led < LED_END) {
		gpio_set(gpio_port[led], gpios[led]);
	}
}

void led_off (enum led_nr led)
{
	if (led < LED_END) {
		gpio_clear(gpio_port[led], gpios[led]);
	}
}



void led_test (void)
{
	int i;

	led_toggle(LED_GREEN);
	for (i = 0; i < 1000000; i++) {	/* Wait a bit. */
		__asm__("nop");
	}

	led_on(LED_RED);
	for (i = 0; i < 1000000; i++) {	/* Wait a bit. */
		__asm__("nop");
	}

	led_toggle(LED_BLUE);
	for (i = 0; i < 1000000; i++) {	/* Wait a bit. */
		__asm__("nop");
	}
	led_off(LED_RED);
}