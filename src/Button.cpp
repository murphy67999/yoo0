#include "raylib.h"

#include "Button.h"

bool Button::isButtonClicked(){
    bool hover = CheckCollisionPointRec(GetMousePosition(), getRec());

    return hover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

void Button::draw(){
    DrawRectangleV(pos, size, color);
    DrawText(text, getTextPosX(), getTextPosY(), fontSize, textColor);
}

Rectangle Button::getRec(){
    return {pos.x, pos.y, size.x, size.y};
}

int Button::getTextPosX(){
    int width = MeasureText(text, fontSize);

    int emptySpace = size.x - width;
    int padding = emptySpace / 2;
    
    return pos.x + padding;
}

int Button::getTextPosY(){
    int emptySpace = size.y - fontSize;
    int padding = emptySpace / 2;

    return pos.y + padding;
}
