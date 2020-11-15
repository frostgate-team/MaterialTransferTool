#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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

void parse(string str);