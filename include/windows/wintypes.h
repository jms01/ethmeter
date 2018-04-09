#ifndef _WINTYPES_
#define _WINTYPES_

#define __cdecl __attribute__((cdecl))
#define __stdcall __attribute__((stdcall))
#define __pascal __stdcall
#define __declspec(e) __attribute__((e))

#define DECLSPEC_IMPORT __declspec(dllimport)
#define DECLSPEC_EXPORT __declspec(dllexport)

#define CDECL __cdecl
#define WINAPIV __cdecl

#define PASCAL __pascal

#define STDCALL __stdcall
#define WINAPI __stdcall
#define APIENTRY __stdcall
#define CALLBACK __stdcall
#define APIPRIVATE __stdcall

#define NULL ((void*)0)

#define FALSE 0
#define TRUE 1
typedef int WINBOOL,*PWINBOOL,*LPWINBOOL;
typedef WINBOOL BOOL;

#define VOID void
typedef void* PVOID;
typedef void* LPVOID;

typedef unsigned int SIZE_T;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned long long QWORD;

typedef BYTE *PBYTE,*LPBYTE;
typedef WORD *PWORD,*LPWORD;
typedef DWORD *PDWORD,*LPDWORD;
typedef QWORD *PQWORD,*LPQWORD;

typedef PBYTE* PPBYTE;
typedef PWORD* PPWORD;
typedef PDWORD* PPDWORD;
typedef PQWORD* PPQWORD;

typedef char CHAR, *PCHAR;
typedef unsigned char UCHAR, *PUCHAR;
typedef short SHORT, *PSHORT;
typedef unsigned short USHORT, *PUSHORT;
typedef int INT, *PINT;
typedef unsigned int UINT, *PUINT;
typedef long LONG, *PLONG;
typedef unsigned long ULONG, *PULONG;

typedef UINT WPARAM;
typedef LONG LPARAM;
typedef LONG LRESULT;
typedef LONG HRESULT;

#ifdef UNICODE
#define TEXT(x) L##x
#else
#define TEXT(x) x
#endif

#define T(x) TEXT(x)

typedef char char_t;
typedef unsigned short wchar_t;

typedef char_t TCHAR;
typedef wchar_t WCHAR;

#define CONST const
typedef WCHAR *PWCHAR,*LPWCH,*PWCH,*NWPSTR,*LPWSTR,*PWSTR;
typedef CONST WCHAR *LPCWCH,*PCWCH,*LPCWSTR,*PCWSTR;

typedef CHAR *PCHAR,*LPCH,*PCH,*NPSTR,*LPSTR,*PSTR;
typedef TCHAR *LPTCH,*PTSTR,*LPTSTR,*LP,*PTCHAR;
typedef CONST CHAR *LPCCH,*PCSTR,*LPCSTR;
typedef CONST TCHAR *LPCTSTR;


typedef PVOID HANDLE;
typedef HANDLE *PHANDLE, *LPHANDLE;

typedef HANDLE HACCEL;
typedef HANDLE HBITMAP;
typedef HANDLE HBRUSH;
typedef HANDLE HCOLORSPACE;
typedef HANDLE HDC;
typedef HANDLE HGLRC;
typedef HANDLE HDESK;
typedef HANDLE HENHMETAFILE;
typedef HANDLE HFONT;
typedef HANDLE HICON;
typedef HICON HCURSOR;
typedef HANDLE HKEY;

typedef HANDLE HMENU;
typedef HANDLE HMETAFILE;
typedef HANDLE HINSTANCE;
typedef HINSTANCE HMODULE;
typedef HANDLE HPALETTE;
typedef HANDLE HPEN;
typedef HANDLE HRGN;
typedef HANDLE HRSRC;
typedef HANDLE HSTR;
typedef HANDLE HTASK;
typedef HANDLE HWND;
typedef HANDLE HWINSTA;
typedef HANDLE HKL;

typedef WORD ATOM, *PATOM;
typedef int HFILE;
typedef DWORD COLORREF;

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

#ifdef _WIN64
  typedef __int64 INT_PTR,*PINT_PTR;
  typedef unsigned __int64 UINT_PTR,*PUINT_PTR;
  typedef __int64 LONG_PTR,*PLONG_PTR;
  typedef unsigned __int64 ULONG_PTR,*PULONG_PTR;
#define __int3264 __int64
#else
  typedef int INT_PTR,*PINT_PTR;
  typedef unsigned int UINT_PTR,*PUINT_PTR;
  typedef long LONG_PTR,*PLONG_PTR;
  typedef unsigned long ULONG_PTR,*PULONG_PTR;
#define __int3264 __int32
#endif

#define _ULONGLONG_
#if((!(defined(_X86_) && !defined(__x86_64)) || (defined(_INTEGRAL_MAX_BITS) && _INTEGRAL_MAX_BITS >= 64)))
typedef __int64 LONGLONG;
typedef unsigned __int64 ULONGLONG;
#define MAXLONGLONG (0x7fffffffffffffff)
#else
typedef double LONGLONG;
typedef double ULONGLONG;
#endif

typedef LONGLONG *PLONGLONG;
typedef ULONGLONG *PULONGLONG;

typedef LONGLONG USN;

typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    };
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    LONGLONG QuadPart;
} LARGE_INTEGER;

typedef LARGE_INTEGER *PLARGE_INTEGER;

typedef union _ULARGE_INTEGER {
    struct {
        DWORD LowPart;
        DWORD HighPart;
    };
    struct {
        DWORD LowPart;
        DWORD HighPart;
    } u;
    ULONGLONG QuadPart;
} ULARGE_INTEGER;

typedef ULARGE_INTEGER *PULARGE_INTEGER;

#endif
