
// Casco_Once

#include <iostream>
#include <vector>
using namespace std;
#define N 4
#define M 5

int termino(vector<int> productos){
    for(int aux: productos) if(aux != 0) return 0;
    return 1;
}

int valida(int capacidad, int peso){
    if(peso != 0 && capacidad >= peso) return 1;
    return 0;
}

void imprime(vector<int> solucion){
    for(int aux: solucion) cout << aux << ' ';
    cout << endl;
}

int diferente(vector<int> solucion, vector<int> ultimo){
    for(int i = 0; i < M; i++){
        if(solucion[i] != ultimo[i]) return 1;
    }
    return 0;
}

int resuelve(vector<int> &productos, vector<int> &capacidades, 
        int posicion, vector<int> &solucion, vector<int> &ultimo){
    if(termino(productos)){
        if(diferente(solucion, ultimo)){ // Es el flag para no imprimir resultados iguales
            imprime(solucion);
            ultimo = solucion;
        }
        return 0;
    }
    if(posicion >= M || capacidades[posicion] < 0) return 0;
    for(int i = 0; i < N; i++){
        if(valida(capacidades[posicion], productos[i])){
            int peso = productos[i];
            capacidades[posicion] -= peso;
            productos[i] = 0;
            solucion[posicion] += peso;
            if(resuelve(productos, capacidades, posicion, solucion, ultimo)) return 1;
            solucion[posicion] -= peso;
            capacidades[posicion] += peso;
            productos[i] = peso;
            
        }
    }
    if(resuelve(productos, capacidades, posicion + 1, solucion, ultimo)) return 1;
    else return 0;
}

int main(void) {
    vector<int> productos = {2,3,1,4}, capacidades = {3,2,5,1,3}, solucion(5, 0), ultimo = solucion;
    resuelve(productos, capacidades, 0, solucion, ultimo);
    return 0;
}