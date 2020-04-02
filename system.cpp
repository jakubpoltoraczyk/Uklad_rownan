#include "system.h" // dolaczenie klasy System

/* Jest to plik z definicjami wszelkich funkcji zwiazanymi z klasa System */

Vector System::solve()const // metoda rozwiazujaca rownanie i podajaca jego wynik w postaci wektora
{
    Matrix pom=get_matrix(); // pomocnicza macierz bedaca kopia macierzy rownania
    Vector result; // pomocniczy wektor wynikowy
    double det[size]; // pomocnicza tablica, ktorej skladowe to dodatkowe wyznacznika rownania
    double det_main=get_matrix().det(); // zmienna okreslajaca wyznacznik glowny rownania
    if(std::abs(det_main)>epsilon) // jesli glowny wyznacznik nie jest zerem
    {
        for(int i=0;i<size;++i) // obliczanie poszczegolnych skladowych wektora wynikowego
        {
            pom.set_column(get_vector(),i); // zamiana kolumny z wektorem wyrazow wolnych w macierzy pomocniczej
            det[i]=pom.det(); // obliczenie dodatkowego wyznacznika o numerze danej skladowej
            det[i]/=det_main; // podzielenie go przez wyznacznik glowny (otrzymanie rezultatu danej skladowej wektora wynikowego)
            pom=get_matrix(); // powrotne ustawienie macierzy pomocniczej jako kopii macierzy glownej rownania
        }
    }
    else // jesli glowny wyznacznik jest zerem
    {
        std::cerr << "Glowny wyznacznik macierzy jest rowny zero. Brak rozwiazania." << std::endl;
        exit(2); // komunikat i wyjscie z programu
    }
    return Vector(det); // zwrocenie wektora wynikowego
}

std::ostream & operator << (std::ostream & o, const System & u) // przeciazenie operatora << dla klasy System
{
    using std::endl;
    o << "Macierz:\n\n" << u.get_matrix() << endl << endl; // wyswietlenie macierzy rownania
    o << "Wektor wyrazow wolnych:\n\n" << u.get_vector() << endl << endl; // wyswietlenie wyrazow wolnych rownania
    o << "Rozwiazanie:\n\n" << u.solve() << endl << endl; // wyswietlenie wektora wynikowego rownania
    o << "Wektor bledu:\n\n" << u.vector_mistake() << endl << endl; // wyswietlenie wektora bledu
    o << "Wartosc bledu:\n\n" << u.value_of_mistake() << endl << endl;  // wyswietlenie wartosci bledu
    return o; // zwrocenie obiektu klasy ostream
}

std::istream & operator >> (std::istream & i, System & u) // przeciazenie operatora >> dla klasy System
{
    Matrix pom_mat; // pomocnicza macierz
    Vector pom_vec; // pomocniczy wektor
    i >> pom_mat; // pobranie macierzy za pomoca przeciazonego dla niej operatora >> 
    i >> pom_vec; // pobranie wektora za pomoca przeciazonego dla niego operatora >> 
    u=System(pom_mat,pom_vec); // przypisanie nowego ukladu rownan do orginalu za pomoca konstruktora
    return i; // zwrocenie obiektu klasy istream
}