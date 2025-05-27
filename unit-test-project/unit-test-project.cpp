#include "pch.h"
#include "CppUnitTest.h"

#include "..\lab9PO\runner_subscription.h"
#include "..\lab9PO\processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    runner_subscription* build_subscription(int result_hour, int result_minute, int result_second)
    {
        runner_subscription* subscription = new runner_subscription;
        subscription->result.hour = result_hour;
        subscription->result.minute = result_minute;
        subscription->result.second = result_second;
        return subscription;
    }

    // вспомогательная функция для удаления массива тестовых данных
    void delete_subscription(runner_subscription* array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            delete array[i];
        }
    }

    TEST_CLASS(unittestproject)
    {
    public:
        // Проверяет минимальное время среди трёх записей
        TEST_METHOD(TestMethod1)
        {
            runner_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(1, 22, 54); // входные данные
            subscriptions[1] = build_subscription(1, 22, 0);
            subscriptions[2] = build_subscription(1, 22, 33);
            Assert::AreEqual("01:22:00", process(subscriptions, 3)); // ожидаемый вывод
            delete_subscription(subscriptions, 3);
        }

        // Проверяет случай, когда minute определяет минимальное время
        TEST_METHOD(TestMethod2)
        {
            runner_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(1, 12, 33); // подаваемые данные
            subscriptions[1] = build_subscription(1, 44, 33);
            subscriptions[2] = build_subscription(1, 23, 33);
            Assert::AreEqual("01:12:33", process(subscriptions, 3)); // ожидаемый вывод
            delete_subscription(subscriptions, 3);
        }

        // Проверяет случай, когда hour определяет минимальное время
        TEST_METHOD(TestMethod3)
        {
            runner_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(1, 22, 54); // входные данные
            subscriptions[1] = build_subscription(3, 22, 54);
            subscriptions[2] = build_subscription(2, 22, 54);
            Assert::AreEqual("01:22:54", process(subscriptions, 3)); // ожидаемый вывод
            delete_subscription(subscriptions, 3);
        }

        // Проверяет минимальное значение hour и minute
        TEST_METHOD(TestMethod4)
        {
            runner_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(2, 14, 50);
            subscriptions[1] = build_subscription(2, 57, 50);
            subscriptions[2] = build_subscription(1, 14, 50);
            Assert::AreEqual("01:14:50", process(subscriptions, 3)); // ожидаемый вывод
            delete_subscription(subscriptions, 3);
        }

        // Проверяет случай, когда минимальное время определяется по hour
        TEST_METHOD(TestMethod5)
        {
            runner_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(3, 8, 18);
            subscriptions[1] = build_subscription(2, 8, 32);
            subscriptions[2] = build_subscription(2, 8, 23);
            Assert::AreEqual("02:08:23", process(subscriptions, 3)); // ожидаемый вывод
            delete_subscription(subscriptions, 3);
        }

        // Проверяет минимальное значение minute при одинаковых hour
        TEST_METHOD(TestMethod6)
        {
            runner_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(3, 24, 39);
            subscriptions[1] = build_subscription(3, 58, 55);
            subscriptions[2] = build_subscription(3, 41, 4);
            Assert::AreEqual("03:24:39", process(subscriptions, 3)); // ожидаемый вывод
            delete_subscription(subscriptions, 3);
        }

        // Проверяет минимальное значение second при одинаковых hour и minute
        TEST_METHOD(TestMethod7)
        {
            runner_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(3, 12, 46);
            subscriptions[1] = build_subscription(3, 32, 17);
            subscriptions[2] = build_subscription(3, 12, 52);
            Assert::AreEqual("03:12:46", process(subscriptions, 3)); // ожидаемый вывод
            delete_subscription(subscriptions, 3);
        }

        // Проверяет случай, когда все значения равны нулю
        TEST_METHOD(TestMethod8)
        {
            runner_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(0, 0, 0);
            subscriptions[1] = build_subscription(0, 0, 1);
            subscriptions[2] = build_subscription(0, 0, 1);
            Assert::AreEqual("00:00:00", process(subscriptions, 3)); // ожидаемый вывод
            delete_subscription(subscriptions, 3);
        }

        // Дублирует TestMethod7 для проверки стабильности функции process()
        TEST_METHOD(TestMethod9)
        {
            runner_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(3, 12, 46);
            subscriptions[1] = build_subscription(3, 32, 17);
            subscriptions[2] = build_subscription(3, 12, 52);
            Assert::AreEqual("03:12:46", process(subscriptions, 3)); // ожидаемый вывод
            delete_subscription(subscriptions, 3);
        }
    };
}

