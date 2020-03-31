#include "system.h"

Vector System::solve()const
{
    Matrix pom=get_matrix();
    Vector result;
    double det[size];
    double det_main=get_matrix().det();
    for(int i=0;i<size;++i)
    {
        pom.set_column(get_vector(),i);
        det[i]=pom.det();
        det[i]/=det_main;
        pom=get_matrix();
    }
    return Vector(det);
}

std::ostream & operator << (std::ostream & o, const System & u)
{
    using std::endl;
    o << "Macierz:\n\n" << u.get_matrix() << endl << endl;
    o << "Wektor wyrazow wolnych:\n\n" << u.get_vector() << endl << endl;
    o << "Rozwiazanie (x,y,z):\n\n" << u.solve() << endl << endl;
    o << "Wektor bledu:\n\n" << u.vector_mistake() << endl << endl;
    o << "Wartosc bledu:\n\n" << u.value_of_mistake() << endl << endl; 
    return o;
}

std::istream & operator >> (std::istream & i, System & u)
{
    Matrix pom_mat;
    Vector pom_vec;
    i >> pom_mat;
    i >> pom_vec;
    u=System(pom_mat,pom_vec);
    return i;
}