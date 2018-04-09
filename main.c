#include <windows.h>

#define IDT_TIMER 123

typedef struct APPSTRUCT{
    HANDLE heap;
    HINSTANCE instance;
    struct DEBUGSTRUCT{
        HANDLE stdIn;
        HANDLE stdOut;
        HANDLE stdErr;
    } debug;
    struct GUISTRUCT{
        HICON iconNone;
        HICON iconUp;
        HICON iconDown;
        HICON iconBoth;
        HWND hiddenWindow;
        HWND mainWindow;
        HWND stat;
        HWND frame;
        BOOL isDragging;
        POINT dragCursorOffset;
        NOTIFYICONDATA notifyIcon;
        char labelText[1024];
    } gui;
    struct STATSTRUCT{
        DWORD bytesDown;
        DWORD bytesUp;
        struct STATSAMPLE{
            DWORD bytesDown;
            DWORD bytesUp;
        } samples[2];
        struct STATSAMPLE* lastSample;
        char perfBuf[10 * 1024];
    } stat;
}*APPSTRUCT;

APPSTRUCT AppStruct;

void initAppStruct(){
    HANDLE thisHeap = GetProcessHeap();
    AppStruct = (APPSTRUCT)HeapAlloc(thisHeap, 0, sizeof(struct APPSTRUCT));
    ZeroMemory(AppStruct, sizeof(struct APPSTRUCT));
    AppStruct->heap = thisHeap;

    AppStruct->instance = (HINSTANCE)GetModuleHandle(NULL);
}

#include "memory.c"
//#include "debug.c" // enable this if you want to use log(strMsg) or alert(strMsg)
#include "ethstat.c"
#include "gui.c"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    // dummy function to let TCC generate a win32 instead of console application
    // we use the real entry point instead (_winstart)
}

int _winstart(void){
    // run at idle priority
    SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);

    // init some modules
    initAppStruct();

    initGui();

    // first sample
    // after the second sample the stats are valid
    // the stats resulting from this sample are never shown
    statUpdate();

    // create timer for stats
    SetTimer(AppStruct->gui.mainWindow, IDT_TIMER, 1000, NULL);

    // main message loop
    doGuiMessageLoop();

    // cleanup on exit
    KillTimer(AppStruct->gui.mainWindow, IDT_TIMER);

    ExitProcess(0);
}
