#include "filter.h"
#include <cstring>
#include <iostream>

runner_subscription** filter(runner_subscription* array[], int size, bool (*check)(runner_subscription* element), int& result_size)
{
	runner_subscription** result = new runner_subscription * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_runner_subscription_by_club(runner_subscription* element)
{
	return strcmp(element->club, "\"Спартак\"") == 0;
}

bool check_runner_subscription_by_time(runner_subscription* element)
{
	if (element->finish.hour - element->start.hour > 2)
		return false;
	else if (element->finish.hour - element->start.hour < 2)
		return true;
	else if (element->finish.minute - element->start.minute > 50)
		return false;
	else if (element->finish.minute - element->start.minute < 50)
		return true;
	else if (element->finish.second - element->start.second == 0)
		return true;
	else
		return false;
}
