#include "core.h"

void MatReader::ReadAllLines(string data)
{
	ifstream infile(data);
	string str;
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			getline(infile, str);
			cout << str << endl;
		}
	}
}
