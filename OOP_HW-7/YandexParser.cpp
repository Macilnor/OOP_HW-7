#include "YandexParser.h"

YandexParser::YandexParser()
	: m_fname(""),
	m_skey("<span class=\'inline-stocks__value_inner\'>"),
	m_nkey("</span>")
{
}

YandexParser::YandexParser(string fname)
	: m_fname(fname),
	m_skey("<span class=\'inline-stocks__value_inner\'>"),
	m_nkey("</span>")
{
}

YandexParser::YandexParser(string fname, const string skey, const string nkey)
	: m_fname(fname),
	m_skey(skey),
	m_nkey(nkey)
{
}

YandexParser::~YandexParser()
{
}

string YandexParser::parse(string currency) const
{
	string out;
	ifstream file(m_fname);
	if (!file)
	{
		cerr << "File Error" << endl;
		return out;
	}
	while (file)
	{
		string s_buf;
		getline(file, s_buf);
		if (s_buf.find(currency) != string::npos)
		{
			size_t cur_found = s_buf.find(currency);
			size_t start = 0;
			size_t end = 0;
			if (s_buf.find(m_skey, cur_found) != string::npos)
				start = s_buf.find(m_skey, cur_found) + m_skey.length();
			else
			{
				cerr << "Start key not found" << endl;
				break;
			}
			if (s_buf.find(m_nkey, start) != string::npos)
				end = s_buf.find(m_nkey, start);
			else
			{
				cerr << "End key not found" << endl;
				break;
			}
			out += currency + " ";
			for (size_t i = start; i < end; i++)
			{
				out += s_buf[i];
			}
			break;
		}
	}

	return out;
}
