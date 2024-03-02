#pragma once

#include <Windows.h>
#include <dwmapi.h>
#include <windowsx.h>
#pragma comment(lib, "Dwmapi.lib")
#pragma warning(disable : 4995)

#define WCA_ACCENT_POLICY 19
#define ACCENT_FLAG_ENABLE_BLURBEHIND 0x20

enum ACCENT_STATE {
    ACCENT_DISABLED = 0,
    ACCENT_ENABLE_GRADIENT = 1,
    ACCENT_ENABLE_TRANSPARENTGRADIENT = 2,
    ACCENT_ENABLE_BLURBEHIND = 3,
    ACCENT_ENABLE_ACRYLICBLURBEHIND = 4,
    ACCENT_INVALID_STATE = 5
};

typedef struct _ACCENT_POLICY {
    int nAccentState;
    int nFlags;
    int nColor;
    int nAnimationId;
} ACCENT_POLICY;

typedef struct _WINDOWCOMPOSITIONATTRIBDATA {
    int nAttribute;
    PVOID pData;
    ULONG ulDataSize;
} WINDOWCOMPOSITIONATTRIBDATA;

namespace AcrylicWindow
{
    void MakeAcrylicWindow(HWND hwnd);
};

