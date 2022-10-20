#include "vector.hh"

Vector::Vector(Vector const &v)
{
    size_ = v.size_;
    coords = std::make_unique<value[]>(size_);
    for (size_t i = 0; i < size_; ++i)
        coords[i] = v.coords[i];
}

Vector &Vector::operator=(Vector const &v)
{
    size_ = v.size_;
    coords = std::make_unique<value[]>(size_);
    for (size_t i = 0; i < size_; ++i)
        coords[i] = v.coords[i];
    return *this;
}

Vector::Vector(size_t N)
{
    coords = std::make_unique<value[]>(N);
    size_ = N;
    for (size_t i = 0; i < N; i++)
        coords[i] = 0;
}

Vector::Vector(std::initializer_list<value> l)
{
    coords = std::make_unique<value[]>(l.size());
    size_ = l.size();
    for (size_t i = 0; i < l.size(); i++)
        coords[i] = *(l.begin() + i);
}

size_t Vector::size() const
{
    return size_;
}

// Public Member functions here
Vector &Vector::operator+=(const Vector &rhs)
{
    if (size() != rhs.size())
        throw std::runtime_error("Incompatible size");

    for (size_t i = 0; i < size(); ++i)
        coords[i] += rhs.coords[i];
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
    if (size() != rhs.size())
        throw std::runtime_error("Incompatible size");

    for (size_t i = 0; i < size(); ++i)
        coords[i] -= rhs.coords[i];
    return *this;
}

Vector &Vector::operator+=(value v)
{
    for (size_t i = 0; i < size(); ++i)
        coords[i] += v;
    return *this;
}

Vector &Vector::operator*=(value v)
{
    for (size_t i = 0; i < size(); ++i)
        coords[i] *= v;
    return *this;
}

Vector Vector::operator+(const Vector &rhs) const
{
    if (size() != rhs.size())
        throw std::runtime_error("Incompatible size");

    Vector v = Vector(size());
    for (size_t i = 0; i < size(); ++i)
        v.coords[i] = coords[i] + rhs.coords[i];
    return v;
}

Vector Vector::operator+(value v) const
{
    Vector v2 = Vector(size());
    for (size_t i = 0; i < size(); ++i)
        v2.coords[i] = coords[i] + v;
    return v2;
}

value Vector::operator*(const Vector &rhs) const
{
    if (size() != rhs.size())
        throw std::runtime_error("Incompatible size");

    value sum = 0;
    for (size_t i = 0; i < size(); ++i)
        sum += coords[i] * rhs.coords[i];

    return sum;
}

Vector Vector::operator*(value v) const
{
    Vector v2 = Vector(size());
    for (size_t i = 0; i < size(); ++i)
        v2.coords[i] = coords[i] * v;
    return v2;
}

value &Vector::operator[](size_t i)
{
    if (i >= size())
        throw std::runtime_error("Out of bounds");
    return coords[i];
}

value Vector::operator[](size_t i) const
{
    if (i >= size())
        throw std::runtime_error("Out of bounds");
    return coords[i];
}

// Non-member functions operators
Vector operator*(value lhs, const Vector &rhs)
{
    return rhs * lhs;
}

Vector operator+(value lhs, const Vector &rhs)
{
    return rhs + lhs;
}

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << "{";
    for (size_t i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ",";
    }
    os << "}";
    return os;
}
