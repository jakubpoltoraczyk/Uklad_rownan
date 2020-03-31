#include "vector.h"

Vector::Vector()
{
    for(int i=0;i<size;++i)
        data[i]=0.0;
}

Vector::Vector(const double * tab)
{
    for(int i=0;i<size;++i)
        data[i]=tab[i];
}

double Vector::lenght() const
{
    double sum=0.0;
    for(int i=0;i<size;++i)
        sum+=data[i]*data[i];
    return sqrt(sum);
}

Vector Vector::operator + (const Vector & v) const
{
    double tab[size];
    for(int i=0;i<size;++i)
        tab[i]=data[i]+v[i];
    return Vector(tab);
}

Vector Vector::operator - (const Vector & v) const
{
    double tab[size];
    for(int i=0;i<size;++i)
        tab[i]=data[i]-v[i];
    return Vector(tab);
}

double Vector::operator * (const Vector & v)const
{
    double sum=0.0;
    for(int i=0;i<size;++i)
        sum+=data[i]*v[i];
    return sum;
}

Vector Vector::operator * (double n)const
{
    double tab[size];
    for(int i=0;i<size;++i)
        tab[i]=data[i]*n;
    return Vector(tab);    
}

std::ostream & operator << (std::ostream & o, const Vector & v)
{
    for(int i=0;i<size;++i)
        o << v[i] << " ";
    return o;
}

std::istream & operator >> (std::istream & i, Vector & v)
{
    double tab[size];
    for(int n=0;n<size;++n)
        i >> tab[n];
    v=Vector(tab);
    return i;
}