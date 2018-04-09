#ifndef _WINUSER32_
#define _WINUSER32_

typedef LRESULT(CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
typedef INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);

#define DefWindowProc DefWindowProcA
LRESULT WINAPI DefWindowProcA(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam
);

typedef struct tagWNDCLASS {
	UINT      style;
	WNDPROC   lpfnWndProc;
	int       cbClsExtra;
	int       cbWndExtra;
	HINSTANCE hInstance;
	HICON     hIcon;
	HCURSOR   hCursor;
	HBRUSH    hbrBackground;
	LPCTSTR   lpszMenuName;
	LPCTSTR   lpszClassName;
} WNDCLASS, *PWNDCLASS;

typedef struct tagWNDCLASSEX {
  UINT      cbSize;
  UINT      style;
  WNDPROC   lpfnWndProc;
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCTSTR   lpszMenuName;
  LPCTSTR   lpszClassName;
  HICON     hIconSm;
} WNDCLASSEX, *PWNDCLASSEX;

typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;

typedef struct tagRECT *PRECT;
typedef struct tagRECT *LPRECT;
typedef const RECT *LPCRECT;

typedef struct tagPOINT {
	LONG x;
	LONG y;
} POINT,POINTL,*PPOINT,*LPPOINT,*PPOINTL,*LPPOINTL;

typedef struct tagMSG {
	HWND hwnd;
	UINT message;
	WPARAM wParam;
	LPARAM lParam;
	DWORD time;
	POINT pt;
} MSG, *LPMSG, *PMSG;

#define COLOR_3DDKSHADOW 21
#define COLOR_3DFACE 15
#define COLOR_3DHILIGHT 20
#define COLOR_3DHIGHLIGHT 20
#define COLOR_3DLIGHT 22
#define COLOR_BTNHILIGHT 20
#define COLOR_3DSHADOW 16
#define COLOR_ACTIVEBORDER 10
#define COLOR_ACTIVECAPTION 2
#define COLOR_APPWORKSPACE 12
#define COLOR_BACKGROUND 1
#define COLOR_DESKTOP 1
#define COLOR_BTNFACE 15
#define COLOR_BTNHIGHLIGHT 20
#define COLOR_BTNSHADOW 16
#define COLOR_BTNTEXT 18
#define COLOR_CAPTIONTEXT 9
#define COLOR_GRAYTEXT 17
#define COLOR_HIGHLIGHT 13
#define COLOR_HIGHLIGHTTEXT 14
#define COLOR_INACTIVEBORDER 11
#define COLOR_INACTIVECAPTION 3
#define COLOR_INACTIVECAPTIONTEXT 19
#define COLOR_INFOBK 24
#define COLOR_INFOTEXT 23
#define COLOR_MENU 4
#define COLOR_MENUTEXT 7
#define COLOR_SCROLLBAR 0
#define COLOR_WINDOW 5
#define COLOR_WINDOWFRAME 6
#define COLOR_WINDOWTEXT 8

#define RegisterClass RegisterClassA
ATOM WINAPI RegisterClassA(
	const WNDCLASS *lpWndClass
);

ATOM WINAPI RegisterClassEx(
	const WNDCLASSEX *lpwcx
);

#define CS_BYTEALIGNCLIENT 4096
#define CS_BYTEALIGNWINDOW 8192
#define CS_KEYCVTWINDOW 4
#define CS_NOKEYCVT 256
#define CS_CLASSDC 64
#define CS_DBLCLKS 8
#define CS_GLOBALCLASS 16384
#define CS_HREDRAW 2
#define CS_NOCLOSE 512
#define CS_OWNDC 32
#define CS_PARENTDC 128
#define CS_SAVEBITS 2048
#define CS_VREDRAW 1
#define CS_IME 0x10000

