#include "Date.h"

Date::Date() : m_day(0), m_month(0), m_year(0)
{
}

Date::Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year)
{
}

Date::~Date()
{

}

void Date::setDay(int day)
{
	m_day = day;
}

void Date::setMonth(int month)
{
	m_month = month;
}

void Date::setYear(int year)
{
	m_year = year;
}

int Date::getDay() const
{
	return m_day;
}

int Date::getMonth() const
{
	return m_month;
}

int Date::getYear() const
{
	return m_year;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.m_day << "." << date.m_month << "." << date.m_year;
	return os;
}

unique_ptr<Date>& compareDate(unique_ptr<Date>& date1, unique_ptr<Date>& date2)
{
	if (date1->getYear() > date2->getYear())
		return date1;
	else if (date1->getYear() < date2->getYear())
		return date2;
	else
	{
		if (date1->getMonth() > date2->getMonth())
			return date1;
		else if (date1->getMonth() < date2->getMonth())
			return date2;
		else
		{
			if (date1->getDay() > date2->getDay())
				return date1;
			else if (date1->getDay() < date2->getDay())
				return date2;
			else
				return date1;
		}
	}
}

void swapDate(unique_ptr<Date>& date1, unique_ptr<Date>& date2)
{
	date1.swap(date2);
}
