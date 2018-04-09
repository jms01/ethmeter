#ifndef _WINMACRO_
#define _WINMACRO_

#define DWORD(x,y) (DWORD)((WORD)(x << 16) | ((WORD)y))
#define HIWORD(x) (WORD)(((DWORD)x >> 16) & 0xFFFF)
#define LOWORD(x) (WORD)(((DWORD)x) & 0xFFFF)

#define HIBYTE(x) (BYTE)(((WORD)x >> 16) & 0xFF)
#define LOBYTE(x) (BYTE)(((WORD)x) & 0xFF)

#endif
