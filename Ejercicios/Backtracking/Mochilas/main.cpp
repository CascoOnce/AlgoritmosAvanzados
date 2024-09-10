
// Casco_Once

#include <iostream>
#include <vector>
using namespace std;

int empaca(int i, int n, int peso, vector<int> paquetes){
    if(i == n or peso < 0) return 0;
    if(paquetes[i] == peso) return 1;
    if(empaca(i + 1, n, peso - paquetes[i], paquetes)) return 1;
    else return empaca(i + 1, n, peso, paquetes);
}

int main (void){
    int n = 4, peso = 9;
    vector<int> paquetes = {1, 3, 12, 5};
    cout << empaca(0, n, peso, paquetes);
    return 0;
}