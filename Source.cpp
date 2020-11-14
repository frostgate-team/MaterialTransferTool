#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "dds.hpp"
#include "core.h"

using namespace cv;

void main(void)
{
	system("mode 650");
	MatReader material;

	string data = "Material/chasm_bridge.mat";
	string imgPath = "Material/dungeonbase_wall_tileable.png"; // Material debug path

	Mat OrigMat = imread(imgPath, IMREAD_COLOR);
	
	Mat SpecMat;
	cvtColor(OrigMat, SpecMat, CV_16F);
	Mat InverseSpecMat;
	bitwise_not(SpecMat, InverseSpecMat);
	cvtColor(InverseSpecMat, InverseSpecMat, COLOR_RGB2RGBA);
	SpecMat = InverseSpecMat / SpecMat;

	//SpecMat.convertTo(SpecMat, CV_32FC3);
	//InverseSpecMat.convertTo(InverseSpecMat, CV_32FC3);


	imshow("Specular_Image", SpecMat);

	material.ReadAllLines(data);

	int k = waitKey(0); // Wait for a keystroke in the window
}