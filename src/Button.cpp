#include "Button.h"

int Button::getTextPosX(){
    int width = MeasureText(text, fontSize);

    return pos.x + (size.x - width) / 2;
}

int Button::getTextPosY(){
    return pos.y + (size.y - fontSize) / 2;
}

bool Button::isButtonClicked(){
    bool hover = CheckCollisionPointRec(GetMousePosition(), getRec());

    return hover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

Rectangle Button::getRec(){
    return {pos.x, pos.y, size.x, size.y};
}