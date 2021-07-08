#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <Windows.h>
#include <regex>

#include <Magick++.h>

using namespace Magick;
using namespace std;

#pragma region Material_type_flags

typedef enum
{
	DEFAULT = 1,
	ROCK = 2,
	WOOD = 3,
	ORGANIC = 4,
	METAL = 5,
}MATERIAL_TYPES;

#pragma endregion
/// <summary>
/// Basic texture handling class 
/// </summary>
class TextureMap
{
private:
	// Converts std::string to LPCWSTR
	LPCWSTR stdStrignToLPCWSTR(string str);
	// Hash image path here
	string hashpath;
	size_t xRes = 0, yRes = 0; // Image resolution
public:
	/// <summary>
	/// Gets hash path
	/// </summary>
	string getHashPath();
	/// <summary>
	/// Gets image resolution
	/// </summary>
	string getImageRes();
	/// <summary>
	/// Makes specular map from Diffuse map
	/// </summary>
	/// <param name="path">- file path</param>
	/// <param name="flags">- enum material types</param>
	void MakeSpecularFromDiffuse(string path, const MATERIAL_TYPES flags);
	/// <summary>
	/// Upscale image to double
	/// </summary>
	/// <param name="path">- file path</param>
	/// <param name="flags">- enum material types</param>
	void TextureUpscale(string path);
	/// <summary>
	/// Creates Hidden image to show it on pictureBox
	/// </summary>
	void createHiddenLinkImage(string path);
};
