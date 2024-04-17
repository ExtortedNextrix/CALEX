#include "macros.h"
#include "../input/input.h"

MouseEvent Mouse;
KeyboardKeys Keys;
KeyboardInput Keyboard;
// triantopeidk
colah::Color yellowColor = { 192, 125, 31 }; // normal -> 213, 137, 48

std::mutex colorSearchMutex;

static std::atomic<bool> yellowFound1(true);

void prefire::prefireLogic()
{
    std::cout << "Started!" << std::endl;
    while (true)
    {
        bool yellowFoundLocal;
        std::thread yellowThread1([&]() { yellowFoundLocal = ColorSearch(yellowColor, 5, 180, 260, 1760, 800); });

        yellowThread1.join(); // get back true or false

        {
            std::lock_guard<std::mutex> lock(colorSearchMutex);
            yellowFound1 = yellowFoundLocal;
        }
            
        if ((Keyboard.getKey(Keys.Z) & 0x01) != 0)
        {
            std::cout << "Pressing!" << std::endl;
            if (!yellowFound1)
            {
                Mouse.leftClick(0, 0); // shoot dat nigga
                std::cout << "Clicked!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                Keyboard.pressKey(Keys.P); // Wall Example
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                Mouse.leftClick(0, 0); // place Wall
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                Keyboard.pressKey(Keys.E); // Shotgun Example
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                // wait till wall placed (takes approx 150ms)
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

bool prefire::ColorSearch(colah::Color wantedColor, int colorThreshold, int x1, int y1, int x2, int y2)
{
    using namespace Gdiplus;

    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    HDC hdcScreen = GetDC(NULL);
    HDC hdcBitmap = CreateCompatibleDC(hdcScreen);
    HBITMAP hBitmap = CreateCompatibleBitmap(hdcScreen, x2 - x1, y2 - y1);

    SelectObject(hdcBitmap, hBitmap);
    BitBlt(hdcBitmap, 0, 0, x2 - x1, y2 - y1, hdcScreen, x1, y1, SRCCOPY);

    Bitmap screenShot(hBitmap, NULL);

    DeleteDC(hdcBitmap);
    ReleaseDC(NULL, hdcScreen);

    Rect rect(0, 0, screenShot.GetWidth(), screenShot.GetHeight());
    BitmapData bmpData;
    screenShot.LockBits(&rect, ImageLockModeRead, PixelFormat32bppARGB, &bmpData);

    int bytes = static_cast<int>(std::abs(static_cast<int>(bmpData.Stride)) * screenShot.GetHeight());
    std::vector<BYTE> rgbValues(bytes);
    memcpy(&rgbValues[0], bmpData.Scan0, bytes);
    screenShot.UnlockBits(&bmpData);

    for (int x = 0; x < screenShot.GetWidth(); x++)
    {
        for (int y = 0; y < screenShot.GetHeight(); y++)
        {
            int position = y * bmpData.Stride + 4 * x;
            colah::Color pixelColor;
            pixelColor.R = rgbValues[position + 2];
            pixelColor.G = rgbValues[position + 1];
            pixelColor.B = rgbValues[position];

            if (AreColorsClose(wantedColor, pixelColor, colorThreshold))
            {
                GdiplusShutdown(gdiplusToken);
                return true;
            }
        }
    }

    GdiplusShutdown(gdiplusToken);
    return false;
}

bool prefire::AreColorsClose(colah::Color color1, colah::Color color2, int maxColorDifference)
{
    int redDiff = std::abs(color1.R - color2.R);
    int greenDiff = std::abs(color1.G - color2.G);
    int blueDiff = std::abs(color1.B - color2.B);
    return redDiff <= maxColorDifference && greenDiff <= maxColorDifference && blueDiff <= maxColorDifference;
}