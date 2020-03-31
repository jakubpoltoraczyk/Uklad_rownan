#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

const int size = 3;

class Vector
{
private:
    double data[size];
public:
    Vector();
    explicit Vector(const double * tab);
    double lenght() const;
    const double & operator [] (int n) const {return data[n];}
    double & operator [] (int n) {return data[n];}
    Vector operator + (const Vector & v) const;
    Vector operator - (const Vector & v) const;
    double operator * (const Vector & v)const;
    Vector operator * (double n)const;
};

std::ostream & operator << (std::ostream & o, const Vector & v);
std::istream & operator >> (std::istream & i, Vector & v);

#endif //VECTOR_H