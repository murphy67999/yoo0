#include "raylib.h"

#include "Button.h"

Button::Button(Vector2 pos, Vector2 size, Color color, const char* text, int fontSize, Color textColor):
m_pos(pos), m_size(size), m_color(color), m_text(text), m_fontSize(fontSize), m_textColor(textColor) {}


bool Button::isButtonClicked() const{
    bool hover = CheckCollisionPointRec(GetMousePosition(), getRec());

    return hover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

void Button::draw() const{
    DrawRectangleV(m_pos, m_size, m_color);
    DrawText(m_text, getTextPosX(), getTextPosY(), m_fontSize, m_textColor);
}

Rectangle Button::getRec() const{
    return {m_pos.x, m_pos.y, m_size.x, m_size.y};
}

int Button::getTextPosX() const{
    int width = MeasureText(m_text, m_fontSize);

    int emptySpace = m_size.x - width;
    int padding = emptySpace / 2;
    
    return m_pos.x + padding;
}

int Button::getTextPosY() const{
    int emptySpace = m_size.y - m_fontSize;
    int padding = emptySpace / 2;

    return m_pos.y + padding;
}
