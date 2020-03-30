#include "macierz.h"

Macierz::Macierz()
{
    for(int i=0;i<size;++i)
        tab[i]=Vector();
}

Macierz::Macierz(const Vector * wsk_tab)
{
    for(int i=0;i<size;++i)
        tab[i]=wsk_tab[i];
}

Vector Macierz::get_column(int n)const
{
    double value[size];
    for(int i=0;i<size;++i)
        value[i]=tab[i][n];
    return Vector(value);
}

void Macierz::transposition()
{
    Macierz pom=*this;
    for(int i=0;i<size;++i)
        tab[i]=pom.get_column(i);
}

Macierz Macierz::operator + (const Macierz & m)const
{
    Macierz pom;
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            pom[i][j]=m[i][j]+tab[i][j];
    return pom;
}

Macierz Macierz::operator - (const Macierz & m)const
{
    Macierz pom;
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            pom[i][j]=m[i][j]-tab[i][j];
    return pom;
}

Macierz Macierz::operator * (const Macierz & m)const
{
    Macierz pom;
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            pom[i][j]=tab[i]*m.get_column(j);
    return pom;
}

Vector Macierz::operator * (const Vector & v)const
{
    double pom[size];
    for(int i=0;i<size;++i)
        pom[i]=0.0;
    for(int i=0;i<size;++i)
    {
        pom[i]=tab[i]*v;
    }
    return Vector(pom);
}

std::ostream & operator << (std::ostream & o, const Macierz & m)
{
    for(int i=0;i<size;++i)
        o << std::endl << m[i];
    return o;
}

std::istream & operator >> (std::istream & i, Macierz & m)
{
    Vector pom[size];
    for(int n=0;n<size;++n)
        i >> pom[n];
    m=Macierz(pom);
    return i;
}