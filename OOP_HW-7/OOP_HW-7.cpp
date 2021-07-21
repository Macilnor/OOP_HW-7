#include <iostream>
#include "Date.h"
#include "YandexParser.h"


int main()
{
	unique_ptr<Date> today = make_unique<Date>(20, 7, 2021);
	unique_ptr<Date> date;
	cout << "Day: " << today->getDay() << endl;
	cout << "Month: " << today->getMonth() << endl;
	cout << "Year: " << today->getYear() << endl;
	cout << *today << endl;
	date = move(today);
	
	if (today)
		cout << "Today is not empty" << endl;
	else 
		cout << "Today is empty" << endl;

	if (date)
		cout << "Date is not empty" << endl;
	else
		cout << "Date is empty" << endl;

	unique_ptr<Date> date1 = make_unique<Date>(20, 7, 2021);
	unique_ptr<Date> date2 = make_unique<Date>(25, 8, 2021);
	cout << *(compareDate(date1, date2)) << endl;
	swapDate(date1, date2);
	cout << *date1 << "  " << *date2 << endl;

	YandexParser par("Yandex.htm");
	cout << par.parse("USD") << "\t" << par.parse("EUR") << endl;
}
