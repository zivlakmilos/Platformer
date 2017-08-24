#ifndef _VECTOR_2_H_
#define _VECTOR_2_H_

#include <math.h>

template<typename T>
class Vector2
{
public:
    Vector2(void);
    Vector2(T x, T y);

    inline T getX(void) const { return m_x; }
    inline void setX(T x) { m_x = x; }

    inline T getY(void) const { return m_y; }
    inline void setY(T y) { m_y = y; }

    inline double getMagnitude(void) { return sqrt(m_x * m_x + m_y * m_y); }
    inline void setMagnitude(double magnitude)
        { double mag = magnitude / getMagnitude(); m_x *= mag; m_y *= mag; }

    inline void normalize(void)
        { double mag = getMagnitude(); m_x /= mag; m_y /= mag; }

    Vector2<T> &operator+=(const Vector2<T> &rhs);
    Vector2<T> operator+(const Vector2<T> &rhs) const;
    Vector2<T> &operator+=(T rhs);
    Vector2<T> operator+(T rhs) const;
    Vector2<T> &operator-=(const Vector2<T> &rhs);
    Vector2<T> operator-(const Vector2<T> &rhs) const;
    Vector2<T> &operator-=(T rhs);
    Vector2<T> operator-(T rhs) const;
    Vector2<T> &operator*=(T rhs);
    Vector2<T> operator*(T rhs) const;
    Vector2<T> &operator/=(T rhs);
    Vector2<T> operator/(T rhs) const;

private:
    T m_x;
    T m_y;
};

template<typename T>
Vector2<T>::Vector2(void)
    : m_x(0),
      m_y(0)
{
}

template<typename T>
Vector2<T>::Vector2(T x, T y)
    : m_x(x),
      m_y(y)
{
}

template<typename T>
Vector2<T> &Vector2<T>::operator+=(const Vector2<T> &rhs)
{
    m_x += rhs.m_x;
    m_y += rhs.m_y;

    return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T> &rhs) const
{
    return Vector2<T>(m_x + rhs.m_x, m_y + rhs.m_y);
}

template<typename T>
Vector2<T> &Vector2<T>::operator+=(T rhs)
{
    m_x += rhs;
    m_y += rhs;

    return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator+(T rhs) const
{
    return Vector2<T>(m_x + rhs, m_y + rhs);
}

template<typename T>
Vector2<T> &Vector2<T>::operator-=(const Vector2<T> &rhs)
{
    m_x -= rhs.m_x;
    m_y -= rhs.m_y;

    return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T> &rhs) const
{
    return Vector2<T>(m_x - rhs.m_x, m_y - rhs.m_y);
}

template<typename T>
Vector2<T> &Vector2<T>::operator-=(T rhs)
{
    m_x -= rhs;
    m_y -= rhs;

    return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator-(T rhs) const
{
    return Vector2<T>(m_x - rhs, m_y - rhs);
}

template<typename T>
Vector2<T> &Vector2<T>::operator*=(T rhs)
{
    m_x *= rhs;
    m_y *= rhs;

    return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator*(T rhs) const
{
    return Vector2<T>(m_x * rhs, m_y * rhs);
}

template<typename T>
Vector2<T> &Vector2<T>::operator/=(T rhs)
{
    m_x /= rhs;
    m_y /= rhs;

    return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator/(T rhs) const
{
    return Vector2<T>(m_x / rhs, m_y / rhs);
}

typedef Vector2<int> Vector2i;
typedef Vector2<unsigned int> Vector2u;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

#endif // _VECTOR_2_H_
