#include "vector.h" // dolaczenie klasy Vector

/* Jest to plik z definicjami wszelkich funkcji zwiazanymi z klasa Vector */

Vector::Vector() // konstruktor domyslny dla klasy Vector
{
    for(int i=0;i<size;++i) // ustawienie wszystkich skladowych wektora na zera
        data[i]=0.0;
}

Vector::Vector(const double * tab) // konstruktor przyjmujacy tablice jako swoj argument
{
    for(int i=0;i<size;++i) // ustawienie odpowiednich skladowych wektora elementami tablicy
        data[i]=tab[i];
}

double Vector::operator [] (int n)const // metoda dostepu do poszczeglonych skladowych wektora (przeciazony [] wersja const)
{
    if(n<size&&n>=0) // sprawdzenie poprawnosci indeksu
        return data[n]; // zwrocenie odpowiedniej skladowej
    std::cerr << "Blad: zly indeks wektora\n";
    exit(1); // w przypadku bledu komunikat i wyjscie
}

double & Vector::operator [] (int n) // metoda dostepu do poszczeglonych skladowych wektora (przeciazony [] wersja nie const)
{
    if(n<size&&n>=0) // sprawdzenie poprawnosci indeksu
        return data[n]; // zwrocenie odpowiedniej skladowej
    std::cerr << "Blad: zly indeks wektora\n";
    exit(1); // w przypadku bledu komunikat i wyjscie
}

Vector Vector::operator + (const Vector & v) const // metoda dodajaca do siebie dwa wektory
{
    double tab[size]; // tablica pomocnicza do zapamietywania poszczegolnych sum skladowych dwoch wektorow
    for(int i=0;i<size;++i) // dodawanie do siebie poszczegolnych skladowych wektorow
        tab[i]=data[i]+v[i];
    return Vector(tab); // zwrocenie obiektu klasy Vector powstalego z sumy przekazanych dwoch wektorow (przy pomocy konstruktora)
}

Vector Vector::operator - (const Vector & v) const // metoda odejmujaca od siebie dwa wektory
{
    double tab[size]; // tablica pomocnicza do zapamietywania poszczegolnych sum skladowych dwoch wektorow
    for(int i=0;i<size;++i) // odejmowanie siebie poszczegolnych skladowych wektorow
        tab[i]=data[i]-v[i];
    return Vector(tab); // zwrocenie obiektu klasy Vector powstalego z sumy przekazanych dwoch wektorow (przy pomocy konstruktora)
}

double Vector::operator * (const Vector & v)const // metoda mnozaca przez siebie dwa wektory (wynikiem jest liczba typu double)
{
    double sum=0.0; // zmienna do zapamietywania wyniku
    for(int i=0;i<size;++i) // zgodnie ze wzorem sumowanie iloczynu tych samych skladowych wektorow
        sum+=data[i]*v[i];
    return sum; // zwrocenie wyniku
}

Vector Vector::operator * (double n)const // metoda mnozaca wektor przez liczbe typu double
{
    double tab[size]; // tablica pomocnicza sluzaca do zapamietania poszczegolnych nowych skladowych wektora
    for(int i=0;i<size;++i) // mnozenie poszczeglonych skladowych
        tab[i]=data[i]*n;
    return Vector(tab); // zwrocenie nowego przemnozonego obiektu typu Vector za pomoca konstruktora
}

std::ostream & operator << (std::ostream & o, const Vector & v) // przeciazenie operatora << dla klasy Vector
{
    for(int i=0;i<size;++i) // wypisywanie w petli poszczegolnych skladowych wektora
        o << v[i] << " ";
    return o; // zwrocenie obiektu klasy ostream
}

std::istream & operator >> (std::istream & i, Vector & v) // przeciazenie operatora >> dla klasy Vector
{
    for(int n=0;n<size;++n) // podanie nowych skladowych wektora
        i >> v[n];
    return i; // zwrocenie obiektu klasy istream
}