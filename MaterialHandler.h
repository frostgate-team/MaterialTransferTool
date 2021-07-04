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
	/// <summary>
	/// Parse stringstream text
	/// </summary>
	void parse();

	string PhysMaterial = "NONE";
	string Diffuse = "NONE";
	string NMap = "NONE";
	string Specular = "NONE";
	string Height = "NONE";
	string Alpha = "NONE";
	string Illumination = "NONE";

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
	/// Getting diffuse map path
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
	/// Getting alpha map location
	/// </summary>
	string getAlphaLocation();
	/// <summary>
	/// Getting illumination map location
	/// </summary>
	string getIlluminationLocation();
	/// <summary>
	/// Clear the entire stringstream content
	/// </summary>
	void clearTextStream();
	/// <summary>
	/// Write log file
	/// </summary>
	/// <param name="path"></param>
	/// <param name="res"></param>
	void writeLog(string path, string res);
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
