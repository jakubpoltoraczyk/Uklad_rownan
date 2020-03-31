#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

class Matrix
{
private:
    Vector tab[size];
public:
    Matrix();
    explicit Matrix(const Vector *wsk_tab);
    const Vector & operator [] (int n)const{return tab[n];}
    Vector & operator [] (int n){return tab[n];}
    Vector get_column(int n)const;
    void set_column(const Vector & v, int number);
    void transposition();
    Matrix operator + (const Matrix & m)const;
    Matrix operator - (const Matrix & m)const;
    Matrix operator * (const Matrix & m)const;
    Vector operator * (const Vector & v)const;
    double det()const;
};

std::ostream & operator << (std::ostream & o, const Matrix & m);
std::istream & operator >> (std::istream & i, Matrix & m);

#endif // MATRIX_H
