/*
* This is the images format decoding class
*/
#pragma once

#include <wincodec.h> // WIC codec header for decoding image from file
#include <atlcomcli.h>

#include "StringConverter.h"

#pragma comment (lib, "windowscodecs")

class IMGReader
{
	CComPtr<IWICImagingFactory>		m_pImagingFactory;
	CComPtr<IWICBitmapDecoder>		m_pBitmapDecoder;
	CComPtr<IWICBitmapFrameDecode>	m_pFrameDecoder;
	CComPtr<IWICFormatConverter>	m_pConverter;

	UINT BitHeight;
	UINT BitWidth;

	BOOLEAN pathExist(LPCWSTR path);

	IMGReader() {};
public:
	IMGReader(LPCWSTR path) { load(path); };
	~IMGReader() { SafeRelease(&m_pConverter); };

	void load(LPCWSTR path);
	void clean();
	template <class T> void SafeRelease(T** ppT)
	{
		if (*ppT)
		{
			(*ppT)->Release();
			*ppT = NULL;
		}
	}

	UINT getBitmapHeight()	{ return BitHeight; };
	UINT getBitmapWidth()	{ return BitWidth; };

	HBITMAP IWICBitmapToHBITMAP();
};
