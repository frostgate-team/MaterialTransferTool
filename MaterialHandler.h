#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>

#include <Magick++.h>

using namespace Magick;
using namespace std;

class MatReader
{
protected:
	/// <summary>
	/// Material name
	/// </summary>
	string name;
	/// <summary>
	/// material path
	/// </summary>
	string path;

	stringstream text;
	const stringstream::pos_type start{ text.tellg() };

	bool ofile = false;

	string PhysicsMaterial;
	string Diffuse;
	string NMap;
	string Specular;
public:
	MatReader() {};
	~MatReader() { name = ""; path = ""; }

	/// <summary>
	/// Read all lines in .mat document by string
	/// </summary>
	void ReadAllLines(string file_path);
	/// <summary>
	/// Getting PhysicsMaterial property
	/// </summary>
	string getPhysMaterial();
	/// <summary>
	/// Getting texture file path
	/// </summary>
	string getDiffuseLocation();
	string getNMapLocation();
	string getSpecularLocation();
	string getHeightLocation();
};

#pragma once

#pragma region Material_type_flags

typedef enum
{
	DEFAULT = 1,
	ROCK = 2,
	WOOD = 3,
	WATER = 4,
	ORGANIC = 5,
	METAL = 6,
	DIRT = 7,
	DUST = 8,
	SILENT = 9,
	GLASS = 10
}MATERIAL_TYPES;

#pragma endregion
/// <summary>
/// Basic texture handling class
/// </summary>
class TextureMap
{
private:

public:
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
	void UpscaleDiffuseMap(string path, int flags);
};