#define WS_BORDER	0x800000
#define WS_CAPTION	0xc00000
#define WS_CHILD	0x40000000
#define WS_CHILDWINDOW	0x40000000
#define WS_CLIPCHILDREN 0x2000000
#define WS_CLIPSIBLINGS 0x4000000
#define WS_DISABLED	0x8000000
#define WS_DLGFRAME	0x400000
#define WS_GROUP	0x20000
#define WS_HSCROLL	0x100000
#define WS_ICONIC	0x20000000
#define WS_MAXIMIZE	0x1000000
#define WS_MAXIMIZEBOX	0x10000
#define WS_MINIMIZE	0x20000000
#define WS_MINIMIZEBOX	0x20000
#define WS_OVERLAPPED	0
#define WS_OVERLAPPEDWINDOW	0xcf0000
#define WS_POPUP	0x80000000
#define WS_POPUPWINDOW	0x80880000
#define WS_SIZEBOX	0x40000
#define WS_SYSMENU	0x80000
#define WS_TABSTOP	0x10000
#define WS_THICKFRAME	0x40000
#define WS_TILED	0
#define WS_TILEDWINDOW	0xcf0000
#define WS_VISIBLE	0x10000000
#define WS_VSCROLL	0x200000

#define CreateWindow CreateWindowA
#define CreateWindowA(a,b,c,d,e,f,g,h,i,j,k) CreateWindowExA(0,a,b,c,d,e,f,g,h,i,j,k)
#define CreateWindowW(a,b,c,d,e,f,g,h,i,j,k) CreateWindowExW(0,a,b,c,d,e,f,g,h,i,j,k)

HWND WINAPI CreateWindowExA(
	DWORD dwExStyle,
	LPCTSTR lpClassName,
	LPCTSTR lpWindowName,
	DWORD dwStyle,
	int x,
	int y,
	int nWidth,
	int nHeight,
	HWND hWndParent,
	HMENU hMenu,
	HINSTANCE hInstance,
	LPVOID lpParam
);

BOOL WINAPI DestroyWindow(
	HWND hWnd
);

#define SW_HIDE 0
#define SW_NORMAL 1
#define SW_SHOWNORMAL 1
#define SW_SHOWMINIMIZED 2
#define SW_MAXIMIZE 3
#define SW_SHOWMAXIMIZED 3
#define SW_SHOWNOACTIVATE 4
#define SW_SHOW 5
#define SW_MINIMIZE 6
#define SW_SHOWMINNOACTIVE 7
#define SW_SHOWNA 8
#define SW_RESTORE 9
#define SW_SHOWDEFAULT 10
#define SW_FORCEMINIMIZE 11
#define SW_MAX  11

BOOL WINAPI ShowWindow(
	HWND hWnd,
	int nCmdShow
);

#define GW_HWNDFIRST 0
#define GW_HWNDLAST 1
#define GW_HWNDNEXT 2
#define GW_HWNDPREV 3
#define GW_OWNER 4
#define GW_CHILD 5
#define GW_ENABLEDPOPUP 6
#define GW_MAX 6

HWND WINAPI GetWindow(HWND hWnd,UINT uCmd);

BOOL WINAPI UpdateWindow(
	HWND hWnd
);

#define RDW_INVALIDATE 0x0001
#define RDW_INTERNALPAINT 0x0002
#define RDW_ERASE 0x0004

#define RDW_VALIDATE 0x0008
#define RDW_NOINTERNALPAINT 0x0010
#define RDW_NOERASE 0x0020

#define RDW_NOCHILDREN 0x0040
#define RDW_ALLCHILDREN 0x0080

#define RDW_UPDATENOW 0x0100
#define RDW_ERASENOW 0x0200

#define RDW_FRAME 0x0400
#define RDW_NOFRAME 0x0800

