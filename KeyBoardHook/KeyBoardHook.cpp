#include <Windows.h>

HINSTANCE g_hInstance = NULL;
HHOOK g_hHook = NULL;
int ms = 0;

BOOL APIENTRY DllMain( HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved )
{
	g_hInstance = (HINSTANCE)hDllHandle;
	return TRUE;
}

LRESULT CALLBACK KeyBoardProc(int code, WPARAM wParam, LPARAM lParam)
{
	static DWORD k;
	static DWORD pre = 0;
	if (code >= HC_ACTION)
	{
		if (pre&& pre == ((KBDLLHOOKSTRUCT *)lParam)->vkCode&&::GetTickCount()-k<ms)
			return TRUE;
		else if(wParam==WM_KEYUP)
		{
			pre = ((KBDLLHOOKSTRUCT *)lParam)->vkCode;
			k = ::GetTickCount();
		}
	}
	return CallNextHookEx(g_hHook, code, wParam, lParam);
}

extern "C"
{
	__declspec(dllexport) BOOL StartHook(int msecond)
	{
		ms = msecond;
		if (g_hHook)
		{
			return FALSE;
		}
		g_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyBoardProc, g_hInstance, 0);
		if (g_hHook)
		{
			return TRUE;
		}
		return FALSE;
	}

	__declspec(dllexport) BOOL StopHook()
	{
		if (UnhookWindowsHookEx(g_hHook))
		{
			g_hHook = NULL;
			return TRUE;
		}
		return FALSE;
	}
};