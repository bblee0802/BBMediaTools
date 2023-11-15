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
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if (k == 's')
    {
        imwrite("starry_night.png", img);
    }
    
    return 0;
}

bool CImageProcess::createViewWindow(HWND hwndParent)
{
    cvNamedWindow("Window1", CV_WINDOW_NORMAL,(unsigned int)hwndParent);
    HWND hWnd = (HWND)cvGetWindowHandle("Window1");
    HWND hParent = ::GetParent(hWnd);
    ::ShowWindow(hParent, SW_HIDE);
}