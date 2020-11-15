#include "core.h"

void MatReader::ReadAllLines(string mat_file)
{
	ifstream infile(mat_file);
	string str;
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			getline(infile, str);
			cout << str << endl;
		}
	}
	else
		cout << "[ERROR] file does not exist or corrupted"<<endl;
}

string MatReader::getPhysMaterial(string mat_file)
{
	ifstream infile(mat_file);
	string str, mat = "PhysicsMaterial=";
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			getline(infile, str);
			parse(str);
		}
	}
	return "aa";
}

void parse(string str)
{
	string line = str;

	// Vector of string to save tokens 
	vector<string> tokens;

	stringstream check1(line);
	string intermediate;

	while (getline(check1, intermediate, ' '))
	{
		tokens.push_back(intermediate);
	}

	/*for (int i = 0; i < tokens.size(); i++)
		cout << tokens[i] << '\n';*/
}