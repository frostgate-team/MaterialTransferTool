#include "MaterialHandler.h"

#include <codecvt>

#pragma region ConfigurationDefines

#define DEFAULT_BLACK_C 5000
#define DEFAULT_WHITE_C 30000

#define ROCK_BLACK_C 13000
#define ROCK_WHITE_C 40000

#define WOOD_BLACK_C 15000
#define WOOD_WHITE_C 40000

#define ORGANIC_BLACK_C 5000
#define ORGANIC_WHITE_C 16000

#define METAL_BLACK_C 3000
#define METAL_WHITE_C 35000

#pragma endregion

LPCWSTR TextureMap::stdStrignToLPCWSTR(string str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wide = converter.from_bytes(str);
	return wide.c_str();
}

void TextureMap::MakeSpecularFromDiffuse(string path, const MATERIAL_TYPES flags)
{
	Image spec(path);
	spec.colorSpace(GRAYColorspace);
	switch (flags)
	{
	case 1: // Default
		spec.level(DEFAULT_BLACK_C, DEFAULT_WHITE_C, 0.4); // {material_flag, material_flag, gamma}
		break;
	case 2: // Rock
		spec.level(ROCK_BLACK_C, ROCK_WHITE_C, 0.4);
		break;
	case 3: // Wood
		spec.level(WOOD_BLACK_C, WOOD_WHITE_C, 0.4);
		break;
	case 4: // Organic
		spec.level(ORGANIC_BLACK_C, ORGANIC_WHITE_C, 0.4);
		break;
	case 5: // Metal
		spec.level(METAL_BLACK_C, METAL_WHITE_C, 0.4);
		break;
	}
	for (size_t i{}; i < 4; i++)
		path.pop_back();

	spec.write(path+"_spec.dds");
}

void TextureMap::UpscaleDiffuseMap(string path)
{
	Image img(path);
	string x = std::to_string(img.columns() * 2);
	string y = std::to_string(img.rows() * 2);
	img.adaptiveResize(x+"x"+y);
	img.interpolate();
	img.write(path);
}

void TextureMap::createHiddenLinkImage(string path) // {..\..\..\ex\ex1\ex.dds}
{
	Image img(path); // opens = {..\..\..\ex\ex1\ex.dds}
	stringstream ssline; 
	string str_segment;
	vector<string> seglist;
	xRes = img.columns();
	yRes = img.rows();

	for (size_t i{}; i < 4; i++) // delete las 4 symbols = {..\..\..\ex\ex1\ex}
		path.pop_back();
	ssline << path; // appends {..\..\..\ex\ex1\ex} to stringstream
	while (getline(ssline, str_segment, '\\')) // parse by '\' char = ["..","..","..","ex","ex1","ex"]
	{
		seglist.push_back(str_segment);
	}															//												  *
	uint16_t seglength = seglist[seglist.size() - 1].length(); // finds name element ["..","..","..","ex","ex1","ex"]
	seglist[seglist.size() - 1] = "hid_" + seglist[seglist.size() - 1] + ".png"; // gives rename last element ["..","..","..","ex","ex1","~ex.jpg"]
	for (size_t i{}; i < seglength; i++) // delete old name = {..\..\..\ex\ex1\}
		path.pop_back();
	str_segment = path + seglist[seglist.size() - 1]; // str_segment = {..\..\..\ex\ex1\~ex.jpg}
	hashpath = str_segment; // hashpath = "..\..\..\ex\ex1\~ex.jpg"
	img.write(str_segment); // write ..\..\..\ex\ex1\~ex.jpg
	BOOL result = SetFileAttributes(stdStrignToLPCWSTR(str_segment), FILE_ATTRIBUTE_HIDDEN); // just hide the ~ex.jpg file
}

string TextureMap::getHashPath()
{
	return hashpath; // return "..\..\..\ex\ex1\~ex.jpg"
}

string TextureMap::getImageRes()
{
	return std::to_string(xRes)+"x"+std::to_string(yRes);
}
