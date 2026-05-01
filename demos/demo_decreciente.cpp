#include <iostream>
#include <vector>
#include "mike_feet.h"

int main() {
    std::vector<long long> entrada = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    auto res = maxStrengthForAllSizes(entrada);
    
    std::cout << "Entrada decreciente: ";
    for (long long x : entrada) std::cout << x << " ";
    std::cout << "\nSalida: ";
    for (long long x : res) std::cout << x << " ";
    std::cout << std::endl;
    
    return 0;
}