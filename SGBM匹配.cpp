#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{

    Mat img1 = imread("E:\\c_test\\StereoVision\\teddy-png-2\\teddy\\im2.png",0);
    Mat img2 = imread("E:\\c_test\\StereoVision\\teddy-png-2\\teddy\\im6.png",0);
	Ptr<cv::StereoSGBM> sgbm = StereoSGBM::create(0,64,9,8*1*9*9,32*1*9*9,1,63,10,100,32);

    Mat disp, disp8;
    int64 t = getTickCount();
	sgbm->compute(img1, img2, disp);
    t = getTickCount() - t;

    cout<<"Time elapsed:"<<t*1000/getTickFrequency()<<endl;//��λ��ms
    disp.convertTo(disp8, CV_8U, 255/(64*16.));

    namedWindow("left", 1);
	imshow("left",img1);
    namedWindow("right", 1);
    imshow("right",img2);
    namedWindow("disparity", 1);
    imshow("disparity", disp8);
    waitKey();
    imwrite("sgbm_disparity.png", disp8);   
    return 0;
}