#include "dds.hpp"
#include "core.h"

void main(void)
{
	//system("mode 650");
	MatReader material;
	TextureMap map;

	string data = "Material/chasm_bridge.mat";
	string imgPath = "upscale.png"; // Material debug path
	string scalePath = "Material/Neural/gigantic.png";

	material.ReadAllLines(data);
	material.getPhysMaterial(data);

	map.MakeSpecularFromDiffuse(imgPath, DEFAULT);
	//map.UpscaleDiffuseMap(scalePath);
}