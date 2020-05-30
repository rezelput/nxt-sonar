#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include "trik_studio_utils.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

U32 __interpretation_started_timestamp__ = 0;
static const float pi = 3.141592653589793;

static float i;

static float u;

static int x;



void ecrobot_device_initialize(void)
{
	srand(systick_get_ms());
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	ecrobot_init_nxtcolorsensor(NXT_PORT_S1, NXT_COLORSENSOR);
}

void ecrobot_device_terminate(void)
{
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	ecrobot_term_nxtcolorsensor(NXT_PORT_S1);
}

/* nxtOSEK hook to be invoked from an ISR in category 2 */
void user_1ms_isr_type2(void)
{ 
	ts_dispatch_timers();
	ecrobot_process_bg_nxtcolorsensor();
}

/* Main task */
TASK(TASK_MAIN)
{
	__interpretation_started_timestamp__ = systick_get_ms();
	
	label_f6d7c6414c8cb3a0b17931c61789:
	x = ecrobot_get_nxtcolorsensor_id(NXT_PORT_S1);
	u = 40 / pi;
	i = u + 10;
	label_d340358498f8b9043696ad8482d:
	nxt_motor_set_speed(NXT_PORT_B, (int)(40 + i), 0);
	nxt_motor_set_speed(NXT_PORT_C, (int)(40 + i), 0);
	
	label_b64d5236864744c089c33c3e9beaee2e:
	while (x < 20 && x > 10) {
		goto label_d5d31cfcc041eda266939974277593;
	}
	goto label_d68e259c32b4399b3fd32b13409b523;
	label_d5d31cfcc041eda266939974277593:
	nxt_motor_set_count(NXT_PORT_B, 0);
	nxt_motor_set_count(NXT_PORT_C, 0);
	
	goto label_d340358498f8b9043696ad8482d;
	label_d68e259c32b4399b3fd32b13409b523:
	ecrobot_sound_tone(1000, 100, 20);
	
	label_f1fe8be4316bbb5fd95f58ae00a:
	while (!(nxt_motor_get_count(NXT_PORT_C) > 300)) {
		wait(3);
	}
	label_f47fe62dc54c4aec954049d50c2bf408:
	nxt_motor_set_speed(NXT_PORT_B, -((int)(30 + i)), 0);
	nxt_motor_set_speed(NXT_PORT_C, -((int)(30 + i)), 0);
	
	label_abc514798cd54ab58e33609192d55fc4:
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	
	label_e875fa3c07fd4b3e86ad09374794ff23:
	nxt_motor_set_speed(NXT_PORT_C, -((int)(50 + i)), 1);
	
	label_c5d328dd4ca3bc093c342508e006:
	wait(1500);
	
	goto label_f6d7c6414c8cb3a0b17931c61789;
}
 