
// Casco_Once

#include <iostream>
#include <vector>
using namespace std;

void imprimir(vector<int> &solucion){
    for(int aux: solucion) cout << aux << ' ';
    cout << endl;
}

int termina(vector<int> &solucion, int k){
    if(!solucion.empty() && solucion.size() > 1 && solucion[solucion.size() - 1] > solucion[solucion.size() - 2] + k) return 1;
    return 0;
}

int resolver(vector<int> &carne, vector<int> &solucion, int peso, int k, int pos){
    if(termina(solucion, k)) return 0;
    if(peso == 0){
        imprimir(solucion);
        return 1;
    }
    if(peso < 0 || pos >= carne.size()) return 0;
    if(carne[pos] != 0){
        solucion.push_back(carne[pos]);
        if(resolver(carne, solucion, peso - carne[pos], k, pos + 1)){
            carne[pos] = 0;
            return 1;
        }else solucion.pop_back();
    }
    return resolver(carne, solucion, peso, k, pos + 1);
}

void vacaLola(vector<int> carne, int peso, int k){
    vector<int> solucion;
    while(resolver(carne, solucion, peso, k, 0)){
        solucion.clear();
    }
}

int main (void){
    // Caso_1
    cout << "CASO 1:" << endl;
    vacaLola({2, 8, 9, 6, 7, 6}, 15, 4);
    // Caso_2
    cout << "CASO 2:" << endl;
    vacaLola({2, 8, 9, 6, 7}, 15, 4);
    // Caso_3
    cout << "CASO 3:" << endl;
    vacaLola({2, 8, 9, 6, 7, 6}, 15, 3);
    return 0;
}