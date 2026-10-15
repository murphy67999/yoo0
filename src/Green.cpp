#include "Green.h"
#include "Gun.h"

Green::Green(Vector2 pos)
: m_pos(pos) {}

void Green::draw() const{
    DrawCircleV(m_pos, m_radius, m_color);
    gun.draw();
}

Vector2 Green::getPos() const{
    return m_pos;
}

float Green::getRadius() const{
    return m_radius;
}