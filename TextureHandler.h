/*
* This is the TextureHandler module
* It use to operate with textures 
*/
#pragma once

#include <Magick++.h>

#include "HPLMaterial.h"

typedef enum
{
	DEFAULT,
	ROCK,		
	WOOD,			
	ORGANIC,		
	METAL		
}MATERIAL_TYPES;

class TextureHandler
{
public:
	static MATERIAL_TYPES autoDetectFlags(HPLMaterial& mat);
	static void MakeSpecularFromDiffuse(HPLMaterial& mat, const MATERIAL_TYPES flags);
	static void TextureUpscale(HPLMaterial& mat);
};