BOOL WINAPI RedrawWindow(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#define GWL_USERDATA -21
#define GWL_EXSTYLE -20
#define GWL_STYLE -16
#define GWL_ID -12
#define GWL_HINSTANCE -6
#define GWL_WNDPROC -4

#define DWL_MSGRESULT 0
#define DWL_DLGPROC 4
#define DWL_USER 8

#ifdef _WIN64
#undef DWL_MSGRESULT
#undef DWL_DLGPROC
#undef DWL_USER
#endif

#define DWLP_MSGRESULT 0
#define DWLP_DLGPROC DWLP_MSGRESULT + sizeof(LRESULT)
#define DWLP_USER DWLP_DLGPROC + sizeof(DLGPROC)

#define SetWindowLong SetWindowLongA
LONG WINAPI SetWindowLongA(
	HWND hWnd,
	int nIndex,
	LONG dwNewLong
);

#define SetWindowText SetWindowTextA
BOOL WINAPI SetWindowTextA(HWND hWnd,LPCSTR lpString);

#define WM_APP 32768
#define WM_ACTIVATE 6
#define WM_ACTIVATEAPP 28
#define WM_AFXFIRST 864
#define WM_AFXLAST 895
#define WM_ASKCBFORMATNAME 780
#define WM_CANCELJOURNAL 75
#define WM_CANCELMODE 31
#define WM_CAPTURECHANGED 533
#define WM_CHANGECBCHAIN 781
#define WM_CHAR 258
#define WM_CHARTOITEM 47
#define WM_CHILDACTIVATE 34
#define WM_CLEAR 771
#define WM_CLOSE 16
#define WM_COMMAND 273
#define WM_COMMNOTIFY 68
#define WM_COMPACTING 65
#define WM_COMPAREITEM 57
#define WM_CONTEXTMENU 123
#define WM_COPY 769
#define WM_COPYDATA 74
#define WM_CREATE 1
#define WM_CTLCOLORBTN 309
#define WM_CTLCOLORDLG 310
#define WM_CTLCOLOREDIT 307
#define WM_CTLCOLORLISTBOX 308
#define WM_CTLCOLORMSGBOX 306
#define WM_CTLCOLORSCROLLBAR 311
#define WM_CTLCOLORSTATIC 312
#define WM_CUT 768
#define WM_DEADCHAR 259
#define WM_DELETEITEM 45
#define WM_DESTROY 2
#define WM_DESTROYCLIPBOARD 775
#define WM_DEVICECHANGE 537
#define WM_DEVMODECHANGE 27
#define WM_DISPLAYCHANGE 126
#define WM_DRAWCLIPBOARD 776
#define WM_DRAWITEM 43
#define WM_DROPFILES 563
#define WM_ENABLE 10
#define WM_ENDSESSION 22
#define WM_ENTERIDLE 289
#define WM_ENTERMENULOOP 529
#define WM_ENTERSIZEMOVE 561
#define WM_ERASEBKGND 20
#define WM_EXITMENULOOP 530
#define WM_EXITSIZEMOVE 562
#define WM_FONTCHANGE 29
#define WM_GETDLGCODE 135
#define WM_GETFONT 49
#define WM_GETHOTKEY 51
#define WM_GETICON 127
#define WM_GETMINMAXINFO 36
#define WM_GETTEXT 13
#define WM_GETTEXTLENGTH 14
#define WM_HANDHELDFIRST 856
#define WM_HANDHELDLAST 863
#define WM_HELP 83
#define WM_HOTKEY 786
#define WM_HSCROLL 276
#define WM_HSCROLLCLIPBOARD 782
#define WM_ICONERASEBKGND 39
#define WM_INITDIALOG 272
#define WM_INITMENU 278
#define WM_INITMENUPOPUP 279
#define WM_INPUTLANGCHANGE 81
#define WM_INPUTLANGCHANGEREQUEST 80
#define WM_KEYDOWN 256
#define WM_KEYUP 257
#define WM_KILLFOCUS 8
#define WM_MDIACTIVATE 546
#define WM_MDICASCADE 551
#define WM_MDICREATE 544
#define WM_MDIDESTROY 545
#define WM_MDIGETACTIVE 553
#define WM_MDIICONARRANGE 552
#define WM_MDIMAXIMIZE 549
#define WM_MDINEXT 548
#define WM_MDIREFRESHMENU 564
#define WM_MDIRESTORE 547
#define WM_MDISETMENU 560
#define WM_MDITILE 550
#define WM_MEASUREITEM 44
#define WM_MENUCHAR 288
#define WM_MENUSELECT 287
#define WM_NEXTMENU 531
#define WM_MOVE 3
#define WM_MOVING 534
#define WM_NCACTIVATE 134
#define WM_NCCALCSIZE 131
#define WM_NCCREATE 129
#define WM_NCDESTROY 130
#define WM_NCHITTEST 132
#define WM_NCLBUTTONDBLCLK 163
#define WM_NCLBUTTONDOWN 161
#define WM_NCLBUTTONUP 162
#define WM_NCMBUTTONDBLCLK 169
#define WM_NCMBUTTONDOWN 167
#define WM_NCMBUTTONUP 168
#define WM_NCMOUSEMOVE 160
#define WM_NCPAINT 133
#define WM_NCRBUTTONDBLCLK 166
#define WM_NCRBUTTONDOWN 164
#define WM_NCRBUTTONUP 165
#define WM_NEXTDLGCTL 40
#define WM_NEXTMENU 531
#define WM_NOTIFY 78
#define WM_NOTIFYFORMAT 85
#define WM_NULL 0
#define WM_PAINT 15
#define WM_PAINTCLIPBOARD 777
#define WM_PAINTICON 38
#define WM_PALETTECHANGED 785
#define WM_PALETTEISCHANGING 784
#define WM_PARENTNOTIFY 528
#define WM_PASTE 770
#define WM_PENWINFIRST 896
#define WM_PENWINLAST 911
#define WM_POWER 72
#define WM_POWERBROADCAST 536
#define WM_PRINT 791
#define WM_PRINTCLIENT 792
#define WM_QUERYDRAGICON 55
#define WM_QUERYENDSESSION 17
#define WM_QUERYNEWPALETTE 783
#define WM_QUERYOPEN 19
#define WM_QUEUESYNC 35
#define WM_QUIT 18
#define WM_RENDERALLFORMATS 774
#define WM_RENDERFORMAT 773
#define WM_SETCURSOR 32
#define WM_SETFOCUS 7
#define WM_SETFONT 48
#define WM_SETHOTKEY 50
#define WM_SETICON 128
#define WM_SETREDRAW 11
#define WM_SETTEXT 12
#define WM_SETTINGCHANGE 26
#define WM_SHOWWINDOW 24
#define WM_SIZE 5
#define WM_SIZECLIPBOARD 779
#define WM_SIZING 532
#define WM_SPOOLERSTATUS 42
#define WM_STYLECHANGED 125
#define WM_STYLECHANGING 124
#define WM_SYSCHAR 262
#define WM_SYSCOLORCHANGE 21
#define WM_SYSCOMMAND 274
#define WM_SYSDEADCHAR 263
#define WM_SYSKEYDOWN 260
#define WM_SYSKEYUP 261
#define WM_TCARD 82
#define WM_TIMECHANGE 30
#define WM_TIMER 275
#define WM_UNDO 772
#define WM_USER 1024
#define WM_USERCHANGED 84
#define WM_VKEYTOITEM 46
#define WM_VSCROLL 277
#define WM_VSCROLLCLIPBOARD 778
#define WM_WINDOWPOSCHANGED 71
#define WM_WINDOWPOSCHANGING 70
#define WM_WININICHANGE 26
#define WM_KEYFIRST 256
#define WM_KEYLAST 264
#define WM_SYNCPAINT  136
#define WM_MOUSEACTIVATE 33
#define WM_MOUSEMOVE 512
#define WM_LBUTTONDOWN 513
#define WM_LBUTTONUP 514
#define WM_LBUTTONDBLCLK 515
#define WM_RBUTTONDOWN 516
#define WM_RBUTTONUP 517
#define WM_RBUTTONDBLCLK 518
#define WM_MBUTTONDOWN 519
#define WM_MBUTTONUP 520
#define WM_MBUTTONDBLCLK 521
#define WM_MOUSEWHEEL 522
#define WM_MOUSEFIRST 512
#define WM_MOUSELAST 522
#define WM_MOUSEHOVER	0x2A1
#define WM_MOUSELEAVE	0x2A3

#define GetMessage GetMessageA
BOOL WINAPI GetMessageA(
	LPMSG lpMsg,
	HWND hWnd,
	UINT wMsgFilterMin,
	UINT wMsgFilterMax
);

BOOL WINAPI TranslateMessage(
	const MSG *lpMsg
);

#define DispatchMessage DispatchMessageA
LRESULT WINAPI DispatchMessageA(
	const MSG *lpmsg
);

void WINAPI PostQuitMessage(
	int nExitCode
);

#define PostMessage PostMessageA
BOOL WINAPI PostMessageA(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam
);

#define MessageBox MessageBoxA
int WINAPI MessageBoxA(
	HWND hWnd,
	LPCTSTR lpText,
	LPCTSTR lpCaption,
	UINT uType
);

/*
// Undocumented
#define MB_USERICON 128
#define MB_ICONASTERISK 64
#define MB_TOPMOST 0x40000
#define MB_ICONMASK 240
#define MB_DEFMASK 3840
#define MB_MODEMASK 0x00003000
#define MB_MISCMASK 0x0000C000
#define MB_NOFOCUS 0x00008000
#define MB_TYPEMASK 15
*/

#define MB_ABORTRETRYIGNORE 2
#define MB_CANCELTRYCONTINUE 6
#define MB_HELP 0x4000
#define MB_OK 0
#define MB_OKCANCEL 1
#define MB_RETRYCANCEL 5
#define MB_YESNO 4
#define MB_YESNOCANCEL 3

#define MB_ICONEXCLAMATION 0x30
#define MB_ICONWARNING 0x30
#define MB_ICONINFORMATION 64
#define MB_ICONQUESTION 32
#define MB_ICONSTOP 16
#define MB_ICONERROR 16
#define MB_ICONHAND 16

#define MB_DEFBUTTON1 0
#define MB_DEFBUTTON2 256
#define MB_DEFBUTTON3 512
#define MB_DEFBUTTON4 0x300

#define MB_APPLMODAL 0
#define MB_SYSTEMMODAL 4096
#define MB_TASKMODAL 0x2000

#define MB_DEFAULT_DESKTOP_ONLY 0x20000
#define MB_RIGHT 0x80000
#define MB_RTLREADING 0x100000
#define MB_SETFOREGROUND 0x10000
#define MB_TOPMOST 0x40000
#define MB_SERVICE_NOTIFICATION  0x00200000

#define IDABORT 3
#define IDCANCEL 2
#define IDCLOSE 8
#define IDHELP 9
#define IDIGNORE 5
#define IDNO 7
#define IDOK 1
#define IDRETRY 4
#define IDTRYAGAIN 10
#define IDYES 6

#define STM_SETICON 0x0170
#define STM_GETICON 0x0171
#define STM_SETIMAGE 0x0172
#define STM_GETIMAGE 0x0173
#define STN_CLICKED 0
#define STN_DBLCLK 1
#define STN_ENABLE 2
#define STN_DISABLE 3
#define STM_MSGMAX 0x0174

#define wvsprintf wvsprintfA
int WINAPI wvsprintfA(
	LPTSTR lpOutput,
	LPCTSTR lpFmt,
	PVOID arglist
);

#define wsprintf wsprintfA
int WINAPIV wsprintfA(LPSTR,LPCSTR,...);

#define LoadIcon LoadIconA
HICON WINAPI LoadIconA(
	HINSTANCE hInstance,
	LPCTSTR lpIconName
);

#define LoadCursor LoadIconA
HCURSOR WINAPI LoadCursorA(
	HINSTANCE hInstance,
	LPCTSTR lpCursorName
);


#define IMAGE_BITMAP 0
#define IMAGE_ICON 1 
#define IMAGE_CURSOR 2

#define LR_CREATEDIBSECTION 0x00002000
#define LR_DEFAULTCOLOR 0x00000000
#define LR_DEFAULTSIZE 0x00000040
#define LR_LOADFROMFILE 0x00000010
#define LR_LOADMAP3DCOLORS 0x00001000
#define LR_LOADTRANSPARENT 0x00000020
#define LR_MONOCHROME 0x00000001
#define LR_SHARED 0x00008000
#define LR_VGACOLOR 0x00000080 

#define LoadImage LoadImageA
HANDLE WINAPI LoadImageA(
	HINSTANCE hinst,
	LPCTSTR lpszName,
	UINT uType,
	int cxDesired,
	int cyDesired,
	UINT fuLoad
);

BOOL WINAPI GetClientRect(
	HWND hWnd,
	LPRECT lpRect
);

BOOL WINAPI GetWindowRect(
	HWND hWnd,
	LPRECT lpRect
);

BOOL WINAPI AdjustWindowRect(
	LPRECT lpRect,
	DWORD dwStyle,
	BOOL bMenu
);

BOOL WINAPI AdjustWindowRectEx(
	LPRECT lpRect,
	DWORD dwStyle,
	BOOL bMenu,
	DWORD dwExStyle
);

BOOL WINAPI MoveWindow(
	HWND hWnd,
	int X,
	int Y,
	int nWidth,
	int nHeight,
	BOOL bRepaint
);

#define SWP_NOSIZE 0x0001
#define SWP_NOMOVE 0x0002
#define SWP_NOZORDER 0x0004
#define SWP_NOREDRAW 0x0008
#define SWP_NOACTIVATE 0x0010
#define SWP_FRAMECHANGED 0x0020
#define SWP_SHOWWINDOW 0x0040
#define SWP_HIDEWINDOW 0x0080
#define SWP_NOCOPYBITS 0x0100
#define SWP_NOOWNERZORDER 0x0200
#define SWP_NOSENDCHANGING 0x0400

#define SWP_DRAWFRAME SWP_FRAMECHANGED
#define SWP_NOREPOSITION SWP_NOOWNERZORDER
#define SWP_DEFERERASE 0x2000
#define SWP_ASYNCWINDOWPOS 0x4000

#define HWND_TOP ((HWND)0)
#define HWND_BOTTOM ((HWND)1)
#define HWND_TOPMOST ((HWND)-1)
#define HWND_NOTOPMOST ((HWND)-2)

BOOL WINAPI SetWindowPos(
	HWND hWnd,
	HWND hWndInsertAfter,
	int X,
	int Y,
	int cx,
	int cy,
	UINT uFlags
);

typedef struct tagWINDOWPLACEMENT {
    UINT  length;
    UINT  flags;
    UINT  showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT  rcNormalPosition;
} WINDOWPLACEMENT,*PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;


BOOL WINAPI GetWindowPlacement(
	HWND hWnd,
	WINDOWPLACEMENT *lpwndpl
);

BOOL WINAPI SetWindowPlacement(
	HWND hWnd,
	CONST WINDOWPLACEMENT *lpwndpl
);

#define CreateDialog CreateDialogA
#define CreateDialogA(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamA(hInstance,lpName,hWndParent,lpDialogFunc,0L)
HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);

