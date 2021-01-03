#include "MaterialHandler.h"

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
	case 5:
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
