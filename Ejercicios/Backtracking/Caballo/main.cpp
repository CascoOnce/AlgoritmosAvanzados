
// Casco_Once

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#define N 8

int movX[] = {2, 1, -1, -2, -2, -1, 1, 2};
int movY[] = {1, 2, 2, 1, -1, -2, -2, -1};

void imprimeTablero(vector<vector<int>> tablero){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << setw(3) << tablero[i][j] << ' ';
        cout << endl;
    }
}

int valida(vector<vector<int>> &tablero, int x, int y){
    if(x < N && y < N && x >= 0 && y >= 0 && tablero[x][y] == -1) return 1;
    else return 0;
}

int resuelve(vector<vector<int>> &tablero, int fila, int columna, int valor){
    if(valor == N*N) return 1;
    for(int i = 0; i < 8; i++){
        int nx = fila + movX[i], ny = columna + movY[i];
        if(valida(tablero, nx, ny)){
            tablero[nx][ny] = valor;
            if(resuelve(tablero, nx, ny, valor + 1)) return 1;
            tablero[nx][ny] = -1;
        }
    }
    return 0;
}

int main (void){
    vector<vector<int>> tablero(N, vector<int> (N, -1));
    tablero[0][0] = 0;
    if(resuelve(tablero, 0, 0, 1)){
        cout << "ENCONTRO: " << endl;
        imprimeTablero(tablero);
    }else cout << "NO" << endl;
    return 0;
}