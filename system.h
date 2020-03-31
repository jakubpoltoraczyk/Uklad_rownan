#ifndef SYSTEM_H
#define SYSTEM_H

#include "vector.h"
#include "matrix.h"

class System
{
private:
    Matrix mat;
    Vector vec;
public:
    System(): mat(), vec() {}
    System(const Matrix & m, const Vector & v): mat(m), vec(v) {}
    const Matrix & get_matrix() const {return mat;}
    const Vector & get_vector() const {return vec;}
    Vector solve()const;
};

std::ostream & operator << (std::ostream & o, const System & u);
std::istream & operator >> (std::istream & i, System & u);

#endif // SYSTEM_H