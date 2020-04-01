#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h" // dolaczenie deklaracji klasy Vector

/* WAZNE - macierz interpretowana wierszowo - np. wektor(x1,y1,z1) sklada sie na pierwszy wiersz macierzy */
/* WAZNE - macierz pobierana jest w postaci transponowanej - np. kolumna (x1,x2,x3) sklada sie na pierwszy wiersz pliku */

class Matrix // klasa Matrix opisujaca matematyczna macierz
{
private:
    Vector tab[size]; // tablica wektorow ktore skladaja sie na macierz
public:
    Matrix(); // konstruktor domyslny klasy Matrix
    explicit Matrix(const Vector *wsk_tab); // jednoparametrowy konstruktor klasy Matrix przyjmujacy tablice obiektow klasy Vector
    const Vector & operator [] (int n)const; // przeciazony operator [] (dostep do poszczegolnych wektorow - wersja const)
    Vector & operator [] (int n); // przeciazony operator [] (dostep do poszczegolnych wektorow - wersja bez const)
    Vector get_column(int n)const; // metoda zwracajaca dowolna kolumne macierzy
    void set_column(const Vector & v, int number); // metoda ustawiajaca podana kolumne macierzy podanym wektorem
    void transposition(); // metoda wykonujaca transpozycje macierzy
    Matrix operator + (const Matrix & m)const; // metoda dodajaca do siebie dwie macierze
    Matrix operator - (const Matrix & m)const; // metoda odejmujaca od siebie dwie macierze
    Matrix operator * (const Matrix & m)const; // metoda mnozaca przez siebie dwie macierze
    Vector operator * (const Vector & v)const; // metoda mnozaca macierz przez wektor
    double det()const; // metoda liczaca wyznacznik macierzy
};

/* Funkcje bezposrednio zwiazane z klasa Matrix */
std::ostream & operator << (std::ostream & o, const Matrix & m); // przeciazenie operatora << dla macierzy
std::istream & operator >> (std::istream & i, Matrix & m); // przeciazenie operatora >> dla macierzy

#endif // MATRIX_H
