#ifndef _VECTOR2D_H
#define _VECTOR2D_H
#pragma once

#include <math.h>

class Vector2D
{
    float xpos, ypos;
//protected:
    using type = Vector2D;
    using type_ptr = Vector2D *;
    using type_ref = Vector2D &;
public:
    Vector2D() = default;

    Vector2D(float x, float y) :
            xpos(x), ypos(y)
    {}

    ~Vector2D() = default;

    void normalize()
    {
        float len = length();
        if (len > 0)
            (*this) /= len;
    }

    type_ref operator/=(float scalar)
    {
        return this->operator/(scalar);
    }

    type_ref operator/(float scalar)
    {
        this->xpos /= scalar;
        this->ypos /= scalar;
        return *this;
    }

    type_ref operator-=(const type_ref v)
    {
        return this->operator-(v);
    }

    type_ref operator-(const type_ref v)
    {
        this->xpos -= v.xpos;
        this->ypos -= v.ypos;
        return *this;
    }

    type_ref operator*=(float scalar)
    {
        return this->operator*(scalar);
    }

    type_ref operator*(float scalar)
    {
        this->xpos *= scalar;
        this->ypos *= scalar;
        return *this;
    }

    type_ref operator+=(const type_ref v)
    {
        return this->operator+(v);
    }

    type_ref operator+(const type_ref v)
    {
        this->xpos += v.xpos;
        this->ypos += v.ypos;
        return *this;
    }

    float get_x() const
    { return xpos; }

    float get_y() const
    { return ypos; }

    void set_x(float x)
    { xpos = x; }

    void set_y(float y)
    { ypos = y; }

    float length() const
    {
        return sqrt(xpos * xpos + ypos * ypos);
    }
//private:
//    float xpos, ypos;
};


#endif //_VECTOR2D_H
