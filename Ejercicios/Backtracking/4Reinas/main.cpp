
// Casco_Once

#include <iostream>
#include <vector>
using namespace std;
#define N 4

void imprimeTablero(vector<vector<int>> tablero){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << tablero[i][j] << ' ';
        cout << endl;
    }
}

int valida(vector<vector<int>> tablero, int fila, int columna){
    for(int i = 0; i < fila; i++) if(tablero[i][columna]) return 0;
    for(int i = fila, j = columna; i >= 0 && j >= 0; i--, j--) if(tablero[i][j] == 1) return 0;
    for(int i = fila, j = columna; i >= 0 && j < N; i--, j++) if(tablero[i][j] == 1) return 0;
    return 1;
}

int resuelve(vector<vector<int>> &tablero, int fila){
    if(fila == N) return 1;
    for(int i = 0; i < N; i++){
        if(valida(tablero, fila, i)){
            tablero[fila][i] = 1;
            if(resuelve(tablero, fila+1)) return 1;
            tablero[fila][i] = 0;
        }
    }
    return 0;
}

int main (void){
    vector<vector<int>> tablero(N, vector<int>(N, 0));
    if(resuelve(tablero, 0)){
        cout << "ENCONTRO: " << endl;
        imprimeTablero(tablero);
    }else cout << "NO ENCONTRO" << endl;
    return 0;
}