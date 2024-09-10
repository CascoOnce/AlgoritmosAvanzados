
// Casco_Once

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define N 5

void imprimeTablero(vector<vector<int>> almacen){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << setw(3) << almacen[i][j] << ' ';
        cout << endl;
    }
}

int valida(vector<int> datos){
    for(int dato: datos) if(dato != 0) return 0;
    return 1;
}

int valida(vector<int> &datos, int valor){
    for(int i = 0; i < datos.size(); i++){
        if(datos[i] == valor){
            datos[i] = 0;
            return 1;
        }
    }
    return 0;
}

int resuelve(vector<vector<int>> &almacen, vector<int> &datos, int fila, int columna, vector<vector<int>> &solucion){
    if(valida(datos)) return 1;
    if(fila == N or columna == N) return 0;
    bool posibilidad = false;
    if(valida(datos, almacen[fila][columna])){
        solucion[fila][columna] = almacen[fila][columna];
        posibilidad = true;
    }
    if(resuelve(almacen, datos, fila+1, columna, solucion)) return 1;
    if(resuelve(almacen, datos, fila, columna+1, solucion)) return 1;
    if(posibilidad){
        solucion[fila][columna] = 0;
        datos.push_back(almacen[fila][columna]);
    }
    return 0;
}

// A = 1, V = 2, M = 3;

int main (void){
    vector<vector<int>> solucion(N, (vector<int>(N, 0))), almacen = {
        {120, 210, 110, 325, 310},
        {110, 201, 310, 105, 215},
        {201, 320, 350, 305, 101},
        {225, 110, 108, 105, 215},
        {310, 302, 308, 310, 110}
    };
    vector<int> datos = {105, 201, 350, 108};
    if(resuelve(almacen, datos, 0, 0, solucion)){
        cout << "ENCONTRO:" << endl;
        imprimeTablero(solucion);
    }else cout << "NO ENCONTRO" << endl;
    return 0;
}