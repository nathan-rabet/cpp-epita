#include "vector.hh"

int Vector::get_coord(int i) const
{
    return coords[i];
}

Vector::Vector()
{
    for (size_t i = 0; i < NDIM; i++)
        coords[i] = 0;
}

Vector::Vector(const value v[])
{
    for (size_t i = 0; i < NDIM; ++i)
        coords[i] = v[i];
}

Vector::Vector(std::initializer_list<value> l)
{
    assert(l.size() == NDIM);
    std::copy(l.begin(), l.end(), coords);
}

Vector Vector::operator+(const Vector &other) const
{
    value l[NDIM];
    for (size_t i = 0; i < NDIM; ++i)
        l[i] = coords[i] + other.coords[i];

    return Vector(l);
}

// Dot product
value Vector::operator*(const Vector &other) const
{
    value sum = 0;
    for (size_t i = 0; i < NDIM; ++i)
        sum += coords[i] * other.coords[i];

    return sum;
}

// Dot product with a scalar
Vector Vector::operator*(const int rhs) const
{
    value l[NDIM];
    for (size_t i = 0; i < NDIM; ++i)
        l[i] = coords[i] * rhs;

    return Vector(l);
}

Vector Vector::operator-(const Vector &other) const
{
    value l[NDIM];
    for (size_t i = 0; i < NDIM; ++i)
        l[i] = coords[i] - other.coords[i];

    return Vector(l);
}

// Public Member functions here
Vector &Vector::operator+=(const Vector &rhs)
{
    for (size_t i = 0; i < NDIM; ++i)
        coords[i] += rhs.coords[i];

    return *this;
}

Vector &Vector::operator+=(const int rhs)
{
    for (size_t i = 0; i < NDIM; ++i)
        coords[i] *= rhs;

    return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
    for (size_t i = 0; i < NDIM; ++i)
        coords[i] -= rhs.coords[i];

    return *this;
}

Vector &Vector::operator*=(const Vector &rhs)
{
    for (size_t i = 0; i < NDIM; ++i)
        coords[i] *= rhs.coords[i];

    return *this;
}

Vector &Vector::operator*=(const value &rhs)
{
    for (size_t i = 0; i < NDIM; ++i)
        coords[i] *= rhs;

    return *this;
}

value &Vector::operator[](size_t i)
{
    assert(i < NDIM);
    return coords[i];
}

// Not vector operators

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << "{";
    for (size_t i = 0; i < NDIM; ++i)
    {
        os << v.get_coord(i);
        if (i != NDIM - 1)
            os << ",";
    }
    os << "}";
    return os;
}

Vector operator*(const value &s, const Vector &v)
{
    value l[NDIM];
    for (size_t i = 0; i < NDIM; ++i)
        l[i] = v.get_coord(i) * s;

    return Vector(l);
}

Vector operator+(const value &s, const Vector &v)
{
    value l[NDIM];
    for (size_t i = 0; i < NDIM; ++i)
        l[i] = v.get_coord(i) + s;

    return Vector(l);
}

Vector operator-(const value &s, const Vector &v)
{
    value l[NDIM];
    for (size_t i = 0; i < NDIM; ++i)
        l[i] = v.get_coord(i) - s;

    return Vector(l);
}
