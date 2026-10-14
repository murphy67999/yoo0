#pragma once

#include "raylib.h"

struct Button{
    Vector2 pos;
    Vector2 size;
    Color color;
    const char* text;
    int fontSize;
    Color textColor;

    Button(Vector2 pos, Vector2 size, Color color, const char* text, int fontSize, Color fontColor);
    bool isButtonClicked() const;
    void draw() const;

private:
    Rectangle getRec() const;
    int getTextPosX() const;
    int getTextPosY() const;
};
