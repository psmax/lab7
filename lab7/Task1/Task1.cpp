// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "FindMax.h"
#include <string>

using namespace std;

struct Sportsman
{
	string name;
	unsigned height;
	unsigned weight;
};


BOOST_AUTO_TEST_CASE(TestEmptyVector)
{
	int max = 1;
	BOOST_CHECK(!FindMax(vector<int>(), max));
	BOOST_CHECK_EQUAL(max, 1);
}

BOOST_AUTO_TEST_CASE(FindMaxValueInIntVector)
{
	int max;
	BOOST_CHECK(FindMax(vector<int>{ -2, 1, 6, 0, 9, -1 }, max));
	BOOST_CHECK_EQUAL(max, 9);
}

BOOST_AUTO_TEST_CASE(FindMinValueInIntVector)
{
	int min;
	BOOST_CHECK(FindMax(vector<int>{ 9, 0, -2, 6, 4, 8 }, min,
		[](int const& a, int const& b){ return a > b; }));

	BOOST_CHECK_EQUAL(min, -2);
}

BOOST_AUTO_TEST_CASE(FindTheHighestSportsmen)
{
	vector<Sportsman> const& sportsmen = {
			{ "Kolya", 190, 75 },
			{ "Dima", 185, 80 },
			{ "Sasha", 180, 95 }
	};

	{
		Sportsman tallestSportsman;

		BOOST_CHECK(FindMax(sportsmen, tallestSportsman,
			[](Sportsman const& a, Sportsman const& b){ return a.height < b.height; }));

		BOOST_CHECK_EQUAL(tallestSportsman.name, "Kolya");
	}
}
BOOST_AUTO_TEST_CASE(FindTheHeavySportsmen)
{
	vector<Sportsman> const& sportsmen = {
			{ "Serezha", 190, 85 },
			{ "Andrey", 195, 100 },
			{ "Igor", 180, 90 }
	};

	{
		Sportsman heaviestSportsman;

		BOOST_CHECK(FindMax(sportsmen, heaviestSportsman,
			[](Sportsman const& a, Sportsman const& b){ return a.weight < b.weight; }));

		BOOST_CHECK_EQUAL(heaviestSportsman.name, "Andrey");
	}
}