BOOL WINAPI GetCursorPos(LPPOINT lpPoint);

HWND WINAPI SetCapture(HWND hWnd);
BOOL WINAPI ReleaseCapture(VOID);

#define MF_ENABLED         0x00000000
#define MF_GRAYED          0x00000001
#define MF_DISABLED        0x00000002
#define MF_BITMAP          0x00000004
#define MF_CHECKED         0x00000008
#define MF_POPUP           0x00000010
#define MF_MENUBARBREAK    0x00000020
#define MF_MENUBREAK       0x00000040
#define MF_OWNERDRAW       0x00000100
#define MF_SEPARATOR       0x00000800
#define MF_STRING          0x00000000
#define MF_UNCHECKED       0x00000000
#define MF_DEFAULT         0x00001000
#define MF_SYSMENU         0x00002000
#define MF_HELP            0x00004000
#define MF_END             0x00000080
#define MF_RIGHTJUSTIFY    0x00004000
#define MF_MOUSESELECT     0x00008000

#define MF_INSERT          0x00000000
#define MF_CHANGE          0x00000080

#define MF_APPEND          0x00000100
#define MF_DELETE          0x00000200
#define MF_REMOVE          0x00001000

#define MF_USECHECKBITMAPS 0x00000200

#define MF_UNHILITE        0x00000000
#define MF_HILITE          0x00000080

