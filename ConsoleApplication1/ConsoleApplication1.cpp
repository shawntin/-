// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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

