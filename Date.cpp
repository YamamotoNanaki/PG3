#include "Date.h"
#include <iostream>
#include <ctime>

#ifdef _MSC_VER
#define DISABLE_C4996 __pragma(warning(push)) __pragma(warning(disable:4996))
#define ENABLE_C4996  __pragma(warning(pop))
#else
#define DISABLE_C4996
#define ENABLE_C4996
#endif

using namespace std;

Date Date::today;

//‰½ŒŽ‰½“ú‚Å•\Ž¦
void Date::Draw()
{
	cout << year << "”N" << month << "ŒŽ" << day << "“ú" << endl;
}

void Date::Set()
{
	year = today.year;
	cout << "ŒŽ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl << endl;
	cin >> month;
	while (month == 0 || month > 12)
	{
		cout << "–³Œø‚È“ü—Í‚Å‚·" << endl;
		cout << "1‚©‚ç12‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl << endl;
		cin >> month;
	}
	unsigned int dayEnd = 31;
	if (today.month > month)
	{
		year++;
	}
	if (month < 8 && month % 2 == 0)
	{
		dayEnd = 30;
		if (month == 2)
		{
			if (year % 4 == 0)
			{
				dayEnd = 29;
			}
			else
			{
				dayEnd = 28;
			}
		}
	}
	else if (month > 8 && month % 2 == 1)
	{
		dayEnd = 30;
	}
	cout << "“ú‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl << endl;
	cin >> day;
	while (day == 0 || day > dayEnd)
	{
		cout << "–³Œø‚È“ü—Í‚Å‚·" << endl;
		cout << "1‚©‚ç" << dayEnd << "‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl << endl;
		cin >> day;
	}
	if (month == today.month && day < today.day)
	{
		year++;
	}
}

int Date::DaysDifference()
{
	int y = static_cast<int>(year - today.year);
	int t = 0;
	if (y == 0)
	{
		switch (month)
		{
		case 12:
			t += 30;
		case 11:
			t += 31;
		case 10:
			t += 30;
		case 9:
			t += 31;
		case 8:
			t += 31;
		case 7:
			t += 30;
		case 6:
			t += 31;
		case 5:
			t += 30;
		case 4:
			t += 31;
		case 3:
			t += 28;
			if (year % 4 == 0)
			{
				t++;
			}
		case 2:
			t += 31;
			break;
		}
		switch (today.month)
		{
		case 12:
			t -= 30;
		case 11:
			t -= 31;
		case 10:
			t -= 30;
		case 9:
			t -= 31;
		case 8:
			t -= 31;
		case 7:
			t -= 30;
		case 6:
			t -= 31;
		case 5:
			t -= 30;
		case 4:
			t -= 31;
		case 3:
			t -= 28;
			if (year % 4 == 0)
			{
				t--;
			}
		case 2:
			t -= 31;
			break;
		}

		t += day - today.day;
		return t;
	}
	else if (y > 0)
	{
		t += 365;
		if ((year - 1) % 4 == 0)t++;
		switch (month)
		{
		case 12:
			t += 30;
		case 11:
			t += 31;
		case 10:
			t += 30;
		case 9:
			t += 31;
		case 8:
			t += 31;
		case 7:
			t += 30;
		case 6:
			t += 31;
		case 5:
			t += 30;
		case 4:
			t += 31;
		case 3:
			t += 28;
			if (year % 4 == 0)
			{
				t++;
			}
		case 2:
			t += 31;
			break;
		}
		switch (today.month)
		{
		case 12:
			t -= 30;
		case 11:
			t -= 31;
		case 10:
			t -= 30;
		case 9:
			t -= 31;
		case 8:
			t -= 31;
		case 7:
			t -= 30;
		case 6:
			t -= 31;
		case 5:
			t -= 30;
		case 4:
			t -= 31;
		case 3:
			t -= 28;
			if (today.year % 4 == 0)
			{
				t--;
			}
		case 2:
			t -= 31;
			break;
		}


		t += day - today.day;
		return t;
	}
	else
	{
		switch (month)
		{
		case 12:
			t += 30;
		case 11:
			t += 31;
		case 10:
			t += 30;
		case 9:
			t += 31;
		case 8:
			t += 31;
		case 7:
			t += 30;
		case 6:
			t += 31;
		case 5:
			t += 30;
		case 4:
			t += 31;
		case 3:
			t += 28;
			if (year % 4 == 0)
			{
				t++;
			}
		case 2:
			t += 31;
			break;
		}
		t -= 365;
		if ((year - 1) % 4 == 0)t--;
		switch (today.month)
		{
		case 12:
			t -= 30;
		case 11:
			t -= 31;
		case 10:
			t -= 30;
		case 9:
			t -= 31;
		case 8:
			t -= 31;
		case 7:
			t -= 30;
		case 6:
			t -= 31;
		case 5:
			t -= 30;
		case 4:
			t -= 31;
		case 3:
			t -= 28;
			if (today.year % 4 == 0)
			{
				t--;
			}
		case 2:
			t -= 31;
			break;
		}

		t += day - today.day;
		return t;
	}
}

void Date::SetToday()
{
	std::time_t t = std::time(nullptr);
	DISABLE_C4996
		std::tm* now = std::localtime(&t);
	ENABLE_C4996
		today.day = now->tm_mday;
	today.month = now->tm_mon + 1;
	today.year = now->tm_year + 1900;
}
