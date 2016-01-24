#pragma once
#include <boost/range/algorithm/transform.hpp>
#include <boost/phoenix.hpp>

template <typename T, typename Comp = std::less<T>>

bool FindMax(std::vector<T> const& arr, T &maxValue, Comp const& comp = Comp())  
{
	if (arr.empty())
	{
		return false;
	}

	size_t max = 0;
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (comp(arr[max], arr[i]))
		{
			max = i;
		}
	}
	maxValue = arr[max];
	return true;
}