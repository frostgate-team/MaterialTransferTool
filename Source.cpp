#include "core.h"

int main(int argc, char **argv)
{
	MatReader material;
	TextureMap map;

	material.ReadAllLines("Material/example/example.mat");
	try
	{
		/*map.UpscaleDiffuseMap(material.getDiffuseLocation());
		map.UpscaleDiffuseMap(material.getNMapLocation());
		map.MakeSpecularFromDiffuse(material.getDiffuseLocation(), DEFAULT);*/
		map.MakeSpecularFromDiffuse("Material/example/pipes.dds", METAL);
	}
	catch (const std::exception& ex)
	{
		cout << "ERROR: " << ex.what() << endl;
	}

	return 0;
}