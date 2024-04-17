#pragma once

// mouse.cpp
class MouseEvent
{
public:
	void leftClick(int x, int y);
};

//keyboard.cpp
class KeyboardKeys { // vKeys
public:
    // Main letter keys
    static const int A = 0x41;
    static const int B = 0x42;
    static const int C = 0x43;
    static const int D = 0x44;
    static const int E = 0x45;
    static const int F = 0x46;
    static const int G = 0x47;
    static const int H = 0x48;
    static const int I = 0x49;
    static const int J = 0x4A;
    static const int K = 0x4B;
    static const int L = 0x4C;
    static const int M = 0x4D;
    static const int N = 0x4E;
    static const int O = 0x4F;
    static const int P = 0x50;
    static const int Q = 0x51;
    static const int R = 0x52;
    static const int S = 0x53;
    static const int T = 0x54;
    static const int U = 0x55;
    static const int V = 0x56;
    static const int W = 0x57;
    static const int X = 0x58;
    static const int Y = 0x59;
    static const int Z = 0x5A;

    // Numeric keys
    static const int VK_0 = 0x30;
    static const int VK_1 = 0x31;
    static const int VK_2 = 0x32;
    static const int VK_3 = 0x33;
    static const int VK_4 = 0x34;
    static const int VK_5 = 0x35;
    static const int VK_6 = 0x36;
    static const int VK_7 = 0x37;
    static const int VK_8 = 0x38;
    static const int VK_9 = 0x39;

    // Function keys (F1 - F12)
    static const int F1 = 0x70;
    static const int F2 = 0x71;
    static const int F3 = 0x72;
    static const int F4 = 0x73;
    static const int F5 = 0x74;
    static const int F6 = 0x75;
    static const int F7 = 0x76;
    static const int F8 = 0x77;
    static const int F9 = 0x78;
    static const int F10 = 0x79;
    static const int F11 = 0x7A;
    static const int F12 = 0x7B;

    // Symbol keys
    static const int SPACE = 0x20;
    static const int MINUS = 0xBD; // -
    static const int PLUS = 0xBB; // +
    static const int COMMA = 0xBC; // ,
    static const int PERIOD = 0xBE; // .
    static const int SLASH = 0xBF; // /
    static const int SEMICOLON = 0xBA; // ;
    static const int QUOTE = 0xDE; // '
    static const int OPEN_BRACKET = 0xDB; // [
    static const int CLOSE_BRACKET = 0xDD; // ]
    static const int BACKSLASH = 0xDC; // \ // 
};

class KeyboardInput {
public:
	void pressKey(int key);
	short getKey(int key);
};

