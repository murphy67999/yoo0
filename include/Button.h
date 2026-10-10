#pragma once

#include "raylib.h"

struct Button{
    Vector2 pos;
    Vector2 size;
    Color color;
    const char* text;
    int fontSize;
    Color textColor;

    int getTextPosX();
    int getTextPosY();
    bool isButtonClicked();

private:
    Rectangle getRec();
};
