

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>

#include "delay.h"

/* monotonically increasing number of milliseconds from reset
 * overflows every 49 days if you're wondering
 */
volatile uint32_t system_millis;

/* Called when systick fires */
void sys_tick_handler(void)
{
	system_millis++;
}



/* sleep for delay milliseconds */
void delay_msleep(uint32_t delay)
{
	uint32_t wake = system_millis + delay;
	while (wake > system_millis);
}



/* return system time in milliseconds */
uint32_t delay_now(void)
{
	return system_millis;
}



/* Set up a timer to create 1mS ticks. */
void delay_setup(void)
{
	/* clock rate / 1000 to get 1mS interrupt rate */
	systick_set_reload(168000);
	systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);
	systick_counter_enable();
	/* this done last */
	systick_interrupt_enable();
}

