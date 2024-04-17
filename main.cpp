#include "main.h"
#include "macros/macros.h"

prefire PreFireMacro;

int main() {
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    PreFireMacro.prefireLogic();

    Gdiplus::GdiplusShutdown(gdiplusToken);
}

