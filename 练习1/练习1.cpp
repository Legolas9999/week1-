#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main() {

	cv::Mat M1 = imread("bn.jpg");
	namedWindow("Ô­Í¼Ïñ", CV_WINDOW_NORMAL);
	imshow("Ô­Í¼Ïñ", M1);
	int height = M1.rows;
	int width = M1.cols;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (M1.at<Vec3b>(j, i)[0] + M1.at<Vec3b>(j, i)[1] + M1.at<Vec3b>(j, i)[2]) / 3;
			M1.at<Vec3b>(j, i)[0] = average;
			M1.at<Vec3b>(j, i)[1] = average;
			M1.at<Vec3b>(j, i)[2] = average;
		}
	}
	namedWindow("Æ½¾ùÍ¼Ïñ", CV_WINDOW_NORMAL);
	imshow("Æ½¾ùÍ¼Ïñ", M1);

	//------------------------------Á·Ï°2--------------------------------------------
	cv::Mat M2 = imread("bn.jpg", 0);
	namedWindow("»Ò¶ÈÍ¼", CV_WINDOW_NORMAL);
	imshow("»Ò¶ÈÍ¼", M2);


	//------------------------Á·Ï°3------------------------------------------
	uchar threshold = 150;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (M1.at<Vec3b>(j, i)[0] + M1.at<Vec3b>(j, i)[1] + M1.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold)
				average = 255;
			else
				average = 0;
			M1.at<Vec3b>(j, i)[0] = average;
			M1.at<Vec3b>(j, i)[1] = average;
			M1.at<Vec3b>(j, i)[2] = average;
		}
	}
	namedWindow("ãÐÖµÍ¼Ïñ", CV_WINDOW_NORMAL);
	imshow("ãÐÖµÍ¼Ïñ", M1);


	//---------------------------Á·Ï°4--------------------------------------
	cv::Mat srcMat = imread("bn.jpg");
	cv::Mat deepMat;
	cv::Mat shallowMat;
	srcMat.copyTo(deepMat);
	shallowMat = srcMat;
	uchar threshold2 = 50;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold2)
				average = 255;
			else
				average = 0;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
		}
	}
	namedWindow("Ç³¸´ÖÆ", CV_WINDOW_NORMAL);
	imshow("Ç³¸´ÖÆ", shallowMat);
	namedWindow("Éî¸´ÖÆ", CV_WINDOW_NORMAL);
	imshow("Éî¸´ÖÆ", deepMat);














	waitKey(0);
}