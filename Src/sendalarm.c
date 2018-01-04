#include "sendalarm.h"

uint8_t duty_history[MEAN_WINDOW_LENGTH];
uint8_t current_index = 0; // Index to be overwritten

uint8_t current_mean = 0;
bool current_mean_is_valid = false;

uint8_t get_current_mean_duty_cycle()
{
	if(!current_mean_is_valid)
		return 0;
	else
		return current_mean;
}

void compute_mean()
{
	if(!current_mean_is_valid)
		return;
	uint16_t sum = 0;
	for(int i = 0; i < MEAN_WINDOW_LENGTH; ++i)
	{
		sum += duty_history[i];
	}
	sum = sum / MEAN_WINDOW_LENGTH;
	current_mean = sum;
}

void register_current_duty_cycle(uint8_t new_duty_cycle)
{
	if(new_duty_cycle == 0 || new_duty_cycle == 255) // Invalid duty cycle
	{
		current_index = 0;
		current_mean_is_valid = false;
		return;
	}
	if(!current_mean_is_valid && current_index == MEAN_WINDOW_LENGTH - 1) // Window has just been filled
		current_mean_is_valid = true;
	duty_history[current_index] = new_duty_cycle;
	current_index = (current_index + 1) % MEAN_WINDOW_LENGTH;
	compute_mean();
}

bool is_alarm_triggered()
{
	if(!current_mean_is_valid)
		return false;
	if(current_mean < 127)
		return true;
	return false;
}
