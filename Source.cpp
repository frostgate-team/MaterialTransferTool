#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "dds.hpp"
#include "core.h"

#include <math.h>

using namespace cv;

void main(void)
{
	//system("mode 650");
	MatReader material;

	string data = "Material/chasm_bridge.mat";
	string imgPath = "Material/chasm_bridge.png"; // Material debug path

	Mat OrigMat = imread(imgPath, IMREAD_COLOR);
	
	Mat SpecMat;
	cvtColor(OrigMat, SpecMat, CV_16F);
	Mat InverseSpecMat;
	Mat Sa;
	//bitwise_not(SpecMat, InverseSpecMat);
	//cvtColor(InverseSpecMat, InverseSpecMat, COLOR_RGB2RGBA);
	InverseSpecMat = 255 - SpecMat;
	Sa = 255-((InverseSpecMat / SpecMat))*10;
	InverseSpecMat = (Sa - InverseSpecMat)*1.35;
	//addWeighted(SpecMat, 0.8, InverseSpecMat, 0.3, 0.4, InverseSpecMat);

	imwrite("Test.png", InverseSpecMat);

	imshow("Specular_Image", InverseSpecMat);

	material.ReadAllLines(data);
	material.getPhysMaterial(data);

	int k = waitKey(0); // Wait for a keystroke in the window
}