#include "MaterialHandler.h"

void MatReader::clearTextStream()
{
	text.clear();
	text.str("");
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

string MatReader::getMaterialType()
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
		if (seglist[i - 1] == " Type=")
			return seglist[i];
	}
	throw exception("There is no MaterialType configuration in this file!");
}

void MatReader::textStreamDebug()
{
	cout << text.str();
}

/******************************************\
|**************CRUTCH ZONE*****************|
\******************************************/

//TODO: REMOVE ALL THE CRUTCHES

string MatReader::getDiffuseLocation()
{
	text.clear();
	text.seekg(start);
	string line;
	vector<string> seglist;
	bool crutch = false;
	if (ofile == false)
		throw exception("File not open");
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
		if (i == seglist.size()-1)
			return "NONE";
	}
}

string MatReader::getNMapLocation()
{
	text.clear();
	text.seekg(start);
	string line;
	vector<string> seglist;
	bool crutch = false;
	if (ofile == false)
		throw exception("File not open");
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
		if (i == seglist.size()-1)
			return "NONE";
	}
}

string MatReader::getSpecularLocation()
{
	text.clear();
	text.seekg(start);
	string line;
	vector<string> seglist;
	bool crutch = false;
	if (ofile == false)
		throw exception("File not open");
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
		if (i == seglist.size()-1)
			return "NONE";
	}
}

string MatReader::getHeightLocation()
{
	text.clear();
	text.seekg(start);
	string line;
	vector<string> seglist;
	bool crutch = false;
	if (ofile == false)
		throw exception("File not open");
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
		if (i == seglist.size()-1)
			return "NONE";
	}
}
