#include "TextureHandler.h"

void TextureHandler::TextureUpscale(std::wstring path)
{
	Magick::Image img(StringConverter::WideToString(path));

}