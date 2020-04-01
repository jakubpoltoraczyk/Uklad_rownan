#include "matrix.h" // dolaczenie klasy Matrix

/* Jest to plik z definicjami wszelkich funkcji zwiazanymi z klasa Matrix */

Matrix::Matrix() // konstruktor domyslny dla Matrix
{
    for(int i=0;i<size;++i) // ustawienie poszczegolnych wierszy macierzy domyslnymi obiektami klasy Vector
        tab[i]=Vector();
}

Matrix::Matrix(const Vector * wsk_tab) // konstruktor jednoparametrowy klasy Matrix przyjmujacy tablice obiektow klasy Vector
{
    for(int i=0;i<size;++i) // ustawienie poszczegolnych wierszy macierzy obiektami klasy Vector
        tab[i]=wsk_tab[i];
}

const Vector & Matrix::operator [] (int n)const // metoda dostepu do poszczegolnych wektorow macierzy - const
{
    if(n<size&&n>=0) // sprawdzenie poprawnosci indeksu
        return tab[n];
    std::cerr << "Blad: zly indeks macierzy\n";
    exit(1); // komunikat i wyjscie jesli zly indeks
}

Vector & Matrix::operator [] (int n) // metoda dostepu do poszczegolnych wektorow macierzy - bez const
{
    if(n<size&&n>=0) // sprawdzenie poprawnosci indeksu
        return tab[n];
    std::cerr << "Blad: zly indeks macierzy\n";
    exit(1); // komunikat i wyjscie jesli zly indeks
}

Vector Matrix::get_column(int n)const // pobranie kolumny macierzy
{
    double value[size]; // tablica pomocnicza sluzaca do przechowania poszczegolnych skladowych kolumny
    for(int i=0;i<size;++i) // zapisanie do tablicy poszczegolnych skladowych wybranej kolumny
        value[i]=tab[i][n];
    return Vector(value); // zwrocenie odpowiednej kolumny w postaci wektora
}

void Matrix::set_column(const Vector & v, int number) // metoda ustawiajaca kolumne innym wektorem
{
    transposition(); // dokonanie transpozycji tak by kolumny macierzy staly sie jej wierszami
    tab[number]=v; // zamiana kolumny na inny wektor
    transposition(); // powrotna transpozycja macierzy
}

void Matrix::transposition() // metoda wykonujaca transpozycje macierzy
{
    Matrix pom=*this; // macierz pomocnicza, ktora jest kopia prawdziwej
    for(int i=0;i<size;++i) // zamiana wierszy na kolumny
        tab[i]=pom.get_column(i);
}

Matrix Matrix::operator + (const Matrix & m)const // metoda dodajaca do siebie dwie macierze
{
    Matrix pom; // pomocnicza macierz
    for(int i=0;i<size;++i) // w podwojnej petli dodawanie do siebie poszczegolnych elementow macierzy
        for(int j=0;j<size;++j)
            pom[i][j]=m[i][j]+tab[i][j];
    return pom; // zwrocenie nowej zsumowanej macierzy
}

Matrix Matrix::operator - (const Matrix & m)const // metoda odejmujaca od siebie dwie macierze
{
    Matrix pom; // pomocnicza macierz
    for(int i=0;i<size;++i) // w podwojnej petli odejmowanie od siebie poszczegolnych elementow macierzy
        for(int j=0;j<size;++j)
            pom[i][j]=m[i][j]-tab[i][j];
    return pom; // zwrocenie nowej zroznicowanej macierzy
}

Matrix Matrix::operator * (const Matrix & m)const // metoda mnozaca dwie macierze przez siebie
{
    Matrix pom; // pomocnicza macierz
    for(int i=0;i<size;++i) // poszczegolne elementy nowej macierzy jako iloczyn kolejnych wierszy i kolumn
        for(int j=0;j<size;++j)
            pom[i][j]=tab[i]*m.get_column(j);
    return pom; // zwrocenie nowego obiektu
}

Vector Matrix::operator * (const Vector & v)const // metoda mnozaca macierz przez wektor
{
    double pom[size]; // tablica pomocnicza
    for(int i=0;i<size;++i) // mnozenie podanego wektora i odpowiednich wierszy macierzy
        pom[i]=tab[i]*v;
    return Vector(pom); // zwrocenie powstalego na skutek mnozenia wektora (powstalego za pomoca konstruktora)
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

std::ostream & operator << (std::ostream & o, const Matrix & m) // przeciazenie operatora << dla obiektow klasy Matrix
{
    for(int i=0;i<size-1;++i) // wyswietlenie poszczegolnych wektorow macierzy za pomoca operatora << dla klasy Vector
        o << m[i] << std::endl;
    o << m[size-1]; // ostatni wiersz wyswietlany bez znaku nowej linii w celu zachowania niezmiennosci kodu zewnetrznego
    return o; // zwrocenie obiektu klasy ostream
}

std::istream & operator >> (std::istream & i, Matrix & m) // przeciazenie operatora >> dla obiektow klasy Matrix
{
    Vector pom[size]; // utworzenie pomocniczej tablicy obiektow klasy Vector
    for(int n=0;n<size;++n) // pobranie kolejnych obiektow Vector za pomoca przeciazonego dla nich operatora >> 
        i >> pom[n];
    m=Matrix(pom); // przypisanie nowej macierzy powstalej za pomoca konstruktora do obecnej macierzy
    m.transposition(); // wykonanie transpozycji ze wzgledu na pobieranie macierzy w postaci transponowanej
    return i; // zwrocenie obiektu klasy istream
}