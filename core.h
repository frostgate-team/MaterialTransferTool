#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#pragma region Material_type_flags

enum MATERIAL_TYPES
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
};

#pragma endregion

class MatReader
{
protected:
	string name;
	string path;
public:
	MatReader(){}
	//explicit MatReader(string file_name) { name = file_name; }
	~MatReader() { name = ""; path = ""; }
	
	/// <summary>
	/// Read all lines in .mat document by string
	/// </summary>
	void ReadAllLines(string mat_file);
	/// <summary>
	/// Decrypts dds file to raw bytes
	/// </summary>
	void ReadDdsTexture(string path);

	/// <summary>
	/// Getting PhysicsMaterial property
	/// </summary>
	string getPhysMaterial(string mat_file);
	/// <summary>
	/// Getting texture file path
	/// </summary>
	string getMapLocation(string mat_file, string map_name);
	/// <summary>
	/// Getting material type
	/// </summary>
	string getMaterialType(string mat_file);
}; 

class TextureMap
{
private:

public:
	/* 
	@param path - path to image file
	@param flags - enum type of material
	*/
	void MakeSpecularFromDiffuse(string path, int flags);
	void UpscaleDiffuseMap(string path);
};

void parse(string str);