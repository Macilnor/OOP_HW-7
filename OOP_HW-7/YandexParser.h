#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class YandexParser
{
private:
	string m_fname;
	const string m_skey;
	const string m_nkey;
public:
	YandexParser();
	YandexParser(string fname);
	YandexParser(string fname, string skey, string nkey);
	~YandexParser();

	string parse(string currency) const;
};