#define MF_BYCOMMAND       0x00000000
#define MF_BYPOSITION      0x00000400

#define SC_SIZE 0xF000
#define SC_MOVE 0xF010
#define SC_MINIMIZE 0xF020
#define SC_MAXIMIZE 0xF030
#define SC_NEXTWINDOW 0xF040
#define SC_PREVWINDOW 0xF050
#define SC_CLOSE 0xF060
#define SC_VSCROLL 0xF070
#define SC_HSCROLL 0xF080
#define SC_MOUSEMENU 0xF090
#define SC_KEYMENU 0xF100
#define SC_ARRANGE 0xF110
#define SC_RESTORE 0xF120
#define SC_TASKLIST 0xF130
#define SC_SCREENSAVE 0xF140
#define SC_HOTKEY 0xF150
#define SC_DEFAULT 0xF160
#define SC_MONITORPOWER 0xF170
#define SC_CONTEXTHELP 0xF180
#define SC_SEPARATOR 0xF00F
#define SC_ICON SC_MINIMIZE
#define SC_ZOOM SC_MAXIMIZE

HMENU WINAPI GetSystemMenu(HWND hWnd,BOOL bRevert);

HMENU WINAPI CreateMenu(void);
HMENU WINAPI CreatePopupMenu(void);

BOOL WINAPI EnableMenuItem(HMENU hMenu,UINT uIDEnableItem,UINT uEnable);

#define AppendMenu AppendMenuA
BOOL WINAPI AppendMenuA(
	HMENU hMenu,
	UINT uFlags,
	PUINT uIDNewItem,
	LPCTSTR lpNewItem
);

BOOL WINAPI SetMenu(HWND hWnd,HMENU hMenu);

typedef VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);

UINT_PTR WINAPI SetTimer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);

#endif
