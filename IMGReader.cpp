#include "IMGReader.h"
#include "MTTErrorLogger.h"

#include <vector>

void IMGReader::load(LPCWSTR path)
{
	HRESULT hr;		// For checking errors

	// Craete WIC factory
	IWICImagingFactory* wicFactory = NULL;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory,	// CLS ID of the object making
		NULL,						// Not part of agregate 
		CLSCTX_INPROC_SERVER,		// DLL runs in the same process
		IID_IWICImagingFactory,		// Ref to interface that communicates with the object
		(LPVOID*)&wicFactory		// The pointer that'll contain factory
	);

	// Create decoder
	IWICBitmapDecoder* wicDecoder = NULL;
	hr = wicFactory->CreateDecoderFromFilename(
		path,							// Path to reading file
		NULL,							// No preferred vendor
		GENERIC_READ,					// Reading file
		WICDecodeMetadataCacheOnLoad,	// Cache on load 
		&wicDecoder						// Making decoder
	);

	// Read frame from the image
	IWICBitmapFrameDecode* wicFrame = NULL;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	//Create converter
	IWICFormatConverter* wicConverter = NULL;
	hr = wicFactory->CreateFormatConverter(&wicConverter);

	// Setup the converter
	hr = wicConverter->Initialize(
		wicFrame,						// Frame
		GUID_WICPixelFormat32bppPBGRA,	// Pixel format
		WICBitmapDitherTypeNone,		// Irrelevant
		NULL,							// No palette needed, irrelevant
		0.0,							// Alpha transparency % irrelevant
		WICBitmapPaletteTypeCustom		// Irrelevant
	);

	wicConverter->GetSize(&BitHeight, &BitWidth);

	wConverter = wicConverter;
}

HBITMAP IMGReader::IWICBitmapToHBITMAP()
{
	UINT height	= BitHeight;	// Bitmap height
	UINT width	= BitWidth;		// Bitmap width
	wConverter->GetSize(&width, &height);

	std::vector<BYTE> buffer(width * height * 4);
	wConverter->CopyPixels(0, width * 4, buffer.size(), buffer.data());

	HBITMAP bitmap = CreateBitmap(width, height, 1, 32, buffer.data()); // Create bitmap from IWICBitmap data

	return bitmap;
}
