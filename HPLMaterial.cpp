#include "HPLMaterial.h"

#pragma region IMGResolution

void IMGResolution::setImgResolution(_Inout_ uint height, _Inout_ uint width)
{
	this->height	= height;
	this->width		= width;
}

void IMGResolution::clear()
{
	this->height	= NULL;
	this->width		= NULL;
}

#pragma endregion

#include <sstream>

#pragma region HPLMaterial

void HPLMaterial::clean()
{
	this->name			= L"NONE";
	this->path			= L"NONE";
	this->directory		= L"NONE";
	this->type			= L"NONE";
	this->PhysMaterial	= L"NONE";

	this->Preview		= L"NONE";

	this->Diffuse		= L"NONE";
	this->NMap			= L"NONE";
	this->Specular		= L"NONE";
	this->Height		= L"NONE";
	this->Alpha			= L"NONE";
	this->Illumination	= L"NONE";

	this->mRes.setImgResolution(0,0);
}

#pragma endregion
