#ifndef SYSTEM_H
#define SYSTEM_H

#include "matrix.h" // dolaczenie klasy Matrix

class System // klasa System opisujaca matematyczne rownanie
{
private:
    Matrix mat; // macierz
    Vector vec; // wektor wyrazow wolnych
public:
    System(): mat(), vec() {} // konstruktor domyslny ustawiajacy macierz i wektor wyrazow wolnych na domyslne wartosci
    System(const Matrix & m, const Vector & v): mat(m), vec(v) {} // konstruktor przyjmujacy konkretna macierz i konkretny wektor
    const Matrix & get_matrix() const {return mat;} // metoda zwracajaca macierz rownania
    const Vector & get_vector() const {return vec;} // metoda zwracajaca wektor wyrazow wolnych rownania
    Vector solve()const; // metoda rozwiazujaca rownanie za pomoca metody Cramera
    Vector vector_mistake() const {return get_matrix()*solve()-get_vector();} // metoda wyznaczajaca wektor bledu rownania
    double value_of_mistake() const {return vector_mistake().lenght();} // metoda wyznaczajaca wartosc bledu rownania (dlugosc wektora bledu)
};

/* Funkcje bezposrednio zwiazane z klasa System */
std::ostream & operator << (std::ostream & o, const System & u); // przeciazony operator << dla klasy System
std::istream & operator >> (std::istream & i, System & u); // przeciazony operator >> dla klasy System

#endif // SYSTEM_H