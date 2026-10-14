#include "raylib.h"

#include "Button.h"

Button::Button(Vector2 pos, Vector2 size, Color color, const char* text, int fontSize, Color textColor):
pos(pos), size(size), color(color), text(text), fontSize(fontSize), textColor(textColor) {}


bool Button::isButtonClicked() const{
    bool hover = CheckCollisionPointRec(GetMousePosition(), getRec());

    return hover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

void Button::draw() const{
    DrawRectangleV(pos, size, color);
    DrawText(text, getTextPosX(), getTextPosY(), fontSize, textColor);
}

Rectangle Button::getRec() const{
    return {pos.x, pos.y, size.x, size.y};
}

int Button::getTextPosX() const{
    int width = MeasureText(text, fontSize);

    int emptySpace = size.x - width;
    int padding = emptySpace / 2;
    
    return pos.x + padding;
}

int Button::getTextPosY() const{
    int emptySpace = size.y - fontSize;
    int padding = emptySpace / 2;

    return pos.y + padding;
}
