#pragma once

#include <Magick++.h>

#include "StringConverter.h"

/*typedef enum
{
	DEFAULT		= 0,
	ROCK		= 1,
	WOOD		= 2,	
	ORGANIC		= 3,
	METAL		= 4,
}MATERIAL_TYPES;*/

class TextureHandler
{
public:
	//static void MakeSpecularFromDiffuse(std::wstring path, const MATERIAL_TYPES flags);
	static void TextureUpscale(std::wstring path);
};

