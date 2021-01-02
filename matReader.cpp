#include "MaterialHandler.h"

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
	while (getline(text, line, '"'))
	{
		seglist.push_back(line);
	}
	for (size_t i = 1; i < seglist.size(); i++)
	{
		if (seglist[i - 1] == " PhysicsMaterial=")
			return seglist[i];
	}
}

string MatReader::getDiffuseLocation()
{
	text.clear();
	text.seekg(start);
	string line;
	vector<string> seglist;
	bool crutch = false;
	while (getline(text, line, '"'))
	{
		seglist.push_back(line);
	}
	for (size_t i = 1; i < seglist.size(); i++)
	{
		if (seglist[i] == (" />\n    <TextureUnits>\n        <Diffuse MipMaps="))
			crutch = true;
		if (seglist[i - 1] == " File=" & crutch == true)
			return seglist[i];
	}
}

/******************************************\
|**************CRUTCH ZONE*****************|
\******************************************/

//TODO: REMOVE CRUTCHES

string MatReader::getNMapLocation()
{
	text.clear();
	text.seekg(start);
	string line;
	vector<string> seglist;
	bool crutch = false;
	while (getline(text, line, '"'))
	{
		seglist.push_back(line);
	}
	for (size_t i = 1; i < seglist.size(); i++)
	{
		if (seglist[i] == (" />\n        <NMap MipMaps="))
			crutch = true;
		if (seglist[i - 1] == " File=" & crutch == true)
			return seglist[i];
	}
}

string MatReader::getSpecularLocation()
{
	text.clear();
	text.seekg(start);
	string line;
	vector<string> seglist;
	bool crutch = false;
	while (getline(text, line, '"'))
	{
		seglist.push_back(line);
	}
	for (size_t i = 1; i < seglist.size(); i++)
	{
		if (seglist[i] == (" />\n        <Specular MipMaps="))
			crutch = true;
		if (seglist[i - 1] == " File=" & crutch == true)
			return seglist[i];
	}
}

string MatReader::getHeightLocation()
{
	text.clear();
	text.seekg(start);
	string line;
	vector<string> seglist;
	bool crutch = false;
	while (getline(text, line, '"'))
	{
		seglist.push_back(line);
	}
	for (size_t i = 1; i < seglist.size(); i++)
	{
		if (seglist[i] == (" />\n        <Height MipMaps="))
			crutch = true;
		if (seglist[i - 1] == " File=" & crutch == true)
			return seglist[i];
	}
}
