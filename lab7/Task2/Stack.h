#pragma once
#include <boost/range/algorithm/transform.hpp>
#include <boost/phoenix.hpp>

template <typename T>
class CStack
{
public:

	struct Item
	{
		//  онструктор €вл€етс€ шаблонным, дл€ реализации т.н. perfect forwarding
		// ¬ случае, когда аргументом €вл€етс€ rvalue, значение будет перемещено
		// в противном случае - скопировано
		template <typename TT>
		Item(TT && value, std::unique_ptr<Item> && previous)
			: value(std::forward<T>(value))
			, previous(std::move(previous))
		{}

		T value;
		std::unique_ptr<Item> previous;
	};

	CStack()
	{
	}

	~CStack()
	{
		Clear();
	}

	bool IsEmpty() const
	{
		return !m_top;
	}

	// ћетод Push €вл€етс€ шаблонным, дл€ реализации т.н. perfect forwarding
	// ¬ случае, когда аргументом €вл€етс€ rvalue, значение будет перемещено
	// в противном случае - скопировано
	template <typename TT>
	void Push(TT && value)
	{
		m_top = std::make_unique<Item>(std::forward<T>(value), move(m_top));
	}

	T Peek()
	{
		return m_top->value;
	}

	T Pop()
	{
		T top = m_top->value;
		m_top = std::move(m_top->previous);
		return top;
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			m_top = std::move(m_top->previous);
		}
	}

	CStack(CStack & other)
	{
		*this = other;
	}

	CStack & operator=(CStack & source)
	{
		CStack tempStack;
		Clear();
		while (!source.IsEmpty())
		{
			tempStack.Push(source.Pop());
		}
		while (!tempStack.IsEmpty())
		{
			source.Push(tempStack.Peek());
			Push(tempStack.Pop());
		}
		return *this;
	}



private:
	std::unique_ptr<Item> m_top;
};

