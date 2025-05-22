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
	/********** вывод бегуна **********/
	cout << "Бегун..........: ";
	// вывод номера
	cout << subscription->number << ". ";
	// вывод фамилии
	cout << subscription->runner.last_name << " ";
	// вывод первой буквы имени
	cout << subscription->runner.first_name[0] << ". ";
	// вывод первой буквы отчества
	cout << subscription->runner.middle_name[0] << ".";
	cout << '\n';
	/********** вывод клуба **********/
	cout << "Клуб...........: ";
	// вывод названия клуба
	cout << subscription->club;
	cout << '\n';
	/********** вывод времени старта **********/
	cout << "Время старта...: ";
	// вывод часов
	cout << setw(2) << setfill('0') << subscription->start.hour << ":";
	// вывод минут
	cout << setw(2) << setfill('0') << subscription->start.minute << ":";
	// вывод секунд
	cout << setw(2) << setfill('0') << subscription->start.second << " ";
	cout << '\n';
	/********** вывод времени финиша **********/
	cout << "Время финиша...: ";
	// вывод часов
	cout << setw(2) << setfill('0') << subscription->finish.hour << ":";
	// вывод минут
	cout << setw(2) << setfill('0') << subscription->finish.minute << ":";
	// вывод секунд
	cout << setw(2) << setfill('0') << subscription->finish.second << " ";
	cout << '\n';
	/********** вывод результата ***************/
	cout << "Результат......: ";
	// вывод часов
	cout << setw(2) << setfill('0') << subscription->result.hour << ":";
	// вывод минут
	cout << setw(2) << setfill('0') << subscription->result.minute << ":";
	// вывод секунд
	cout << setw(2) << setfill('0') << subscription->result.second << " ";
	cout << '\n';
	cout << '\n';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа №9. GIT\n";
	cout << "Вариант №1. Результаты марафона\n";
	cout << "Автор: Пичев Владислав";
	cout << "Группа: 24ИСиТ\n\n";
	runner_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", subscriptions, size);
		//Массив для отсортированных
		runner_subscription* sorted[100];
		for (int i = 0; i < size; i++)
		{
			sorted[i] = subscriptions[i];
		}
		cout << "***** Результаты марафона *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(subscriptions[i]);
		}
		bool (*check_filter)(runner_subscription*) = NULL; // check_function - это указатель на функцию, возвращающую значение типа bool,
		// и принимающую в качестве параметра значение типа book_subscription*

		bool check_choose = true;
		//Выбор фильтрации
		cout << "\nВыберите способ фильтрации или обработки данных:\n";
		cout << "1) Вывести всех участников и их результаты из клуба \"Спартак\"\n";
		cout << "2) Вывести всех участников, у которых результат лучше чем 2:50:00\n";
		cout << "\nВведите номер выбранного пункта: ";

		int item_filter;
		cin >> item_filter;

		if (item_filter != 1 && item_filter != 2)
		{
			check_choose = false;
		}

		cout << "\nВыберите метод сортировки:\n";
		cout << "1) Bubble sort\n";
		cout << "2) Quick sort\n";
		cout << "\nВведите номер выбранного пункта: ";

		int item_sort_method;
		cin >> item_sort_method;

		if (item_sort_method != 1 && item_sort_method != 2)
		{
			check_choose = false;
		}

		cout << "\nВыберите критерий сортировки:\n";
		cout << "1) По возрастанию времени забега (разницы между временем финиша и старта)\n";
		cout << "2) По возрастанию названия спортивного клуба, а в рамках одного клуба по возрастанию фамилии участника\n";
		cout << "\nВведите номер выбранного пункта: ";

		int item_criteria;
		cin >> item_criteria;

		if (item_criteria != 1 && item_criteria != 2)
		{
			check_choose = false;
		}

		cout << '\n';

		if (!check_choose)
		{
			cerr << "Некоректный номер пункта" << '\n';
			return 1;
		}

		//Фильтрация
		switch (item_filter)
		{
		case 1:
			check_filter = check_runner_subscription_by_club; // присваиваем в указатель на функцию соответствующую функцию
			cout << "******************** Участники клуба \"Спартак\" ********************\n\n";
			break;
		case 2:
			check_filter = check_runner_subscription_by_time; // присваиваем в указатель на функцию соответствующую функцию
			cout << "******************** Участники с результатом лучше чем 2:50:00 ********************\n\n";
			break;
		}
		if (check_filter)
		{
			int new_size;
			//Фильтрация
			runner_subscription** filtered = filter(subscriptions, size, check_filter, new_size);
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}

			delete[] filtered;

			//Сортировка


			if (item_sort_method == 1)
			{
				cout << "******************** Сортировка Пузырьком ********************\n";
				//Пузырек
				if (item_criteria == 1)
				{
					cout << "******************** Сортировка по возрастанию времени забега ********************\n\n";
					sort_Bubble_up_time_result(sorted, size);

				}
				else if (item_criteria == 2)
				{
					cout << "******************** Сортировка по возрастанию названия спортивного клуба, а в рамках одного клуба по возрастанию фамилии участника ********************\n\n";
					sort_Bubble_club_last_name(sorted, size);
				}

			}
			else if (item_sort_method == 2)
			{
				cout << "******************** Быстрая сортировка ********************\n";
				//Быстро
				if (item_criteria == 1)
				{
					cout << "******************** Сортировка по возрастанию времени забега ********************\n\n";
					sort_Quick_up_time_result(sorted, 0, size - 1);
				}
				else if (item_criteria == 2)
				{
					cout << "******************** Сортировка по возрастанию названия спортивного клуба, а в рамках одного клуба по возрастанию фамилии участника ********************\n\n";
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