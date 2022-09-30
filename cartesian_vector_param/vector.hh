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

    int get_coord(int i) const;

    Vector(const value v[]);

    Vector(std::initializer_list<value> l);

    Vector operator+(const Vector &other) const;

    // Dot product
    value operator*(const Vector &other) const;

    // Dot product with a scalar
    Vector operator*(const int rhs) const;

    Vector operator-(const Vector &other) const;

    // Public Member functions here
    Vector &operator+=(const Vector &rhs);

    Vector &operator+=(const int rhs);

    Vector &operator-=(const Vector &rhs);

    Vector &operator*=(const Vector &rhs);

    Vector &operator*=(const value &rhs);

    value &operator[](size_t i);
    // More to go

private:
    // Private Member functions here (if necessary)

    value coords[NDIM];
    // Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
std::ostream &operator<<(std::ostream &os, const Vector &v);
