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

static int * * G;

static int * c;

static int * g;

static int i;

static int j;

static int s;

static float u;

static int x;

static float y;



/* OSEK declarations */
DeclareTask(TASK_dd1112adef54413696793a61d0cc24be);

void ecrobot_device_initialize(void)
{
	srand(systick_get_ms());
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);
	ecrobot_init_sonar_sensor(NXT_PORT_S1);
	/* Enables fetching data from sonar */
	ecrobot_get_sonar_sensor(NXT_PORT_S1);
}

void ecrobot_device_terminate(void)
{
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);
	ecrobot_term_sonar_sensor(NXT_PORT_S1);
}

/* nxtOSEK hook to be invoked from an ISR in category 2 */
void user_1ms_isr_type2(void)
{ 
	ts_dispatch_timers();

}

/* Tasks */
TASK(TASK_dd1112adef54413696793a61d0cc24be)
{
	while (true) {
		while (y > 0) {
			while (!(nxt_motor_get_count(B,C) > 1000)) {
				wait(3);
			}
			while (true) {
				while (!(ecrobot_get_sonar_sensor(NXT_PORT_S1) < 15)) {
					wait(50);
				}
				
				wait(2000);
				
				nxt_motor_set_speed(NXT_PORT_B, 0, 1);
				nxt_motor_set_speed(NXT_PORT_C, 0, 1);
				
				nxt_motor_set_count(NXT_PORT_B, 0);
				nxt_motor_set_count(NXT_PORT_C, 0);
				
				nxt_motor_set_speed(NXT_PORT_B, 0, 1);
				
				nxt_motor_set_speed(NXT_PORT_C, -(100), 0);
				
				y = u + x;
				ActivateTask(TASK_dd1112adef54413696793a61d0cc24be);
				if (y > 90) {
					while (!(ecrobot_get_sonar_sensor(NXT_PORT_S1) < 15)) {
						wait(50);
					}
					
					ecrobot_sound_tone(1000, 100, 50);
					
					nxt_motor_set_speed(NXT_PORT_B, (int)(50 + u), 0);
					nxt_motor_set_speed(NXT_PORT_C, (int)(50 + u), 0);
					
				} else {
					nxt_motor_set_count(NXT_PORT_B, 0);
					nxt_motor_set_count(NXT_PORT_C, 0);
					
					ecrobot_sound_tone(1000, 100, 50);
					
					nxt_motor_set_speed(NXT_PORT_B, (int)(50 - u), 0);
					
					nxt_motor_set_speed(NXT_PORT_C, 0, 1);
					
				}
			}
			break;
		}
		i = 0;
		j = i + 1;
		
		for (int __iter__1 = 0; __iter__1 < 10; ++__iter__1) {
			return;
			
			break;
		}
	}
}

/* Main task */
TASK(TASK_MAIN)
{
	__interpretation_started_timestamp__ = systick_get_ms();
	
	s = ecrobot_get_sonar_sensor(NXT_PORT_S1);
	c = ;
	g = ;
	G = { g };
	u = s * 180 / pi;
	nxt_motor_set_speed(NXT_PORT_B, (int)(50 + u), 0);
	nxt_motor_set_speed(NXT_PORT_C, (int)(50 + u), 0);

	

	
	}
	x = 1;
	while (true) {
		y = u + x;
		ActivateTask(TASK_dd1112adef54413696793a61d0cc24be);
		if (y > 90) {
			while (!(ecrobot_get_sonar_sensor(NXT_PORT_S1) < 15)) {
				wait(50);
			}
			
			ecrobot_sound_tone(1000, 100, 50);
			
			nxt_motor_set_speed(NXT_PORT_B, (int)(50 + u), 0);
			nxt_motor_set_speed(NXT_PORT_C, (int)(50 + u), 0);
			
		} else {
			nxt_motor_set_count(NXT_PORT_B, 0);
			nxt_motor_set_count(NXT_PORT_C, 0);
			
			ecrobot_sound_tone(1000, 100, 50);
			
			nxt_motor_set_speed(NXT_PORT_B, (int)(50 - u), 0);
			
			nxt_motor_set_speed(NXT_PORT_C, 0, 1);
			
		}
		while (!(ecrobot_get_sonar_sensor(NXT_PORT_S1) < 15)) {
			wait(50);
		}
		
		wait(2000);
		
		nxt_motor_set_speed(NXT_PORT_B, 0, 1);
		nxt_motor_set_speed(NXT_PORT_C, 0, 1);
		
		nxt_motor_set_count(NXT_PORT_B, 0);
		nxt_motor_set_count(NXT_PORT_C, 0);
		
		nxt_motor_set_speed(NXT_PORT_B, 0, 1);
		
		nxt_motor_set_speed(NXT_PORT_C, -(100), 0);
		
	}
}
