#include "Core.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/dnn_superres.hpp>

using namespace cv;
using namespace dnn;
using namespace dnn_superres;

#pragma region ConfigurationDefines

#define DEFAULT_BLACK_C 10
#define DEFAULT_WHITE_C 1.35

#define ROCK_BLACK_C
#define ROCK_WHITE_C

#define WOOD_BLACK_C
#define WOOD_WHITE_C

#define WATER_BLACK_C
#define WATER_WHITE_C

#define ORGANIC_BLACK_C
#define ORGANIC_WHITE_C

#define METAL_BLACK_C
#define METAL_WHITE_C

#define DIRT_BLACK_C
#define DIRT_WHITE_C

#define DUST_BLACK_C
#define DUST_WHITE_C

#define SILENT_BLACK_C
#define SILENT_WHITE_C

#define GLASS_BLACK_C
#define GLASS_WHITE_C

#pragma endregion


void TextureMap::MakeSpecularFromDiffuse(string path, int flags)
{
	Mat OrigMat = imread(path, IMREAD_COLOR);

	Mat SpecMat;
	cvtColor(OrigMat, SpecMat, CV_16F);
	Mat InverseSpecMat;
	Mat Sa;
	InverseSpecMat = 255 - SpecMat;

	switch (flags)
	{
	case DEFAULT:
		Sa = 255 - ((InverseSpecMat / SpecMat)) * DEFAULT_BLACK_C;
		InverseSpecMat = (Sa - InverseSpecMat) * DEFAULT_WHITE_C;
		break;
	case ROCK:
		break;
	}

	imwrite("Test.png", InverseSpecMat);

	imshow("Specular_Image", InverseSpecMat);

	int k = waitKey(0); // Wait for a keystroke in the window
}

void TextureMap::UpscaleDiffuseMap(string path)
{
	DnnSuperResImpl rs;
	Mat origTexture = imread(path, IMREAD_COLOR);

	string modelPath = "pre-trained_models/FSRCNN_x2.pb";
	rs.readModel(modelPath);

	rs.setModel("fsrcnn", 2);

	Mat img_new;
	rs.upsample(origTexture, img_new);
	imwrite("upscale.png", img_new);
	imshow("Upscaled_image", img_new);
}
