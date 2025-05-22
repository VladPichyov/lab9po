#include "pch.h"
#include "CppUnitTest.h"

#include "C:\Users\Vlad\git\lab9po\lab9PO\runner_subscription.h"
#include "C:\Users\Vlad\git\lab9po\lab9PO\processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	// вспомогательная функция для создания одной записи на абонементе
	// так как для тестов необходимы лишь данные о дате выдачи и возврате книги,
	// данные о названии, авторе и читателе не заполняются
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
		TEST_METHOD(TestMethod1)
		{
			runner_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 22, 54);
			subscriptions[1] = build_subscription(1, 22, 0);
			subscriptions[2] = build_subscription(1, 22, 33);
			Assert::AreEqual("01:22:00", process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod2)
		{
			runner_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 12, 33);
			subscriptions[1] = build_subscription(1, 44, 33);
			subscriptions[2] = build_subscription(1, 23, 33);
			Assert::AreEqual("01:12:33", process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod3)
		{
			runner_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 22, 54);
			subscriptions[1] = build_subscription(3, 22, 54);
			subscriptions[2] = build_subscription(2, 22, 54);
			Assert::AreEqual("01:22:54", process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod4)
		{
			runner_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(2, 14, 50);
			subscriptions[1] = build_subscription(2, 57, 50);
			subscriptions[2] = build_subscription(1, 14, 50);
			Assert::AreEqual("01:14:50", process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod5)
		{
			runner_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(3, 8, 18);
			subscriptions[1] = build_subscription(2, 8, 32);
			subscriptions[2] = build_subscription(2, 8, 23);
			Assert::AreEqual("02:08:23", process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod6)
		{
			runner_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(3, 24, 39);
			subscriptions[1] = build_subscription(3, 58, 55);
			subscriptions[2] = build_subscription(3, 41, 4);
			Assert::AreEqual("03:24:39", process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod7)
		{
			runner_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(3, 12, 46);
			subscriptions[1] = build_subscription(3, 32, 17);
			subscriptions[2] = build_subscription(3, 12, 52);
			Assert::AreEqual("03:12:46", process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod8)
		{
			runner_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(0, 0, 0);
			subscriptions[1] = build_subscription(0, 0, 1);
			subscriptions[2] = build_subscription(0, 0, 1);
			Assert::AreEqual("00:00:00", process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}
		TEST_METHOD(TestMethod9)
		{
			runner_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(3, 12, 46);
			subscriptions[1] = build_subscription(3, 32, 17);
			subscriptions[2] = build_subscription(3, 12, 52);
			Assert::AreEqual("03:12:46", process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}
	};
}

