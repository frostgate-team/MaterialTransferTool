#include "TextureHandler.h"

#include "StringConverter.h"
#include "MTTErrorLogger.h"

void TextureHandler::TextureUpscale(HPLMaterial& mat)
{
	std::vector<std::wstring> upscale_list{
	(mat.getDiffuse() != L"NONE") ? (mat.getFileDirectory() + mat.getDiffuse()) : L"NONE",
	(mat.getNMap() != L"NONE") ? (mat.getFileDirectory() + mat.getNMap()) : L"NONE",
	(mat.getAlpha() != L"NONE") ? (mat.getFileDirectory() + mat.getAlpha()) : L"NONE",
	(mat.getIllumination() != L"NONE") ? (mat.getFileDirectory() + mat.getIllumination()) : L"NONE"
	};

	Magick::Image img;
	IMGResolution resolution;
	for (uint i{}; i < upscale_list.size(); i++)
	{
		if (upscale_list[i] == L"NONE") { break; };
		img.read(StringConverter::WideToString(upscale_list[i]));
		resolution.setImgResolution(img.columns() * 2, img.rows() * 2);
		img.adaptiveResize(resolution.to_string());
		img.write(StringConverter::WideToString(upscale_list[i]));
	}
}