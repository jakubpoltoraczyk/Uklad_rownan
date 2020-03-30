#ifndef MACIERZ_H
#define MACIERZ_H

#include "wektor.h"

class Macierz
{
private:
    Vector tab[size];
public:
    Macierz();
    explicit Macierz(const Vector *wsk_tab);
    const Vector & operator [] (int n)const{return tab[n];}
    Vector & operator [] (int n){return tab[n];}
    Vector get_column(int n)const;
    void transposition();
    Macierz operator + (const Macierz & m)const;
    Macierz operator - (const Macierz & m)const;
    Macierz operator * (const Macierz & m)const;
    Vector operator * (const Vector & v)const;
};

std::ostream & operator << (std::ostream & o, const Macierz & m);
std::istream & operator >> (std::istream & i, Macierz & m);

#endif // MACIERZ_H
