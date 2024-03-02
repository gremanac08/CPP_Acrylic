#include "AcrylicWindow.h"

bool SetWindowCompositionAttribute(HWND hwnd, ACCENT_POLICY* policy);

void AcrylicWindow::MakeAcrylicWindow(HWND hwnd)
{
	// Abilita gli effetti di composizione
	int compositionEnabled = TRUE;
    DwmEnableComposition(DWM_EC_ENABLECOMPOSITION);

	// Definisce la struttura per li sfondo acrilico
    ACCENT_POLICY accent = {
        ACCENT_ENABLE_ACRYLICBLURBEHIND,
        NULL, NULL, NULL
    };

	// Imposta lo sfondo acrilico sulla finestra
	WINDOWCOMPOSITIONATTRIBDATA data;
	data.nAttribute = WCA_ACCENT_POLICY;
	data.pData = &accent;
	data.ulDataSize = sizeof(accent);

	SetWindowCompositionAttribute(hwnd, &accent);
}

bool SetWindowCompositionAttribute(HWND hwnd, ACCENT_POLICY* policy)
{
    WINDOWCOMPOSITIONATTRIBDATA data;
    data.nAttribute = 19;
    data.pData = policy;
    data.ulDataSize = sizeof(ACCENT_POLICY);
    HINSTANCE hm = LoadLibrary(L"user32.dll");
    if (hm == NULL)
    {
        return false;
    }

    auto SetWindowCompositionAttribute = reinterpret_cast<BOOL(WINAPI*)(HWND, WINDOWCOMPOSITIONATTRIBDATA*)>(GetProcAddress(hm, "SetWindowCompositionAttribute"));
    if (SetWindowCompositionAttribute == NULL)
    {
        FreeLibrary(hm);
        return false;
    }
    SetWindowCompositionAttribute(hwnd, &data);
    FreeLibrary(hm);
    return true;
}
