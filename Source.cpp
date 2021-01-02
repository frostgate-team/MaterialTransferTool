#include "core.h"

int main(int argc, char **argv)
{
	MatReader material;
	TextureMap map;

	string data = "Material/chasm_bridge.mat";
	string imgPath = "Material/Neural/gigantic.png";

	map.UpscaleDiffuseMap(imgPath, DEFAULT);
	map.MakeSpecularFromDiffuse("upscale.dds", DEFAULT);

	material.ReadAllLines(data);
	cout << material.getPhysMaterial() << endl;
	cout << material.getDiffuseLocation() << endl;
	cout << material.getNMapLocation() << endl;
	cout << material.getSpecularLocation() << endl;
	cout << material.getHeightLocation() << endl;

	return 0;
}