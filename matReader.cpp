#include "MaterialHandler.h"

void MatReader::clearTextStream()
{
	text.clear();
	text.str("");
}

void MatReader::writeLog(string path, string res)
{
	ofstream logfile(getDiffuseLocation());
}

void MatReader::ReadAllLines(string mat_file)
{
	ifstream infile(mat_file, ios::in | ios::binary);
	if (infile.is_open())
	{
		text << infile.rdbuf();
		infile.close();
	}
	else { throw exception("[ERROR] file does not exist or corrupted"); };
	parse();
}

void MatReader::parse()
{
	string line;
	smatch match;
	while (text)
	{
		getline(text, line);
		if (regex_search(line, match, regex("<Main")))
		{
			regex_search(line, match, regex("PhysicsMaterial=\"[A-z0-9|.|/|:|\\|-|+| ]+"));
			this->PhysMaterial = match.str().erase(0, 17);
		}
		else if (regex_search(line, match, regex("<Diffuse")))
		{
			regex_search(line, match, regex("File=\"[A-z0-9|.|/|:|\\|-|+| ]+"));
			string reg = match.str().erase(0, 6);
			regex_search(reg, match, regex("[A-z0-9]+\.[A-z0-9]+$"));
			this->Diffuse = match.str();
		}
		else if (regex_search(line, match, regex("<NMap")))
		{
			regex_search(line, match, regex("File=\"[A-z0-9|.|/|:|\\|-|+| ]+"));
			string reg = match.str().erase(0, 6);
			regex_search(reg, match, regex("[A-z0-9]+\.[A-z0-9]+$"));
			this->NMap = match.str();
		}
		else if (regex_search(line, match, regex("<Specular")))
		{
			regex_search(line, match, regex("File=\"[A-z0-9|.|/|:|\\|-|+| ]+"));
			string reg = match.str().erase(0, 6);
			regex_search(reg, match, regex("[A-z0-9]+\.[A-z0-9]+$"));
			this->Specular = match.str();
		}
		else if (regex_search(line, match, regex("<Height")))
		{
			regex_search(line, match, regex("File=\"[A-z0-9|.|/|:|\\|-|+| ]+"));
			string reg = match.str().erase(0, 6);
			regex_search(reg, match, regex("[A-z0-9]+\.[A-z0-9]+$"));
			this->Height = match.str();
		}
		else if (regex_search(line, match, regex("<Alpha")))
		{
			regex_search(line, match, regex("File=\"[A-z0-9|.|/|:|\\|-|+| ]+"));
			string reg = match.str().erase(0, 6);
			regex_search(reg, match, regex("[A-z0-9]+\.[A-z0-9]+$"));
			this->Alpha = match.str();
		}
		else if (regex_search(line, match, regex("<Illumination")))
		{
			regex_search(line, match, regex("File=\"[A-z0-9|.|/|:|\\|-|+| ]+"));
			string reg = match.str().erase(0, 6);
			regex_search(reg, match, regex("[A-z0-9]+\.[A-z0-9]+$"));
			this->Illumination = match.str();
		}
	}
}

string MatReader::getPhysMaterial()
{
	return this->PhysMaterial;
}

string MatReader::getDiffuseLocation()
{
	return this->Diffuse;
}

string MatReader::getNMapLocation()
{
	return this->NMap;
}

string MatReader::getHeightLocation()
{
	return this->Height;
}

string MatReader::getSpecularLocation()
{
	return this->Specular;
}

string MatReader::getAlphaLocation()
{
	return this->Alpha;
}

string MatReader::getIlluminationLocation()
{
	return this->Illumination;
}
