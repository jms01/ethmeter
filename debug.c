
void log(LPSTR argMessage, ...);
int alert(LPSTR argMessage, ...);

void createConsoleWindow();

void ensureConsoleWindow(){
    if (GetConsoleWindow() == NULL) {
        createConsoleWindow();
    }
}

BOOL WINAPI consoleCtrlHandler(DWORD argType);

void createConsoleWindow(){
    if (GetConsoleWindow() == NULL) {
        AllocConsole();
    }

    SetConsoleCtrlHandler(&consoleCtrlHandler, TRUE);

    SetConsoleTitle("Debug console");

    // disable the console close button
    // pressing this button terminates the whole process
    // use CTRL-C to close the console
    HANDLE sysMenu = GetSystemMenu(GetConsoleWindow(), FALSE);
    EnableMenuItem(sysMenu, SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);

    struct DEBUGSTRUCT* debug = &AppStruct->debug;
    debug->stdIn = GetStdHandle(STD_INPUT_HANDLE);
    debug->stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    debug->stdErr = GetStdHandle(STD_ERROR_HANDLE);

    log("Debug console initialized... (use CTRL-C to close the console)\n");
}

BOOL WINAPI consoleCtrlHandler(DWORD argType){
    BOOL isHandled = FALSE;
    switch(argType){
        case CTRL_C_EVENT:
            log("Closing debug console.\n");
            FreeConsole();
            isHandled = TRUE;
            break;
    }
    return isHandled;
}

void log(LPSTR argMessage, ...){
    ensureConsoleWindow();
    char* theMessage = (char*)malloc(4 * 1024);
    int strLength = wvsprintf(theMessage, argMessage, ((PVOID)&argMessage + sizeof(argMessage)));
    DWORD outLength;
        WriteConsole(AppStruct->debug.stdOut, theMessage, strLength, &outLength, NULL);
    free(theMessage);
}

int alert(LPSTR argMessage, ...){
    char* theMessage = (char*)malloc(4 * 1024);
    wvsprintf(theMessage, argMessage, ((PVOID)&argMessage + sizeof(argMessage)));
        int theButton = MessageBox(NULL, theMessage, "Debug Message", MB_OK | MB_ICONINFORMATION);
    free(theMessage);
    return theButton;
}
