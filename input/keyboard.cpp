#include <Windows.h>
#include <thread>
#include "input.h"


void KeyboardInput::pressKey(int key)
{
    keybd_event(key,
        0x45,
        KEYEVENTF_EXTENDEDKEY | 0,
        0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    keybd_event(key,
        0x45,
        KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
        0);
}

short KeyboardInput::getKey(int key)
{
    return GetAsyncKeyState(key);
}