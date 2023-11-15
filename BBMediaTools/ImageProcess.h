#pragma once
#include <iostream>


class CImageProcess
{
public:
	CImageProcess();
	~CImageProcess();

public:
	bool openImage(std::string filePath);
	bool createViewWindow(HWND hWnd);
};

