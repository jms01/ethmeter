
#define WM_NOTIFYICON (WM_USER + 0x139)
#define WM_RENDERSTAT (WM_USER + 0x42)

BOOL CALLBACK MainProc(HWND,UINT,WPARAM,LPARAM);
BOOL CALLBACK HiddenProc(HWND,UINT,WPARAM,LPARAM);

void initGui(){
    struct GUISTRUCT* gui = &AppStruct->gui;

    gui->iconNone = LoadImage(AppStruct->instance, "ICO_NONE", IMAGE_ICON, 16, 16, 0);
    gui->iconUp   = LoadImage(AppStruct->instance, "ICO_UP",   IMAGE_ICON, 16, 16, 0);
    gui->iconDown = LoadImage(AppStruct->instance, "ICO_DOWN", IMAGE_ICON, 16, 16, 0);
    gui->iconBoth = LoadImage(AppStruct->instance, "ICO_BOTH", IMAGE_ICON, 16, 16, 0);

    gui->hiddenWindow = CreateDialog(AppStruct->instance, "DLG_HIDDEN", 0, HiddenProc);
    gui->mainWindow = CreateDialog(AppStruct->instance, "DLG_ETHMETER", gui->hiddenWindow, MainProc);

    gui->stat = GetWindow(gui->mainWindow, GW_CHILD);
    gui->frame = GetWindow(gui->stat, GW_HWNDNEXT);

    SetWindowPos(gui->mainWindow, HWND_TOPMOST, 1720,20, 150,23, 0);

    NOTIFYICONDATA* notifyIcon = &gui->notifyIcon;
    notifyIcon->cbSize = sizeof(NOTIFYICONDATA);
    notifyIcon->hWnd = gui->mainWindow;
    notifyIcon->uCallbackMessage = WM_NOTIFYICON;
    notifyIcon->uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
    notifyIcon->hIcon = gui->iconNone;
    strcpy(notifyIcon->szTip, "EthMeter");

    Shell_NotifyIcon(NIM_ADD, notifyIcon);
}

void doGuiMessageLoop(){
    MSG msg;
    while (GetMessage(&msg, 0, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

BOOL CALLBACK resizeProc(HWND,UINT,WPARAM,LPARAM);
BOOL CALLBACK moveProc(HWND,UINT,WPARAM,LPARAM);
BOOL CALLBACK statProc(HWND,UINT,WPARAM,LPARAM);

BOOL CALLBACK HiddenProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam){
    return 0;
}

BOOL CALLBACK MainProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam){
    int result = 0;

    struct GUISTRUCT* gui = &AppStruct->gui;

    switch (msg) {
        case WM_DESTROY:
            Shell_NotifyIcon(NIM_DELETE, &gui->notifyIcon);
            PostQuitMessage(0);
            result = -1;
            break;
        case WM_CTLCOLORSTATIC:
            result = (int)GetStockObject(WHITE_BRUSH);
            break;
        case WM_COMMAND:
            if (HIWORD(wParam) == STN_DBLCLK) {
                PostMessage(gui->mainWindow, WM_DESTROY, 0, 0);
            }
            result = -1;
            break;
        case WM_NOTIFYICON:
            if(lParam == WM_LBUTTONDBLCLK) {
                PostMessage(gui->mainWindow, WM_DESTROY, 0, 0);
            }
            result = 0;
            break;
        default:
            if (result == 0) result = resizeProc(hWnd, msg, wParam, lParam);
            if (result == 0) result = moveProc(hWnd, msg, wParam, lParam);
            if (result == 0) result = statProc(hWnd, msg, wParam, lParam);
    }
    return result;
}

BOOL CALLBACK resizeProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam){
    int result = 0;

    RECT rc;

    struct GUISTRUCT* gui = &AppStruct->gui;

    switch (msg) {
        case WM_SIZE:
            GetClientRect(gui->mainWindow, &rc);
            MoveWindow(gui->stat, 1, 1, rc.right-2, rc.bottom-2, TRUE);
            MoveWindow(gui->frame, 0, 0, rc.right, rc.bottom, TRUE);
            RedrawWindow(gui->stat, NULL, NULL, RDW_INVALIDATE);
            result = -1;
            break;
    }

    return result;
}

BOOL CALLBACK moveProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam){
    int result = 0;

    RECT rc;
    POINT cur;

    struct GUISTRUCT* gui = &AppStruct->gui;

    switch (msg) {
        case WM_SETCURSOR:
            switch(HIWORD(lParam)){
                case WM_LBUTTONDOWN:
                    if ((HWND)wParam == gui->stat && !gui->isDragging) {
                        GetWindowRect(gui->mainWindow, &rc);
                        GetCursorPos(&gui->dragCursorOffset);
                        gui->dragCursorOffset.x = gui->dragCursorOffset.x - rc.left;
                        gui->dragCursorOffset.y = gui->dragCursorOffset.y - rc.top;

                        SetCapture(gui->mainWindow);
                        gui->isDragging = TRUE;

                        result = 0;
                    }
            }
            break;
        case WM_MOUSEMOVE:
            if (gui->isDragging) {
                GetCursorPos(&cur);
                SetWindowPos(
                    gui->mainWindow, HWND_TOPMOST,
                    cur.x - gui->dragCursorOffset.x,
                    cur.y - gui->dragCursorOffset.y,
                    0,0, SWP_NOSIZE
                );
                result = 0;
            }
            break;
        case WM_LBUTTONUP:
            if (gui->isDragging) {
                ReleaseCapture();
                gui->isDragging = FALSE;
            }
            result = 0;
            break;
    }

    return result;
}

BOOL CALLBACK statProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam){
    int result = 0;

    RECT rc;
    POINT cur;

    struct GUISTRUCT* gui = &AppStruct->gui;

    switch (msg) {
        case WM_TIMER:
            statUpdate();
            PostMessage(gui->mainWindow, WM_RENDERSTAT, 0, 0);
            result = 0;
            break;
        case WM_RENDERSTAT:
            wsprintf(gui->labelText, "DL: %d.%d k UL: %d.%d k",
                (AppStruct->stat.bytesDown/1024), ((AppStruct->stat.bytesDown * 10) / 1024) % 10,
                (AppStruct->stat.bytesUp/1024), ((AppStruct->stat.bytesUp * 10) / 1024) % 10
            );
            SetWindowText(gui->stat, gui->labelText);

            NOTIFYICONDATA* notifyIcon = &gui->notifyIcon;
            HICON selectedIcon = gui->iconNone;
            if (AppStruct->stat.bytesDown > 0) {
                selectedIcon = gui->iconDown;
            }
            if (AppStruct->stat.bytesUp   > 0) {
                selectedIcon = gui->iconUp;
            }
            if (AppStruct->stat.bytesDown > 0 && AppStruct->stat.bytesUp > 0) {
                selectedIcon = gui->iconBoth;
            }
            notifyIcon->hIcon = selectedIcon;
            strcpy(notifyIcon->szTip, gui->labelText);
            Shell_NotifyIcon(NIM_MODIFY, notifyIcon);

            result = 0;
            break;
    }

    return result;
}
