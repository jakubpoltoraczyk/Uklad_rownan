#include "system.h" // dolaczenie klasy System, Matrix i Vector
#include <iostream>
#include <fstream>

int main(void)
{
    std::ifstream plik;
    plik.open("plik"); // otwarcie pliku z rownaniem do odczytu
    System rownanie; // utworzenie obiektu klasy System
    plik >> rownanie; // pobranie rownania z pliku do obiektu klasy System
    std::cout << rownanie << std::endl; // wyswietlenie danych o podanym rownaniu
    plik.close(); // zamkniecie pliku
    return 0; // zwrocenie zera w przypadku poprawnego zamkniecia programu
}