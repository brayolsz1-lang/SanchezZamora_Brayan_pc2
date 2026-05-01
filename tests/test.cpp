#include <iostream>
#include <vector>
#include "mike_feet.h"

int main() {
    // Prueba 1: n=1
    std::vector<long long> a1 = {42};
    auto r1 = maxStrengthForAllSizes(a1);
    std::cout << "n=1: " << r1[0] << " (esperado 42)\n";
    
    // Prueba 2: todos iguales
    std::vector<long long> a2 = {5,5,5,5};
    auto r2 = maxStrengthForAllSizes(a2);
    std::cout << "iguales: ";
    for (long long x : r2) std::cout << x << " ";
    std::cout << "\n";
    
    return 0;
}