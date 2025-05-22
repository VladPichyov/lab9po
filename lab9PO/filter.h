#ifndef FILTER_H
#define FILTER_H

#include "runner_subscription.h"

runner_subscription** filter(runner_subscription* array[], int size, bool (*check)(runner_subscription* element), int& result_size);

/*
�������� ������� <function_name>:
    ������� ���������� ������ � ��������� ������� � ��� ��������� �� ��������,
    ��� ������� ������� ������ ���������� �������� true, ���������� � �����
    ������, ��������� �� ������� ������������ ��������

���������:
    array       - ������ � ��������� �������
    size        - ������ ������� � ��������� �������
    check       - ��������� �� ������� ������.
                  � �������� �������� ����� ��������� ����� �������� ���
                  ������� ������, �������� ������� ������� ����
    result_data - ��������, ������������ �� ������ - ����������, � �������
                  ������� ������� ������ ��������������� �������

������������ ��������
    ��������� �� ������ �� ���������� �� ��������, ��������������� �������
    ������ (��� ������� ������� ������ ���������� true)
*/


bool check_runner_subscription_by_club(runner_subscription* element);

/*
�������� ������� check_book_subscription_by_author:
    ������� ������ - ���������, �������� �� ������ ��������� ��������� ������� ����� � ������ �� ����������

���������:
    element - ��������� �� �������, ������� ����� ���������

������������ ��������
    true, ���� ������ ��������� ��������� �������� ������� ����� � ������ �� ����������, � false � ���� ������
*/


bool check_runner_subscription_by_time(runner_subscription* element);

/*
�������� ������� check_book_subscription_by_date:
    ������� ������ - ���������, ����� �� ����� �� ������� ������ �� ���������� � ����� 2021-�� ����

���������:
    element - ��������� �� �������, ������� ����� ���������

������������ ��������
    true, ���� ����� �� ������� ������ �� ���������� ����� � ����� 2021-�� ����, � false � ���� ������
*/

bool sort_runner_subscription_by_result_up_bubble(runner_subscription* element);
bool sort_runner_subscription_by_result_up_quick(runner_subscription* element);
bool sort_runner_subscription_by_club_last_name_up_bubble(runner_subscription* element);
bool sort_runner_subscription_by_club_last_name_up_quick(runner_subscription* element);
#endif
