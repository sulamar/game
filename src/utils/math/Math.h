#pragma once
#include <iostream>

namespace engine
{
    template<typename T>
    struct Vector2
    {
        Vector2()
        : x(0), y(0)
        {}

        Vector2(T _x, T _y)
        : x(_x), y(_y) 
        {}

        T x, y;

        Vector2<T> Add(const Vector2<T>& v) const
        {
            return Vector2<T>(x + v.x, y + v.y);
        }
        Vector2<T> Multiply(const Vector2<T>& v) const
        {
            return Vector2<T>(x * v.x, y * v.y);
        }

        Vector2<T> operator+(const Vector2<T>& v) const
        {
            return Add(v);
        }
        Vector2<T> operator+=(const Vector2<T>& v) const
        {
            x += v.y;
            y += v.y;

            return Vector2<T>(x, y);
        }
        Vector2<T> operator-(const Vector2<T>& v)
        {
            x = x - v.x;
            y = y - v.y;

            return Vector2<T>(x, y);
        }
        Vector2<T> operator-=(const Vector2<T>& v)
        {
            x -= v.x;
            y -= v.y;

            return Vector2<T>(x, y);
        }
        Vector2<T> operator*(const Vector2<T>& v) const
        {
            return Multiply(v);
        }

        Vector2<T> operator=(const Vector2<T>& v) 
        {
            x = v.x;
            y = v.y;

            return Vector2<T>(x, y);
        }

        bool operator==(const Vector2<T>& v) const
        {
            return x == v.x && y == v.y;
        }
        bool operator!=(const Vector2<T>& v) const
        {
                return !(*this == v);
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const Vector2<T>& other)
    {
        stream << other.x << ", " << other.y;
        return stream;
    }
}