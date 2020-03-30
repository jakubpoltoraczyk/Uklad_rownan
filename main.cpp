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
    Uklad rownanie;
    plik >> rownanie;
    cout << rownanie << endl;
    return 0;
}