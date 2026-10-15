#pragma once

#include "raylib.h"

struct Button{
    Button(Vector2 pos, Vector2 size, Color color, const char* text, int fontSize, Color fontColor);
    bool isButtonClicked() const;
    void draw() const;

private:
    const Vector2 m_pos;
    const Vector2 m_size;
    const Color m_color;
    const char* m_text;
    const int m_fontSize;
    const Color m_textColor;

    Rectangle getRec() const;
    int getTextPosX() const;
    int getTextPosY() const;
};
