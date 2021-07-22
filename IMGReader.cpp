#include "IMGReader.h"
#include "MTTErrorLogger.h"

#include <filesystem>
#include <vector>

void IMGReader::load(LPCWSTR path)
{
	HRESULT hr;

	if (!pathExist(path)) { path = L"nodata.jpg"; }; // Check if image really exist in this derectory

	m_pImagingFactory	= NULL;
	m_pBitmapDecoder	= NULL;
	m_pFrameDecoder		= NULL;
	m_pConverter		= NULL;

	hr = CoCreateInstance(
		CLSID_WICImagingFactory,	// CLS ID of the object making
		NULL,						// Not part of agregate 
		CLSCTX_INPROC_SERVER,		// DLL runs in the same process
		IID_IWICImagingFactory,		// Ref to interface that communicates with the object
		(LPVOID*)&m_pImagingFactory	// The pointer that'll contain factory
	);

	hr = m_pImagingFactory->CreateDecoderFromFilename(
		path,							// Path to reading file
		NULL,							// No preferred vendor
		GENERIC_READ,					// Reading file
		WICDecodeMetadataCacheOnLoad,	// Cache on load 
		&m_pBitmapDecoder				// Making decoder
	);

	hr = m_pBitmapDecoder->GetFrame(0, &m_pFrameDecoder);

	hr = m_pImagingFactory->CreateFormatConverter(&m_pConverter);

	hr = m_pConverter->Initialize(
		m_pFrameDecoder,				// Frame
		GUID_WICPixelFormat32bppPBGRA,	// Pixel format
		WICBitmapDitherTypeNone,		// Irrelevant
		NULL,							// No palette needed, irrelevant
		0.0,							// Alpha transparency % irrelevant
		WICBitmapPaletteTypeCustom		// Irrelevant
	);

	this->m_pConverter->GetSize(&BitHeight, &BitWidth);
}

void IMGReader::clean()
{
	BitHeight = BitWidth = 0;

	SafeRelease(&m_pConverter);
	SafeRelease(&m_pFrameDecoder);
	SafeRelease(&m_pBitmapDecoder);
}

HBITMAP IMGReader::IWICBitmapToHBITMAP()
{
	UINT height	= BitHeight;	// Bitmap height
	UINT width	= BitWidth;		// Bitmap width
	m_pConverter->GetSize(&width, &height);

	std::vector<BYTE> buffer(width * height * 4);
	m_pConverter->CopyPixels(0, width * 4, buffer.size(), buffer.data());

	HBITMAP bitmap = CreateBitmap(width, height, 1, 32, buffer.data()); // Creating bitmap from IWICBitmap data

	return bitmap;
}

BOOLEAN IMGReader::pathExist(LPCWSTR path)
{
	if (std::filesystem::exists(path)) {
		return true;
	}
	return false;
}
