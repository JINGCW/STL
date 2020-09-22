#ifndef _VECTOR2D_H
#define _VECTOR2D_H
#pragma once

#include <math.h>

using namespace std;

class Vector2D {
//    friend Vector2D &operator+=(Vector2D &lhs, Vector2D &rhs);

public:
    Vector2D() = default;

    Vector2D(float x, float y) :
            xpos(x), ypos(y) {}

    ~Vector2D() = default;

    void normalize() {
        auto len = length();
        if (len > 0)
            (*this) /= len;
    }

    void reset()
    {
        this->xpos = this->ypos = 0;
    }
    auto get_x() const { return xpos; }

    float get_y() const { return ypos; }

    void set_x(float x) { xpos = x; }

    void set_y(float y) { ypos = y; }

    float length() const {
        return sqrt(xpos * xpos + ypos * ypos);
    }

    Vector2D &operator+(const Vector2D &v) {
        this->xpos += v.xpos;
        this->ypos += v.ypos;
        return *this;
    }
    Vector2D &operator+=(const Vector2D &v) {
        this->xpos += v.xpos;
        this->ypos += v.ypos;
        return *this;
    }

    Vector2D &operator-(const Vector2D &v) {
        this->xpos -= v.xpos;
        this->ypos -= v.ypos;
        return *this;
    }

    Vector2D &operator-=(const Vector2D &v) {
        return this->operator-(v);
    }


    Vector2D &operator*(float scalar) {
        this->xpos *= scalar;
        this->ypos *= scalar;
        return *this;
    }

    Vector2D &operator*=(float scalar) {
        return this->operator*(scalar);
    }

    Vector2D &operator/(float scalar) {
        this->xpos /= scalar;
        this->ypos /= scalar;
        return *this;
    }

    Vector2D &operator/=(float scalar) {
        return this->operator/(scalar);
    }

private:
    float xpos, ypos;
};

// Vector2D &operator+=(Vector2D &lhs, Vector2D &rhs) {
//    lhs.xpos += rhs.xpos;
//    lhs.ypos += rhs.ypos;
//    return lhs;
//}

#endif //_VECTOR2D_H
