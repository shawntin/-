// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <Windows.h>
extern "C"
{
	BOOL StartHook(int msecond);
	BOOL StopHook();
};
#pragma comment(lib, "../Release/KeyBoardHook.lib")
int main()
{
	StartHook(20);
    return 0;
}

