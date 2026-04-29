#include <iostream>
#include <vector>
#include "mike_feet.h"

using namespace std;

int main() {
    
    
    vector<long long> ejemplo = {1, 2, 3, 4, 5, 4, 3, 2, 1, 6};
    vector<long long> resultado = maxStrengthForAllSizes(ejemplo);
    
    cout << "Resultado: ";
    for (long long x : resultado) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}