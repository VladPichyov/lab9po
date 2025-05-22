#ifndef FILTER_H
#define FILTER_H

#include "runner_subscription.h"

runner_subscription** filter(runner_subscription* array[], int size, bool (*check)(runner_subscription* element), int& result_size);

/*
ОПИСАНИЕ ФУНКЦИИ <function_name>:
    функция перебирает массив с исходными данными и все указатели на элементы,
    для которых функция отбора возвращает значение true, помещаются в новый
    массив, указатель на который возвращается функцией

ПАРАМЕТРЫ:
    array       - массив с исходными данными
    size        - размер массива с исходными данными
    check       - указатель на функцию отбора.
                  В качестве значения этого параметра можно передать имя
                  функции отбора, прототип которой приведён ниже
    result_data - параметр, передаваемый по ссылке - переменная, в которую
                  функция запишет размер результирующего массива

ВОЗВРАЩАЕМОЕ ЗНАЧЕНИЕ
    указатель на массив из указателей на элементы, удовлетворяющие условию
    отбора (для которых функция отбора возвращает true)
*/


bool check_runner_subscription_by_club(runner_subscription* element);

/*
ОПИСАНИЕ ФУНКЦИИ check_book_subscription_by_author:
    функция отбора - проверяет, является ли Пушкин Александр Сергеевич автором книги в записи на абонементе

ПАРАМЕТРЫ:
    element - указатель на элемент, который нужно проверить

ВОЗВРАЩАЕМОЕ ЗНАЧЕНИЕ
    true, если Пушкин Александр Сергеевич является автором книги в записи на абонементе, и false в ином случае
*/


bool check_runner_subscription_by_time(runner_subscription* element);

/*
ОПИСАНИЕ ФУНКЦИИ check_book_subscription_by_date:
    функция отбора - проверяет, взята ли книга из текущей записи на абонементе в марте 2021-го года

ПАРАМЕТРЫ:
    element - указатель на элемент, который нужно проверить

ВОЗВРАЩАЕМОЕ ЗНАЧЕНИЕ
    true, если книга из текущей записи на абонементе взята в марте 2021-го года, и false в ином случае
*/

bool sort_runner_subscription_by_result_up_bubble(runner_subscription* element);
bool sort_runner_subscription_by_result_up_quick(runner_subscription* element);
bool sort_runner_subscription_by_club_last_name_up_bubble(runner_subscription* element);
bool sort_runner_subscription_by_club_last_name_up_quick(runner_subscription* element);
#endif
