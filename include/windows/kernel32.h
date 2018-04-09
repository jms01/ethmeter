#ifndef _WINKERNEL32_
#define _WINKERNEL32_

void WINAPI ExitProcess(UINT uExitCode);

void WINAPI RtlZeroMemory(PVOID Destination, SIZE_T Length);
void WINAPI RtlMoveMemory(PVOID Destination, const void* Source, SIZE_T Length);
void WINAPI RtlFillMemory(PVOID Destination, SIZE_T Length, UCHAR Fill);

#define ZeroMemory RtlZeroMemory
#define MoveMemory RtlMoveMemory
#define FillMemory RtlFillMemory

HANDLE WINAPI GetCurrentProcess(VOID);

#define DEBUG_PROCESS 0x1
#define DEBUG_ONLY_THIS_PROCESS 0x2
#define CREATE_SUSPENDED 0x4
#define DETACHED_PROCESS 0x8
#define CREATE_NEW_CONSOLE 0x10
#define NORMAL_PRIORITY_CLASS 0x20
#define IDLE_PRIORITY_CLASS 0x40
#define HIGH_PRIORITY_CLASS 0x80
#define REALTIME_PRIORITY_CLASS 0x100
#define CREATE_NEW_PROCESS_GROUP 0x200
#define CREATE_UNICODE_ENVIRONMENT 0x400
#define CREATE_SEPARATE_WOW_VDM 0x800
#define CREATE_SHARED_WOW_VDM 0x1000
#define CREATE_FORCEDOS 0x2000
#define BELOW_NORMAL_PRIORITY_CLASS 0x4000
#define ABOVE_NORMAL_PRIORITY_CLASS 0x8000
#define STACK_SIZE_PARAM_IS_A_RESERVATION 0x10000

BOOL WINAPI SetPriorityClass(HANDLE hProcess,DWORD dwPriorityClass);

HANDLE WINAPI HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
HANDLE WINAPI GetProcessHeap();

LPVOID WINAPI HeapAlloc(
	HANDLE hHeap,
	DWORD dwFlags,
	SIZE_T dwBytes
);

BOOL WINAPI HeapFree(
	HANDLE hHeap,
	DWORD dwFlags,
	LPVOID lpMem
);

#define GetModuleHandle GetModuleHandleA
HMODULE WINAPI GetModuleHandleA(
	LPCTSTR lpModuleName
);

#define strcat lstrcatA
LPTSTR WINAPI lstrcatA(LPTSTR lpString1,LPTSTR lpString2);

#define strcmp lstrcmpA
int WINAPI lstrcmpA(LPCTSTR lpString1,LPCTSTR lpString2);

#define strcmpi lstrcmpiA
int WINAPI lstrcmpiA(LPCTSTR lpString1,LPCTSTR lpString2);

#define strcpy lstrcpyA
LPTSTR WINAPI lstrcpyA(LPTSTR lpString1,LPTSTR lpString2);

#define strcpyn lstrcpynA
LPTSTR WINAPI lstrcpynA(LPTSTR lpString1,LPCTSTR lpString2,int iMaxLength);

#define strlen lstrlenA
int WINAPI lstrlenA(LPCTSTR lpString);

#define CTRL_C_EVENT 0
#define CTRL_BREAK_EVENT 1
#define CTRL_CLOSE_EVENT 2

#define CTRL_LOGOFF_EVENT 5
#define CTRL_SHUTDOWN_EVENT 6

BOOL WINAPI AllocConsole(void);
BOOL WINAPI FreeConsole(void);

#define STD_INPUT_HANDLE (DWORD)(0xfffffff6)
#define STD_OUTPUT_HANDLE (DWORD)(0xfffffff5)
#define STD_ERROR_HANDLE (DWORD)(0xfffffff4)
HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
HWND WINAPI GetConsoleWindow(void);

#define WriteConsole WriteConsoleA
BOOL WINAPI WriteConsoleA(
	HANDLE hConsoleOutput,
	PVOID lpBuffer,
	DWORD nNumberOfCharsToWrite,
	LPDWORD lpNumberOfCharsWritten,
	LPVOID lpReserved
);

#define SetConsoleTitle SetConsoleTitleA
BOOL WINAPI SetConsoleTitleA(LPCTSTR lpConsoleTitle);

typedef BOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);
BOOL WINAPI SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine, BOOL Add);

#endif
