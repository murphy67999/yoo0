#pragma once

#include "raylib.h"

struct Button{
    Vector2 pos;
    Vector2 size;
    Color color;
    const char* text;
    int fontSize;
    Color textColor;

    bool isButtonClicked();
    void draw();

private:
    Rectangle getRec();
    int getTextPosX();
    int getTextPosY();
};
