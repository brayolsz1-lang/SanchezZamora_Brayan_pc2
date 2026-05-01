#include <iostream>
#include <vector>
#include "mike_feet.h"

int main() {
    std::vector<long long> entrada = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto res = maxStrengthForAllSizes(entrada);
    
    std::cout << "Entrada creciente: ";
    for (long long x : entrada) std::cout << x << " ";
    std::cout << "\nSalida: ";
    for (long long x : res) std::cout << x << " ";
    std::cout << std::endl;
    
    return 0;
}