#include "pch.h"
#include "ImageProcess.h"
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;
using namespace std;


#ifdef _DEBUG
#pragma comment(lib, "opencv_core454d")
#pragma comment(lib, "opencv_highgui454d")
#pragma comment(lib, "opencv_imgcodecs454d")
#else
#pragma comment(lib, "opencv_core454")
#pragma comment(lib, "opencv_highgui454")
#pragma comment(lib, "opencv_imgcodecs454")
#endif


constexpr auto IMGPROCESS_WINDOWNAME = "IMGPROCESS_WINDOW";

CImageProcess::CImageProcess()
{

}

CImageProcess::~CImageProcess()
{

}

bool CImageProcess::openImage(std::string filepath)
{
   Mat img = imread(filepath, IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << filepath << std::endl;
        return false;
    }
   // imshow(IMGPROCESS_WINDOWNAME, img);
   
    CvMat cvimg = cvMat(img);
    cvShowImage(IMGPROCESS_WINDOWNAME, &cvimg);
     
    return true;
}

bool CImageProcess::createViewWindow(HWND hwndParent)
{
    cvNamedWindow(IMGPROCESS_WINDOWNAME, CV_WINDOW_NORMAL,hwndParent);
    return true;
}