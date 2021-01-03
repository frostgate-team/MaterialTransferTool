#include "MaterialHandler.h"

#pragma region ConfigurationDefines

#define DEFAULT_BLACK_C 5000
#define DEFAULT_WHITE_C 30000

#define ROCK_BLACK_C 15000
#define ROCK_WHITE_C 40000

#define WOOD_BLACK_C 15000
#define WOOD_WHITE_C 40000

#define WATER_BLACK_C
#define WATER_WHITE_C

#define ORGANIC_BLACK_C
#define ORGANIC_WHITE_C

#define METAL_BLACK_C
#define METAL_WHITE_C

#define DIRT_BLACK_C
#define DIRT_WHITE_C

#define DUST_BLACK_C
#define DUST_WHITE_C

#define SILENT_BLACK_C
#define SILENT_WHITE_C

#define GLASS_BLACK_C
#define GLASS_WHITE_C

#pragma endregion

void TextureMap::MakeSpecularFromDiffuse(string path, const MATERIAL_TYPES flags)
{
	Image upscaleImage(path);
	upscaleImage.colorSpace(GRAYColorspace);
	switch (flags)
	{
	case 1: // Default
		upscaleImage.level(DEFAULT_BLACK_C, DEFAULT_WHITE_C, 0.4); // {material_flag, material_flag, gamma}
		break;
	case 3: // Wood
		upscaleImage.level(WOOD_BLACK_C, WOOD_WHITE_C, 0.4);
		break;
	}
	for (size_t i{}; i < 4; i++)
		path.pop_back();

	upscaleImage.write(path+"_spec.dds"); 
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
