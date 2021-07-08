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

	std::wstring to_wstring() { return StringConverter::StringToWide(std::to_string(height) + "x" + std::to_string(width)); };

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
	std::wstring type			= L"NONE";
	std::wstring PhysMaterial	= L"NONE";

	std::wstring Preview		= L"NONE";

	std::wstring Diffuse		= L"NONE";
	std::wstring NMap			= L"NONE";
	std::wstring Specular		= L"NONE";
	std::wstring Height			= L"NONE";
	std::wstring Alpha			= L"NONE";
	std::wstring Illumination	= L"NONE";

	IMGResolution mRes;
public:
	void setPhysMaterial(_Inout_ std::wstring string)		{ PhysMaterial = string; };
	void setMaterialPath(_Inout_ std::wstring string)		{ path = string; };
	void setMaterialName(_Inout_ std::wstring string)		{ name = string; };
	void setMaterialType(_Inout_ std::wstring string)		{ type = string; };
	void setResolution(_In_ uint height, _In_ uint width)	{ mRes.setImgResolution(height, width); };
	void setMetrialPreview(_Inout_ std::wstring string)		{ Preview = string; };

	void setDiffuse(_Inout_ std::wstring string)		{ Diffuse = string; };
	void setNMap(_Inout_ std::wstring string)			{ NMap = string; };
	void setHeight(_Inout_ std::wstring string)			{ Height = string; };
	void setSpecular(_Inout_ std::wstring string)		{ Specular = string; };
	void setAlpha(_Inout_ std::wstring string)			{ Alpha = string; };
	void setIllumination(_Inout_ std::wstring string)	{ Illumination = string; };


	std::wstring getMaterialName()		{ return name; };
	std::wstring getMaterialPath()		{ return path; };
	std::wstring getPhysMaterial()		{ return PhysMaterial; };
	std::wstring getMaterialType()		{ return type; };
	std::wstring getMaterialRes()		{ return mRes.to_wstring(); };
	std::wstring getMaterialPreview()	{ return Preview; };

	std::wstring getDiffuse()		{ return Diffuse; };
	std::wstring getNMap()			{ return NMap; };
	std::wstring getSpecular()		{ return Specular; };
	std::wstring getHeight()		{ return Height; };
	std::wstring getAlpha()			{ return Alpha; };
	std::wstring getIllumination()	{ return Illumination; };
};

