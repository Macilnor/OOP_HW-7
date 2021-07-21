#pragma once
#include <iostream>

using namespace std;

class Date
{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date();
	Date(int day, int month, int year);
	~Date();

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	friend ostream& operator<<(ostream& os, const Date& date);
};

unique_ptr<Date>& compareDate(unique_ptr<Date>& date1, unique_ptr<Date>& date2);
void swapDate(unique_ptr<Date>& date1, unique_ptr<Date>& date2);