#ifndef __KEYBOARDHOOK_INTERFACE__
#define __KEYBOARDHOOK_INTERFACE__

extern "C"
{
	BOOL StartHook(int msecond);
	BOOL StopHook();
};

#endif