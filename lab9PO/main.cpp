#include <iostream>
#include <iomanip>

using namespace std;

#include "Sort.h"
#include "runner_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(runner_subscription* subscription)
{
	/********** ����� ������ **********/
	cout << "�����..........: ";
	// ����� ������
	cout << subscription->number << ". ";
	// ����� �������
	cout << subscription->runner.last_name << " ";
	// ����� ������ ����� �����
	cout << subscription->runner.first_name[0] << ". ";
	// ����� ������ ����� ��������
	cout << subscription->runner.middle_name[0] << ".";
	cout << '\n';
	/********** ����� ����� **********/
	cout << "����...........: ";
	// ����� �������� �����
	cout << subscription->club;
	cout << '\n';
	/********** ����� ������� ������ **********/
	cout << "����� ������...: ";
	// ����� �����
	cout << setw(2) << setfill('0') << subscription->start.hour << ":";
	// ����� �����
	cout << setw(2) << setfill('0') << subscription->start.minute << ":";
	// ����� ������
	cout << setw(2) << setfill('0') << subscription->start.second << " ";
	cout << '\n';
	/********** ����� ������� ������ **********/
	cout << "����� ������...: ";
	// ����� �����
	cout << setw(2) << setfill('0') << subscription->finish.hour << ":";
	// ����� �����
	cout << setw(2) << setfill('0') << subscription->finish.minute << ":";
	// ����� ������
	cout << setw(2) << setfill('0') << subscription->finish.second << " ";
	cout << '\n';
	/********** ����� ���������� ***************/
	cout << "���������......: ";
	// ����� �����
	cout << setw(2) << setfill('0') << subscription->result.hour << ":";
	// ����� �����
	cout << setw(2) << setfill('0') << subscription->result.minute << ":";
	// ����� ������
	cout << setw(2) << setfill('0') << subscription->result.second << " ";
	cout << '\n';
	cout << '\n';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������������ ������ �9. GIT\n";
	cout << "������� �1. ���������� ��������\n";
	cout << "�����: ����� ���������";
	cout << "������: 24����\n\n";
	runner_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", subscriptions, size);
		//������ ��� ���������������
		runner_subscription* sorted[100];
		for (int i = 0; i < size; i++)
		{
			sorted[i] = subscriptions[i];
		}
		cout << "***** ���������� �������� *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(subscriptions[i]);
		}
		bool (*check_filter)(runner_subscription*) = NULL; // check_function - ��� ��������� �� �������, ������������ �������� ���� bool,
		// � ����������� � �������� ��������� �������� ���� book_subscription*

		bool check_choose = true;
		//����� ����������
		cout << "\n�������� ������ ���������� ��� ��������� ������:\n";
		cout << "1) ������� ���� ���������� � �� ���������� �� ����� \"�������\"\n";
		cout << "2) ������� ���� ����������, � ������� ��������� ����� ��� 2:50:00\n";
		cout << "\n������� ����� ���������� ������: ";

		int item_filter;
		cin >> item_filter;

		if (item_filter != 1 && item_filter != 2)
		{
			check_choose = false;
		}

		cout << "\n�������� ����� ����������:\n";
		cout << "1) Bubble sort\n";
		cout << "2) Quick sort\n";
		cout << "\n������� ����� ���������� ������: ";

		int item_sort_method;
		cin >> item_sort_method;

		if (item_sort_method != 1 && item_sort_method != 2)
		{
			check_choose = false;
		}

		cout << "\n�������� �������� ����������:\n";
		cout << "1) �� ����������� ������� ������ (������� ����� �������� ������ � ������)\n";
		cout << "2) �� ����������� �������� ����������� �����, � � ������ ������ ����� �� ����������� ������� ���������\n";
		cout << "\n������� ����� ���������� ������: ";

		int item_criteria;
		cin >> item_criteria;

		if (item_criteria != 1 && item_criteria != 2)
		{
			check_choose = false;
		}

		cout << '\n';

		if (!check_choose)
		{
			cerr << "����������� ����� ������" << '\n';
			return 1;
		}

		//����������
		switch (item_filter)
		{
		case 1:
			check_filter = check_runner_subscription_by_club; // ����������� � ��������� �� ������� ��������������� �������
			cout << "******************** ��������� ����� \"�������\" ********************\n\n";
			break;
		case 2:
			check_filter = check_runner_subscription_by_time; // ����������� � ��������� �� ������� ��������������� �������
			cout << "******************** ��������� � ����������� ����� ��� 2:50:00 ********************\n\n";
			break;
		}
		if (check_filter)
		{
			int new_size;
			//����������
			runner_subscription** filtered = filter(subscriptions, size, check_filter, new_size);
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}

			delete[] filtered;

			//����������


			if (item_sort_method == 1)
			{
				cout << "******************** ���������� ��������� ********************\n";
				//�������
				if (item_criteria == 1)
				{
					cout << "******************** ���������� �� ����������� ������� ������ ********************\n\n";
					sort_Bubble_up_time_result(sorted, size);

				}
				else if (item_criteria == 2)
				{
					cout << "******************** ���������� �� ����������� �������� ����������� �����, � � ������ ������ ����� �� ����������� ������� ��������� ********************\n\n";
					sort_Bubble_club_last_name(sorted, size);
				}

			}
			else if (item_sort_method == 2)
			{
				cout << "******************** ������� ���������� ********************\n";
				//������
				if (item_criteria == 1)
				{
					cout << "******************** ���������� �� ����������� ������� ������ ********************\n\n";
					sort_Quick_up_time_result(sorted, 0, size - 1);
				}
				else if (item_criteria == 2)
				{
					cout << "******************** ���������� �� ����������� �������� ����������� �����, � � ������ ������ ����� �� ����������� ������� ��������� ********************\n\n";
					sort_Quick_club(sorted, 0, size - 1);
					int buff = 0;
					for (int i = 0; i < size - 1; i++)
					{
						if (strcmp(sorted[i]->club, sorted[i + 1]->club) != 0 || i == size - 2)
						{
							sort_Quick_last_name(sorted, buff, i);
							buff = i + 1;
						}
					}
				}
			}

			for (int i = 0; i < size; i++)
			{
				output(sorted[i]);
			}

		}
		for (int i = 0; i < size; i++)
		{
			delete subscriptions[i];
		}
	}
	catch (const char* error)
	{
		cout << error << '\n';
	}
	return 0;
}