#include "uklad.h"
#include <iostream>
#include <fstream>

int main(void)
{
    using std::endl;
    using std::cout;
    using std::cin;
    std::ifstream plik;
    plik.open("plik");
    Macierz one;
    Vector two,result;
    plik >> one >> two;
    result=one*two;
    cout << endl << result << endl;
    plik.close();
    return 0;
}