#pragma once
#include "../main.h"

namespace colah {
    struct Color
    {
        int R;
        int G;
        int B;
    };
}

class prefire {
public:
    void prefireLogic();
	bool ColorSearch(colah::Color wantedColor, int colorThreshold, int x1, int y1, int x2, int y2);
	bool AreColorsClose(colah::Color color1, colah::Color color2, int maxColorDifference);
};