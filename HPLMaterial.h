#pragma once

#include <ostream>

#include "StringConverter.h"

typedef unsigned int uint;

class IMGResolution
{
private:
	uint height	= NULL;
	uint width	= NULL;
public:
	IMGResolution() : height(0), width(0) {};
	IMGResolution(uint img_height, uint img_width) : height(img_height), width(img_width) {};
	~IMGResolution() {};

	void setImgResolution(_Inout_ uint height, _Inout_ uint width);
	void clear();

	uint getHeight()	{ return height; };
	uint getWidth()		{ return width; };

	friend std::ostream& operator << (std::ostream& out, IMGResolution& res)
	{
		out << res.height << "x" << res.width;
		return out;
	}
};

class HPLMaterial
{
private:
	std::wstring name			= L"NONE";
	std::wstring path			= L"NONE";
	std::wstring PhysMaterial	= L"NONE";

	std::wstring Deffuse		= L"NONE";
	std::wstring NMap			= L"NONE";
	std::wstring Specular		= L"NONE";
	std::wstring Height			= L"NONE";
	std::wstring Alpha			= L"NONE";
	std::wstring Illumination	= L"NONE";

	std::wstring type			= L"NONE";

	bool use_alpha				= false;

	IMGResolution mRes;
public:
	void read(_In_z_ std::wstring path);


	void setDeffuse(_Inout_ std::wstring string)		{ Deffuse = string; };
	void setNMap(_Inout_ std::wstring string)			{ NMap = string; };
	void setSpecular(_Inout_ std::wstring string)		{ Specular = string; };
	void setHeight(_Inout_ std::wstring string)			{ Height = string; };
	void setAlpha(_Inout_ std::wstring string)			{ Alpha = string; };
	void setIllumination(_Inout_ std::wstring string)	{ Illumination = string; };


	std::wstring getMaterialName()	{ return name; };
	std::wstring getMaterialPath()	{ return path; };
	std::wstring getPhysMaterial()	{ return PhysMaterial; };

	std::wstring getDeffuse()		{ return Deffuse; };
	std::wstring getNMap()			{ return NMap; };
	std::wstring getSpecular()		{ return Specular; };
	std::wstring getHeight()		{ return Height; };
	std::wstring getAlpha()			{ return Alpha; };
	std::wstring getIllumination()	{ return Illumination; };
};

