#include "Vec2.hpp"
#include <cmath>

Vec2::Vec2(float xin, float yin)
    : x(xin), y(yin) {}

bool Vec2::operator==(const Vec2 &rhs) const {
    return (x == rhs.x && y == rhs.y);
}

bool Vec2::operator!=(const Vec2 &rhs) const {
    return !(*this == rhs);
}

Vec2 Vec2::operator+(const Vec2 &rhs) const {
    return {x + rhs.x, y + rhs.y};
}

Vec2 Vec2::operator-(const Vec2 &rhs) const {
    return {x - rhs.x, y - rhs.y};
}

Vec2 Vec2::operator/(const float val) const {
    return {x / val, y / val};
}

Vec2 Vec2::operator*(const float val) const {
    return {x * val, y * val};
}

Vec2& Vec2::operator+=(const Vec2 &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vec2& Vec2::operator*=(const float val) {
    x *= val;
    y *= val;
    return *this;
}

Vec2& Vec2::operator/=(const float val) {
    x /= val;
    y /= val;
    return *this;
}

float Vec2::dist(const Vec2 &rhs) const {
    return sqrtf(((rhs.x - x)*(rhs.x - x)) + ((rhs.y - y)*(rhs.y - y)));
}
