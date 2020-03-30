#include "uklad.h"

std::ostream & operator << (std::ostream & o, const Uklad & u)
{
    o << "Macierz: " << u.get_macierz() << std::endl;
    o << "Wektor wyrazow wolnych: " << u.get_vector();
    return o;
}

std::istream & operator >> (std::istream & i, Uklad & u)
{
    Macierz pom_mac;
    Vector pom_vec;
    i >> pom_mac;
    i >> pom_vec;
    u=Uklad(pom_mac,pom_vec);
    return i;
}