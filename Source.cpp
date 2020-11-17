#include "dds.hpp"
#include "core.h"

void main(void)
{
	//system("mode 650");
	MatReader material;
	TextureMap map;

	string data = "Material/chasm_bridge.mat";
	string imgPath = "Material/dungeonbase_floor.png"; // Material debug path

	material.ReadAllLines(data);
	material.getPhysMaterial(data);

	map.MakeSpecularFromDiffuse(imgPath, DEFAULT);
}