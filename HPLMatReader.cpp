#include "HPLMatReader.h"

#include <fstream>

std::wstring HPLMatReader::parseGeneralInfo(std::string regex, std::string line)
{
	uint rxSize	= 0;
	std::smatch reg_match;

	std::regex_search(line, reg_match, std::regex(regex));
	rxSize = static_cast<uint>(reg_match.str().size()) + 2;
	std::regex_search(line, reg_match, std::regex(regex+"=\"[A-z0-9|.|/|:|\\|-|+| ]+"));

	return StringConverter::StringToWide(reg_match.str().erase(0,rxSize));
}

std::wstring HPLMatReader::parseTextureUnits(std::string param, std::string line)
{
	uint rxSize = 0;
	std::smatch reg_match;

	std::regex_search(line, reg_match, std::regex(param));
	rxSize = static_cast<uint>(reg_match.str().size()) + 2;
	std::regex_search(line, reg_match, std::regex(param+"=\"[A-z0-9|.|/|:|\\|-|+| ]+"));
	if (param == "File") {
		line = reg_match.str().erase(0, rxSize);
		std::regex_search(line, reg_match, std::regex("[^\\|/]+.[A-z0-9]+$"));
		return StringConverter::StringToWide(reg_match.str());
	}

	return StringConverter::StringToWide(reg_match.str().erase(0, rxSize));
}

void HPLMatReader::read(_Inout_ HPLMaterial& mat, _In_ std::wstring path)
{
	std::ifstream matfile(path);
	std::string str_line;
	std::smatch match;

	while (std::getline(matfile, str_line))
	{
		if (std::regex_search(str_line, match, std::regex("<Main")))
		{
			mat.setPhysMaterial(parseGeneralInfo("PhysicsMaterial", str_line));
			mat.setMaterialType(parseGeneralInfo("Type", str_line));
		}
		if (std::regex_search(str_line, match, std::regex("<Diffuse")))
		{
			mat.setDiffuse(parseTextureUnits("File", str_line));
			mat.setMaterialName(mat.getDiffuse());
		}
		if (std::regex_search(str_line, match, std::regex("<NMap")))
		{
			mat.setNMap(parseTextureUnits("File", str_line));
		}
		if (std::regex_search(str_line, match, std::regex("<Specular")))
		{
			mat.setSpecular(parseTextureUnits("File", str_line));
		}
		if (std::regex_search(str_line, match, std::regex("<Height")))
		{
			mat.setHeight(parseTextureUnits("File", str_line));
		}
		if (std::regex_search(str_line, match, std::regex("<Alpha")))
		{
			mat.setAlpha(parseTextureUnits("File", str_line));
		}
		if (std::regex_search(str_line, match, std::regex("<Illumination")))
		{
			mat.setIllumination(parseTextureUnits("File", str_line));
		}
	}
}