#include "filter.h"
#include <cstring>
#include <iostream>
#include "Sort.h"

// Функция для обмена двух элементов
void swap(runner_subscription* array[], int i, int j) {
	runner_subscription* buff = array[i];
	array[i] = array[j];
	array[j] = buff;
}

//Пузырек для результата
void sort_Bubble_up_time_result(runner_subscription* array[], int size)
{
	runner_subscription* buff;
	for (int i = size - 1; i > -1; i--)
	{
		for (int k = 0; k < i; k++)
		{
			if (array[k]->result.hour > array[k + 1]->result.hour)
			{
				buff = array[k];
				array[k] = array[k + 1];
				array[k + 1] = buff;
			}
			else if
				(
					array[k]->result.hour == array[k + 1]->result.hour &&
					array[k]->result.minute > array[k + 1]->result.minute
					)
			{
				buff = array[k];
				array[k] = array[k + 1];
				array[k + 1] = buff;
			}
			else if
				(
					array[k]->result.hour == array[k + 1]->result.hour &&
					array[k]->result.minute == array[k + 1]->result.minute &&
					array[k]->result.second > array[k + 1]->result.second
					)
			{
				buff = array[k];
				array[k] = array[k + 1];
				array[k + 1] = buff;
			}
		}
	}
}

//Пузырек для клуба
void sort_Bubble_club_last_name(runner_subscription* array[], int size)
{
	runner_subscription* buff;
	//Сортировка по клубам
	for (int i = size - 1; i > -1; i--)
	{
		for (int k = 0; k < i; k++)
		{
			if (strcmp(array[k]->club, array[k + 1]->club) == 1)
			{
				buff = array[k];
				array[k] = array[k + 1];
				array[k + 1] = buff;
			}
		}
	}
	//Сортировка по Фамилиям
	for (int i = size - 1; i > -1; i--)
	{
		for (int k = 0; k < i; k++)
		{
			if (strcmp(array[k]->runner.last_name, array[k + 1]->runner.last_name) == 1 && strcmp(array[k]->club, array[k + 1]->club) == 0)
			{
				buff = array[k];
				array[k] = array[k + 1];
				array[k + 1] = buff;
			}
		}
	}
}

//Быстрая для результата
void sort_Quick_up_time_result(runner_subscription* array[], int low, int high)
{
	if (low < high) {
		// Разбиение массива
		int pi = partition_result(array, low, high);

		// Рекурсивная сортировка элементов до и после разбиения
		sort_Quick_up_time_result(array, low, pi - 1);
		sort_Quick_up_time_result(array, pi + 1, high);
	}
}

//Штука для быстрых сортировок(результат)
int partition_result(runner_subscription* array[], int low, int high) {
	int pivot = array[high]->result.hour * 3600 + array[high]->result.minute * 60 + array[high]->result.second; // Выбор последнего элемента в качестве опорного
	int i = (low - 1); // Индекс меньшего элемента

	for (int j = low; j < high; j++) {
		// Если текущий элемент меньше или равен опорному
		if ((array[j]->result.hour * 3600 + array[j]->result.minute * 60 + array[j]->result.second) <= pivot) {
			i++; // увеличиваем индекс меньшего элемента
			swap(array, i, j); // обмен элементов
		}
	}
	swap(array, i + 1, high); // обмен опорного элемента с элементом в индексе i+1
	return (i + 1); // возвращаем индекс опорного элемента
}

//Быстрая для клуба(клуб)
void sort_Quick_club(runner_subscription* array[], int low, int high)
{
	if (low < high) {
		// Разбиение массива
		int pi = partition_club(array, low, high);

		// Рекурсивная сортировка элементов до и после разбиения
		sort_Quick_club(array, low, pi - 1);
		sort_Quick_club(array, pi + 1, high);
	}
}

//Штука для быстрых сортировок(клуб)
int partition_club(runner_subscription* array[], int low, int high) {
	char* pivot = array[high]->club; // Выбор последнего элемента в качестве опорного
	int i = (low - 1); // Индекс меньшего элемента

	for (int j = low; j < high; j++) {
		// Если текущий элемент меньше или равен опорному
		if (strcmp(array[j]->club, pivot) <= 0) {
			i++; // увеличиваем индекс меньшего элемента
			swap(array, i, j); // обмен элементов
		}
	}
	swap(array, i + 1, high); // обмен опорного элемента с элементом в индексе i+1
	return (i + 1); // возвращаем индекс опорного элемента
}

//Быстрая для клуба(фамилия)
void sort_Quick_last_name(runner_subscription* array[], int low, int high)
{
	if (low < high) {
		// Разбиение массива
		int pi = partition_last_name(array, low, high);

		// Рекурсивная сортировка элементов до и после разбиения
		sort_Quick_last_name(array, low, pi - 1);
		sort_Quick_last_name(array, pi + 1, high);
	}
}

//Штука для быстрых сортировок(фамилия)
int partition_last_name(runner_subscription* array[], int low, int high) {
	char* pivot = array[high]->runner.last_name; // Выбор последнего элемента в качестве опорного
	int i = (low - 1); // Индекс меньшего элемента

	for (int j = low; j < high; j++) {
		// Если текущий элемент меньше или равен опорному
		if (strcmp(array[j]->runner.last_name, pivot) <= 0) {
			i++; // увеличиваем индекс меньшего элемента
			swap(array, i, j); // обмен элементов
		}
	}
	swap(array, i + 1, high); // обмен опорного элемента с элементом в индексе i+1
	return (i + 1); // возвращаем индекс опорного элемента
}
