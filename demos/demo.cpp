#include <iostream>
#include <vector>
#include "mike_feet.h"

int main() {
    std::vector<long long> ejemplo = {1,2,3,4,5,4,3,2,1,6};
    auto res = maxStrengthForAllSizes(ejemplo);
    for (long long x : res) std::cout << x << " ";
    return 0;
}