// task2tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Task2/Stack.h"

struct Item
{

};

struct DefaultStack_
{
	CStack<Item> defaultStack;
};
// —тек по умолчанию:
BOOST_FIXTURE_TEST_SUITE(DefaultStack, DefaultStack_)
// €вл€етс€ пустым
	BOOST_AUTO_TEST_CASE(IsEmpty)
	{
		BOOST_CHECK(defaultStack.IsEmpty());
	}

	// после добавлени€ элемента становитс€ не пустым
	BOOST_AUTO_TEST_CASE(BecomesNotEmptyAutoPushingAnElement)
	{
		defaultStack.Push(Item());
		BOOST_CHECK(!defaultStack.IsEmpty());
	}

	BOOST_AUTO_TEST_CASE(PushPopGetWorksOnString)
	{
		CStack<std::string> stack;
		stack.Push("1");
		stack.Push("2");
		BOOST_CHECK_EQUAL(stack.Peek(), "2");
		BOOST_CHECK_EQUAL(stack.Pop(), "2");
		BOOST_CHECK_EQUAL(stack.Peek(), "1");
		BOOST_CHECK_EQUAL(stack.Pop(), "1");
		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
	}

	BOOST_AUTO_TEST_CASE(CorrectStackClearing)
	{
		CStack<std::string> stack;
		stack.Push("1");
		stack.Push("2");
		stack.Clear();
		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
	}

	BOOST_AUTO_TEST_CASE(CorrectStackFromAnotherStack)
	{
		CStack<std::string> stack;
		stack.Push("1");
		stack.Push("2");

		CStack<std::string> stack1(stack);

		BOOST_CHECK_EQUAL(stack1.Peek(), "2");
		BOOST_CHECK_EQUAL(stack1.Pop(), "2");
		BOOST_CHECK_EQUAL(stack1.Peek(), "1");
		BOOST_CHECK_EQUAL(stack1.Pop(), "1");
		BOOST_CHECK_EQUAL(stack1.IsEmpty(), true);
	}

	BOOST_AUTO_TEST_CASE(CorrectStackFromEmptyStack)
	{
		CStack<std::string> stack;

		CStack<std::string> stack1(stack);

		BOOST_CHECK_EQUAL(stack1.IsEmpty(), true);
	}

	BOOST_AUTO_TEST_CASE(CorrectStackFromAnotherStackToEmptyStackSingleElement)
	{
		CStack<std::string> stack;

		CStack<std::string> stack1;
		stack1.Push("3");

		stack = stack1;

		BOOST_CHECK_EQUAL(stack.Peek(), "3");
		BOOST_CHECK_EQUAL(stack.Pop(), "3");
		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
	}

	BOOST_AUTO_TEST_CASE(CorrectStackFromAnotherStackToEmptyStackMultiElement)
	{
		CStack<std::string> stack;

		CStack<std::string> stack1;
		stack1.Push("3");
		stack1.Push("4");

		stack = stack1;

		BOOST_CHECK_EQUAL(stack.Peek(), "4");
		BOOST_CHECK_EQUAL(stack.Pop(), "4");
		BOOST_CHECK_EQUAL(stack.Peek(), "3");
		BOOST_CHECK_EQUAL(stack.Pop(), "3");
		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
	}

	BOOST_AUTO_TEST_CASE(CorrectStackFromAnotherStackToNotEmptyStackSingleElement)
	{
		CStack<std::string> stack;
		stack.Push("1");

		CStack<std::string> stack1;
		stack1.Push("3");

		stack = stack1;

		BOOST_CHECK_EQUAL(stack.Peek(), "3");
		BOOST_CHECK_EQUAL(stack.Pop(), "3");
		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
	}

	BOOST_AUTO_TEST_CASE(CorrectStackFromAnotherStackToNotEmptyStackMultiElement)
	{
		CStack<std::string> stack;
		stack.Push("1");
		stack.Push("2");

		CStack<std::string> stack1;
		stack1.Push("3");
		stack1.Push("4");

		stack = stack1;

		BOOST_CHECK_EQUAL(stack.Peek(), "4");
		BOOST_CHECK_EQUAL(stack.Pop(), "4");
		BOOST_CHECK_EQUAL(stack.Peek(), "3");
		BOOST_CHECK_EQUAL(stack.Pop(), "3");
		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
	}

	#define HUGE_NUMBER 500000

	BOOST_AUTO_TEST_CASE(Correct500KStackFromAnother500KStack)
	{
		CStack<int> stack;
		CStack<int> stack1;
		for (int i = 0; i < HUGE_NUMBER; i++)
		{
			stack.Push(i);
		}

		for (int i = 1; i <= HUGE_NUMBER; i++)
		{
			stack1.Push(i);
		}

		stack = stack1;

		for (int i = HUGE_NUMBER; i > 0; i--)
		{
			BOOST_CHECK_EQUAL(stack.Peek(), i);
			BOOST_CHECK_EQUAL(stack.Pop(), i);
		}
		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
	}
BOOST_AUTO_TEST_SUITE_END()