#pragma once

#include <wincodec.h> // WIC codec header for decoding image from file

#include "StringConverter.h"

#pragma comment (lib, "windowscodecs")

class IMGReader
{
	IWICFormatConverter* wConverter;

	UINT BitHeight;
	UINT BitWidth;

	IMGReader() {};
public:
	IMGReader(LPCWSTR path) { load(path); };
	~IMGReader() { wConverter->Release(); };

	void load(LPCWSTR path);

	UINT getBitmapHeight()	{ return BitHeight; };
	UINT getBitmapWidth()	{ return BitWidth; };

	HBITMAP IWICBitmapToHBITMAP();
};

