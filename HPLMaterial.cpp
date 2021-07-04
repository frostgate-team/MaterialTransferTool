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

void HPLMaterial::read(_In_z_ std::wstring path)
{

}

#pragma endregion
