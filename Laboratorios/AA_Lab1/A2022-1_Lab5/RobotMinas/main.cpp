
// Casco_Once

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#define N 9
#define M 5
#define movs 8

int movY[movs] = {0, 1, 1, 1, 0, -1, -1, -1}, movX[movs] = {1, 1, 0, -1, -1, -1, 0, 1};

void imprimeTablero(vector<vector<char>> almacen){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << setw(3) << almacen[i][j] << ' ';
        cout << endl;
    }
}

void cargaminas(vector<vector<char>> &a) {
    a[0][4]='*', a[2][2]='*', a[4][1]='*', a[4][2]='*', a[4][4]='*', a[5][1]='*', a[5][2]='*';
    a[5][4]='*', a[6][1]='*', a[6][3]='*', a[7][0]='*', a[7][1]='*', a[7][2]='*', a[7][3]='*';
}

int valida(vector<vector<char>> terreno, int x, int y){
    if(x < N && x >= 0 && y < M && y >= 0 && terreno[x][y] == '0') return 1;
    return 0;
}

void chequea(vector<vector<char>> terreno, vector<vector<char>> &solucion, int x, int y){
    int nx, ny;
    for(int i = 0; i < movs; i++){
        nx = x + movX[i], ny = y + movY[i];
        if(valida(solucion, nx, ny) && terreno[nx][ny] == '*') solucion[nx][ny] = '*';
    }
}

int resuelve(vector<vector<char>> terreno, vector<vector<char>> &solucion, int fila, int columna, char actual){
    if(fila == N-1 && columna == M-1){
        imprimeTablero(solucion);
        return 1;
    }
    int nx, ny;
    chequea(terreno, solucion, fila, columna);
    for(int i = 0; i < movs; i++){
        nx = fila + movX[i], ny = columna + movY[i];
        if(valida(solucion, nx, ny)){
            solucion[nx][ny] = actual + 1;
            if(resuelve(terreno, solucion, nx, ny, actual+1)) return 1;
            else solucion[nx][ny] = '0';
        }
    }
    return 0;
}

int main (void){
    vector<vector<char>>  solucion(N, vector<char>(M, '0')), terreno(N, vector<char>(M, '0'));
    cargaminas(terreno);
    solucion[0][0] = 'A';
    resuelve(terreno, solucion, 0, 0, 'A');
    return 0;
}