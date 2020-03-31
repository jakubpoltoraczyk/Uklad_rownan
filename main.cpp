#include "system.h"
#include <iostream>
#include <fstream>

int main(void)
{
    std::ifstream plik;
    plik.open("plik");
    System rownanie;
    plik >> rownanie;
    std::cout << rownanie << std::endl;
    plik.close();
    return 0;
}