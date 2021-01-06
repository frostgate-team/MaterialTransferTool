#include "MaterialHandler.h"

void MatReader::clearTextStream()
{
	text.clear();
	text.str("");
}

string MatReader::getAbsoluteFilePath(string filepath1, string filepath2)
{
	string str_segment;
	stringstream ssline;

	for (size_t i = filepath1.length() - 1; filepath1[i] != '\\'; i--)
		filepath1.pop_back();

#pragma region filePath2
	vector<string> seglist;
	for (size_t i{}; i < filepath2.length(); i++)
		if (filepath2[i] == '\\')
			filepath2[i] = '/';
	ssline << filepath2;
	while (getline(ssline, str_segment, '/'))
	{
		seglist.push_back(str_segment);
	}
	return filepath1 + seglist[seglist.size() - 1];
#pragma endregion


}

void MatReader::writeLog(string path, string res)
{
	string name;
	ofstream logfile();
}

void MatReader::ReadAllLines(string mat_file)
{
	ifstream infile(mat_file);
	string str;
	if (infile.is_open())
	{
		ofile = true;
		while (!infile.eof())
		{
			getline(infile, str);
			text << str + "\n";
		}
	}
	else
		throw exception("[ERROR] file does not exist or corrupted");
}

string MatReader::getPhysMaterial()
{
	text.clear();
	text.seekg(start);
	string line;
	vector<string> seglist;
	if (ofile == false)
		throw exception("File not open");
	while (getline(text, line, '"'))
	{
		if (line == " />")
			break;
		seglist.push_back(line);
	}
	for (size_t i = 1; i < seglist.size(); i++)
	{
		if (seglist[i - 1] == " PhysicsMaterial=")
			return seglist[i];
		if (i == seglist.size()-1)
			return "NONE";
	}
}

string MatReader::textStreamDebug()
{
	return text.str();
}

/******************************************\
|**************CRUTCH ZONE*****************|
\******************************************/

//TODO: REMOVE ALL THE CRUTCHES

string MatReader::getDiffuseLocation()
{
	text.clear();
	text.seekg(start);
	stringstream newline;
	string line;
	vector<string> seglist;
	bool crutch = false;
	if (ofile == false)
		throw exception("File not open");
	while (getline(text, line, '"'))
	{
		newline << line;
		while (getline(newline, line, ' '))
			seglist.push_back(line);
		newline.clear();
		newline.str("");
	}
	for (size_t i{}; i < seglist.size(); i++)
	{
		if (seglist[i] == "<Diffuse")
			crutch = true;
		if (crutch == true & seglist[i - 1] == "File=")
			return seglist[i];
		if (i == seglist.size() - 1)
			return "NONE";
	}
}

string MatReader::getNMapLocation()
{
	text.clear();
	text.seekg(start);
	stringstream newline;
	string line;
	vector<string> seglist;
	bool crutch = false;
	if (ofile == false)
		throw exception("File not open");
	while (getline(text, line, '"'))
	{
		newline << line;
		while (getline(newline, line, ' '))
			seglist.push_back(line);
		newline.clear();
		newline.str("");
	}
	for (size_t i{}; i < seglist.size(); i++)
	{
		if (seglist[i] == "<NMap")
			crutch = true;
		if (crutch == true & seglist[i - 1] == "File=")
			return seglist[i];
		if (i == seglist.size() - 1)
			return "NONE";
	}
}

string MatReader::getSpecularLocation()
{
	text.clear();
	text.seekg(start);
	stringstream newline;
	string line;
	vector<string> seglist;
	bool crutch = false;
	if (ofile == false)
		throw exception("File not open");
	while (getline(text, line, '"'))
	{
		newline << line;
		while (getline(newline, line, ' '))
			seglist.push_back(line);
		newline.clear();
		newline.str("");
	}
	for (size_t i{}; i < seglist.size(); i++)
	{
		if (seglist[i] == "<Specular")
			crutch = true;
		if (crutch == true & seglist[i - 1] == "File=")
			return seglist[i];
		if (i == seglist.size() - 1)
			return "NONE";
	}
}

string MatReader::getHeightLocation()
{
	text.clear();
	text.seekg(start);
	stringstream newline;
	string line;
	vector<string> seglist;
	bool crutch = false;
	if (ofile == false)
		throw exception("File not open");
	while (getline(text, line, '"'))
	{
		newline << line;
		while (getline(newline, line, ' '))
			seglist.push_back(line);
		newline.clear();
		newline.str("");
	}
	for (size_t i{}; i < seglist.size(); i++)
	{
		if (seglist[i] == "<Height")
			crutch = true;
		if (crutch == true & seglist[i - 1] == "File=")
			return seglist[i];
		if (i == seglist.size() - 1)
			return "NONE";
	}
}

string MatReader::getAlphaLocation()
{
	text.clear();
	text.seekg(start);
	stringstream newline;
	string line;
	vector<string> seglist;
	bool crutch = false;
	if (ofile == false)
		throw exception("File not open");
	while (getline(text, line, '"'))
	{
		newline << line;
		while (getline(newline, line, ' '))
			seglist.push_back(line);
		newline.clear();
		newline.str("");
	}
	for (size_t i{}; i < seglist.size(); i++)
	{
		if (seglist[i] == "<Alpha")
			crutch = true;
		if (crutch == true & seglist[i - 1] == "File=")
			return seglist[i];
		if (i == seglist.size() - 1)
			return "NONE";
	}
}
