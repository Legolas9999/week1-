#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main() {

	cv::Mat M1 = imread("bn.jpg");
	namedWindow("ԭͼ��", CV_WINDOW_NORMAL);
	imshow("ԭͼ��", M1);
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
	namedWindow("ƽ��ͼ��", CV_WINDOW_NORMAL);
	imshow("ƽ��ͼ��", M1);

	//------------------------------��ϰ2--------------------------------------------
	cv::Mat M2 = imread("bn.jpg", 0);
	namedWindow("�Ҷ�ͼ", CV_WINDOW_NORMAL);
	imshow("�Ҷ�ͼ", M2);


	//------------------------��ϰ3------------------------------------------
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
	namedWindow("��ֵͼ��", CV_WINDOW_NORMAL);
	imshow("��ֵͼ��", M1);


	//---------------------------��ϰ4--------------------------------------
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
	namedWindow("ǳ����", CV_WINDOW_NORMAL);
	imshow("ǳ����", shallowMat);
	namedWindow("���", CV_WINDOW_NORMAL);
	imshow("���", deepMat);














	waitKey(0);
}