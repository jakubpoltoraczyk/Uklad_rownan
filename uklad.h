#ifndef UKLAD_H
#define UKLAD_H

#include "wektor.h"
#include "macierz.h"

class Uklad
{
private:
    Macierz mac;
    Vector vec;
public:
    Uklad(): mac(Macierz()), vec(Vector()) {}
    Uklad(const Macierz & m, const Vector & v): mac(m), vec(v) {}
    const Macierz & get_macierz() const {return mac;}
    const Vector & get_vector() const {return vec;}
};

std::ostream & operator << (std::ostream & o, const Uklad & u);
std::istream & operator >> (std::istream & i, Uklad & u);

#endif // UKLAD_H