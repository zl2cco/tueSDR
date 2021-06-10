#pragma once

enum led_nr {
	LED_GREEN = 0,
	LED_RED,
	LED_BLUE,
	LED_END
};

void led_setup (void);
void led_toggle (enum led_nr led);
void led_on (enum led_nr led);
void led_off (enum led_nr led);

void led_test (void);
