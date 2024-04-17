#include <Windows.h>
#include <thread>
#include "input.h"

void MouseEvent::leftClick(int x, int y)
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}
