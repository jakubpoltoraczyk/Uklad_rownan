#ifndef VECTOR_H
#define VECTOR_H

#include "const_value.h" // dolaczenie stalych wartosci
#include <iostream>
#include <cmath>

class Vector // Klasa Vector opisujaca matematyczny wektor
{
private:
    double data[size]; // tablica sluzaca do przechowywania skladowych wektora
public:
    Vector(); // konstruktor domyslny
    explicit Vector(const double * tab); // konstruktor przyjmujacy jako argument tablice wartosci typu double
    double lenght() const; // metoda zwracajaca dlugosc wektora
    double operator [] (int n) const; // przeciazony operator [] (dostep do skladowych wektora - wersja const)
    double & operator [] (int n); // przeciazony operator [] (dostep do skladowych wektora - wersja bez const)
    Vector operator + (const Vector & v) const; // metoda dodajaca do siebie dwa wektory
    Vector operator - (const Vector & v) const; // metoda odejmujaca od siebie dwa wektory
    double operator * (const Vector & v)const; // metoda mnozaca ze soba dwa wektory
    Vector operator * (double n)const; // metoda mnozaca wektor przez wartosc typu double
};

/* Funkcje bezposrednio zwiazane z klasa Vector */
std::ostream & operator << (std::ostream & o, const Vector & v); // przeciazenie operatora << dla klasy Vector 
std::istream & operator >> (std::istream & i, Vector & v); // przeciazenie operatora >> dla klasy

#endif //VECTOR_H