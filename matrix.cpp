#include "matrix.h"

Matrix::Matrix()
{
    for(int i=0;i<size;++i)
        tab[i]=Vector();
}

Matrix::Matrix(const Vector * wsk_tab)
{
    for(int i=0;i<size;++i)
        tab[i]=wsk_tab[i];
}

Vector Matrix::get_column(int n)const
{
    double value[size];
    for(int i=0;i<size;++i)
        value[i]=tab[i][n];
    return Vector(value);
}

void Matrix::set_column(const Vector & v, int number)
{
    transposition();
    tab[number]=v;
    transposition();
}

void Matrix::transposition()
{
    Matrix pom=*this;
    for(int i=0;i<size;++i)
        tab[i]=pom.get_column(i);
}

Matrix Matrix::operator + (const Matrix & m)const
{
    Matrix pom;
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            pom[i][j]=m[i][j]+tab[i][j];
    return pom;
}

Matrix Matrix::operator - (const Matrix & m)const
{
    Matrix pom;
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            pom[i][j]=m[i][j]-tab[i][j];
    return pom;
}

Matrix Matrix::operator * (const Matrix & m)const
{
    Matrix pom;
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            pom[i][j]=tab[i]*m.get_column(j);
    return pom;
}

Vector Matrix::operator * (const Vector & v)const
{
    double pom[size];
    for(int i=0;i<size;++i)
        pom[i]=tab[i]*v;
    return Vector(pom);
}

double Matrix::det()const
{
    using namespace std;
    double value,result=1;
    Matrix pom=*this;
    for(int i=0;i<size-1;++i)
    {
        for(int j=i+1;j<size;++j)
        {
            value=pom.tab[j][i]/pom.tab[i][i];
            pom.tab[j]=pom.tab[j]-(pom.tab[i]*value);
        }
    }
    for(int i=0;i<size;++i)
        result*=pom[i][i];
    return result;
}

std::ostream & operator << (std::ostream & o, const Matrix & m)
{
    for(int i=0;i<size-1;++i)
        o << m[i] << std::endl;
    o << m[size-1];
    return o;
}

std::istream & operator >> (std::istream & i, Matrix & m)
{
    Vector pom[size];
    for(int n=0;n<size;++n)
        i >> pom[n];
    m=Matrix(pom);
    m.transposition();
    return i;
}