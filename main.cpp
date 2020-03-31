#include "system.h"
#include <iostream>
#include <fstream>

int main(void)
{
    using std::endl;
    using std::cout;
    using std::cin;
    std::ifstream plik;
    plik.open("plik");
    System rownanie;
    plik >> rownanie;
    cout << rownanie << endl;
    plik.close();
    return 0;
}