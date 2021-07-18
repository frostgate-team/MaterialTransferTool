#pragma once

#include <Magick++.h>

#include "HPLMaterial.h"

/*typedef enum
{
	DEFAULT,
	ROCK,		
	WOOD,			
	ORGANIC,		
	METAL		
}MATERIAL_TYPES;*/

class TextureHandler
{
public:
	//static void MakeSpecularFromDiffuse(HPLMaterial& mat, const MATERIAL_TYPES flags);
	static void TextureUpscale(HPLMaterial& mat);
};

