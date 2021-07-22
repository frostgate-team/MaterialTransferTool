#include "TextureHandler.h"

#include <codecvt>
#include <regex>
#include <thread>

#include "StringConverter.h"
#include "MTTErrorLogger.h"

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

void TextureHandler::TextureUpscale(HPLMaterial& mat)
{
	std::vector<std::wstring> upscale_list{
	(mat.getDiffuse() != L"NONE") ? (mat.getFileDirectory() + mat.getDiffuse()) : L"NONE",
	(mat.getNMap() != L"NONE") ? (mat.getFileDirectory() + mat.getNMap()) : L"NONE",
	(mat.getAlpha() != L"NONE") ? (mat.getFileDirectory() + mat.getAlpha()) : L"NONE",
	(mat.getIllumination() != L"NONE") ? (mat.getFileDirectory() + mat.getIllumination()) : L"NONE"
	};

	Magick::Image img;
	IMGResolution resolution;
	for (uint i{}; i < upscale_list.size(); i++)
	{
		if (upscale_list[i] == L"NONE") { break; };
		img.read(StringConverter::WideToString(upscale_list[i]));
		resolution.setImgResolution(img.columns() * 2, img.rows() * 2);
		img.adaptiveResize(resolution.to_string());
		
		img.write(StringConverter::WideToString(upscale_list[i]));
	}
}

MATERIAL_TYPES TextureHandler::autoDetectFlags(HPLMaterial& mat)
{
	std::smatch reg_match;
	std::string converted_str = StringConverter::WideToString(mat.getMaterialType());

	if (std::regex_search(converted_str, reg_match, std::regex("Metal|metal")))
	{
		return METAL;
	}
	if (std::regex_search(converted_str, reg_match, std::regex("Rock|rock")))
	{
		return ROCK;
	}
	if (std::regex_search(converted_str, reg_match, std::regex("Wood|wood")))
	{
		return WOOD;
	}
	if (std::regex_search(converted_str, reg_match, std::regex("Organic|organic")))
	{
		return ORGANIC;
	}
	return DEFAULT;
}

void TextureHandler::MakeSpecularFromDiffuse(HPLMaterial& mat, const MATERIAL_TYPES flags)
{
	if (mat.getDiffuse() == L"NONE") { return; };

	Magick::Image img_specular(StringConverter::WideToString(mat.getFileDirectory() + mat.getDiffuse()));
	img_specular.colorSpace(Magick::GRAYColorspace);

	switch (flags)
	{
	case 0: // Default
		img_specular.level(DEFAULT_BLACK_C, DEFAULT_WHITE_C, 0.4); // {material_flag, material_flag, gamma}
		break;
	case 1: // Rock
		img_specular.level(ROCK_BLACK_C, ROCK_WHITE_C, 0.4);
		break;
	case 2: // Wood
		img_specular.level(WOOD_BLACK_C, WOOD_WHITE_C, 0.4);
		break;
	case 3: // Organic
		img_specular.level(ORGANIC_BLACK_C, ORGANIC_WHITE_C, 0.4);
		break;
	case 4: // Metal
		img_specular.level(METAL_BLACK_C, METAL_WHITE_C, 0.4);
		break;
	}

	img_specular.write(StringConverter::WideToString( mat.getFileDirectory() + mat.getSpecular()));
}