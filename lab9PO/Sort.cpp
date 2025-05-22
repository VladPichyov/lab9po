#include "filter.h"
#include <cstring>
#include <iostream>
#include "Sort.h"

// ������� ��� ������ ���� ���������
void swap(runner_subscription* array[], int i, int j) {
	runner_subscription* buff = array[i];
	array[i] = array[j];
	array[j] = buff;
}

//������� ��� ����������
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

//������� ��� �����
void sort_Bubble_club_last_name(runner_subscription* array[], int size)
{
	runner_subscription* buff;
	//���������� �� ������
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
	//���������� �� ��������
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

//������� ��� ����������
void sort_Quick_up_time_result(runner_subscription* array[], int low, int high)
{
	if (low < high) {
		// ��������� �������
		int pi = partition_result(array, low, high);

		// ����������� ���������� ��������� �� � ����� ���������
		sort_Quick_up_time_result(array, low, pi - 1);
		sort_Quick_up_time_result(array, pi + 1, high);
	}
}

//����� ��� ������� ����������(���������)
int partition_result(runner_subscription* array[], int low, int high) {
	int pivot = array[high]->result.hour * 3600 + array[high]->result.minute * 60 + array[high]->result.second; // ����� ���������� �������� � �������� ��������
	int i = (low - 1); // ������ �������� ��������

	for (int j = low; j < high; j++) {
		// ���� ������� ������� ������ ��� ����� ��������
		if ((array[j]->result.hour * 3600 + array[j]->result.minute * 60 + array[j]->result.second) <= pivot) {
			i++; // ����������� ������ �������� ��������
			swap(array, i, j); // ����� ���������
		}
	}
	swap(array, i + 1, high); // ����� �������� �������� � ��������� � ������� i+1
	return (i + 1); // ���������� ������ �������� ��������
}

//������� ��� �����(����)
void sort_Quick_club(runner_subscription* array[], int low, int high)
{
	if (low < high) {
		// ��������� �������
		int pi = partition_club(array, low, high);

		// ����������� ���������� ��������� �� � ����� ���������
		sort_Quick_club(array, low, pi - 1);
		sort_Quick_club(array, pi + 1, high);
	}
}

//����� ��� ������� ����������(����)
int partition_club(runner_subscription* array[], int low, int high) {
	char* pivot = array[high]->club; // ����� ���������� �������� � �������� ��������
	int i = (low - 1); // ������ �������� ��������

	for (int j = low; j < high; j++) {
		// ���� ������� ������� ������ ��� ����� ��������
		if (strcmp(array[j]->club, pivot) <= 0) {
			i++; // ����������� ������ �������� ��������
			swap(array, i, j); // ����� ���������
		}
	}
	swap(array, i + 1, high); // ����� �������� �������� � ��������� � ������� i+1
	return (i + 1); // ���������� ������ �������� ��������
}

//������� ��� �����(�������)
void sort_Quick_last_name(runner_subscription* array[], int low, int high)
{
	if (low < high) {
		// ��������� �������
		int pi = partition_last_name(array, low, high);

		// ����������� ���������� ��������� �� � ����� ���������
		sort_Quick_last_name(array, low, pi - 1);
		sort_Quick_last_name(array, pi + 1, high);
	}
}

//����� ��� ������� ����������(�������)
int partition_last_name(runner_subscription* array[], int low, int high) {
	char* pivot = array[high]->runner.last_name; // ����� ���������� �������� � �������� ��������
	int i = (low - 1); // ������ �������� ��������

	for (int j = low; j < high; j++) {
		// ���� ������� ������� ������ ��� ����� ��������
		if (strcmp(array[j]->runner.last_name, pivot) <= 0) {
			i++; // ����������� ������ �������� ��������
			swap(array, i, j); // ����� ���������
		}
	}
	swap(array, i + 1, high); // ����� �������� �������� � ��������� � ������� i+1
	return (i + 1); // ���������� ������ �������� ��������
}
