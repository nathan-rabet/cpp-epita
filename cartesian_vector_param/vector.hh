#pragma once

#include <cassert>
#include <initializer_list>
#include <ostream>

#include "config.h"

class Vector
{
public:
    // DO NOT CHANGE THIS
    Vector(const Vector &) = default;
    Vector &operator=(const Vector &) = default;
    ~Vector() = default;
    //

    // Add suitable constructors
    Vector();

    int get_coord(int i) const
    {
        return coords[i];
    }

    Vector(const value v[])
    {
        for (size_t i = 0; i < NDIM; ++i)
            coords[i] = v[i];
    }

    Vector(std::initializer_list<value> l)
    {
        assert(l.size() == NDIM);
        std::copy(l.begin(), l.end(), coords);
    }

    Vector operator+(const Vector &other) const
    {
        value l[NDIM];
        for (size_t i = 0; i < NDIM; ++i)
            l[i] = coords[i] + other.coords[i];

        return Vector(l);
    }

    // Dot product
    value operator*(const Vector &other) const
    {
        value sum = 0;
        for (size_t i = 0; i < NDIM; ++i)
            sum += coords[i] * other.coords[i];

        return sum;
    }

    // Dot product with a scalar
    Vector operator*(const int rhs) const
    {
        value l[NDIM];
        for (size_t i = 0; i < NDIM; ++i)
            l[i] = coords[i] * rhs;

        return Vector(l);
    }

    Vector operator-(const Vector &other) const
    {
        value l[NDIM];
        for (size_t i = 0; i < NDIM; ++i)
            l[i] = coords[i] - other.coords[i];

        return Vector(l);
    }

    // Public Member functions here
    Vector &operator+=(const Vector &rhs)
    {
        for (size_t i = 0; i < NDIM; ++i)
            coords[i] += rhs.coords[i];

        return *this;
    }

    Vector &operator+=(const int rhs)
    {
        for (size_t i = 0; i < NDIM; ++i)
            coords[i] *= rhs;

        return *this;
    }

    Vector &operator-=(const Vector &rhs)
    {
        for (size_t i = 0; i < NDIM; ++i)
            coords[i] -= rhs.coords[i];

        return *this;
    }

    Vector &operator*=(const Vector &rhs)
    {
        for (size_t i = 0; i < NDIM; ++i)
            coords[i] *= rhs.coords[i];

        return *this;
    }

    Vector &operator*=(const value &rhs)
    {
        for (size_t i = 0; i < NDIM; ++i)
            coords[i] *= rhs;

        return *this;
    }

    value &operator[](size_t i)
    {
        assert(i < NDIM);
        return coords[i];
    }
    // More to go

private:
    // Private Member functions here (if necessary)

    value coords[NDIM];
    // Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
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
