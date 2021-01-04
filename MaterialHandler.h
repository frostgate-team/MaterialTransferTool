#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <Windows.h>

#include <Magick++.h>

using namespace Magick;
using namespace std;

class MatReader
{
protected:
	/// <summary>
	/// Stringstream from file
	/// </summary>
	stringstream text;
	/// <summary>
	/// Stringstream start position
	/// </summary>
	const stringstream::pos_type start{ text.tellg() };
	/// <returns> true if file is open</returns>
	bool ofile = false;

public:
	MatReader() {};
	~MatReader() {};

	/// <summary>
	/// Read all lines in .mat document by string
	/// </summary>
	void ReadAllLines(string file_path);
	/// <summary>
	/// Getting PhysicsMaterial property
	/// </summary>
	string getPhysMaterial();
	/// <summary>
	/// Getting diffuse file path
	/// </summary>
	string getDiffuseLocation();
	/// <summary>
	/// Getting normal map file path
	/// </summary>
	string getNMapLocation();
	/// <summary>
	/// Getting specular map file path
	/// </summary>
	string getSpecularLocation();
	/// <summary>
	/// Getting height map file path
	/// </summary>
	string getHeightLocation();
	/// <summary>
	/// Getting alpha map location from file
	/// </summary>
	string getAlphaLocation();
	/// <summary>
	/// Prints all stringstream content
	/// </summary>
	void textStreamDebug();
	/// <summary>
	/// Clear the entire stringstream content
	/// </summary>
	void clearTextStream();
	/// <summary>
	/// Gets absolute file path
	/// </summary>
	/// <param name="str">- CLI string</param>
	/// <param name="str2">- std::string path</param>
	string getAbsoluteFilePath(string str, string str2);
};

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

	string hashpath;
public:
	string getHashPath();
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
	void UpscaleDiffuseMap(string path);
	/// <summary>
	/// Creates Hidden image to show it on pictureBox
	/// </summary>
	void createHiddenLinkImage(string path);
};
