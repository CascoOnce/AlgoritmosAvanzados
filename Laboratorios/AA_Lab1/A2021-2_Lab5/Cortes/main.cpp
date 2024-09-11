
// Casco_Once

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
#define movs 8
#define movili 4
#define N 5
int movY[movs] = {0, 1, 1, 1, 0, -1, -1, -1}, movX[movs] = {1, 1, 0, -1, -1, -1, 0, 1};
int moviliY[movili] = {0, 1, 0, -1}, moviliX[movili] = {1, 0, -1, 0};

void imprimeTablero(ofstream &file,vector<vector<int>> &almacen){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) file << setw(3) << almacen[i][j] << ' ';
        file << endl;
    }
}

int valida(vector<vector<int>> &terreno, int x, int y){
    if(x < N && x >= 0 && y < N && y >= 0 && terreno[x][y] == 0) return 1;
    return 0;
}

bool comprueba(vector<vector<int>> &mapa, int x, int y){
    for(int i = 0; i < movs; i++){
        int nx = x + movX[i], ny = y + movY[i];
        if(valida(mapa, nx, ny)) return false;
    }
    return true;
}

int comprobarLinea(vector<vector<int>> &mapa, int x, int y, int finX, int finY, int mov){
    if(!valida(mapa, finX, finY)) return 0;
    if(moviliX[mov] > 0) for(int i = 0; i < moviliX[mov]*3; i++) if(mapa[x + i][y] != 0) return 0;
    if(moviliX[mov] < 0) for(int i = 0; i > moviliX[mov]*3; i--) if(mapa[x + i][y] != 0) return 0;
    if(moviliY[mov] > 0) for(int i = 0; i < moviliY[mov]*3; i++) if(mapa[x][y + i] != 0) return 0;
    if(moviliY[mov] < 0) for(int i = 0; i > moviliY[mov]*3; i--) if(mapa[x][y + i] != 0) return 0;
    return 1;
}

void llenadoLinea(vector<vector<int>> &mapa, int x, int y, int mov, int valor){
    if(moviliX[mov] < 0) for(int i = 0; i > moviliX[mov]*3; i--) mapa[x + i][y] = valor;
    if(moviliX[mov] > 0) for(int i = 0; i < moviliX[mov]*3; i++) mapa[x + i][y] = valor;
    if(moviliY[mov] < 0) for(int i = 0; i > moviliY[mov]*3; i--) mapa[x][y + i] = valor;
    if(moviliY[mov] > 0) for(int i = 0; i < moviliY[mov]*3; i++) mapa[x][y + i] = valor;
}

int robotCortes(ofstream &file, vector<vector<int>> &mapa, int x, int y, int valor){
    if(valor > 1 && comprueba(mapa, x, y)){
        imprimeTablero(file, mapa);
        file << endl;
        return 0;
    }
    for(int i = 0; i < movs; i++){
        int nx = x + movX[i], ny = y + movY[i];
        if(valida(mapa, nx, ny)){
            for(int j = 0; j < movili; j++){
                int finX = moviliX[j] != 0? (moviliX[j] < 0? nx + moviliX[j]*3 + 1: nx + moviliX[j]*3 - 1): nx;
                int finY = moviliY[j] != 0? (moviliY[j] < 0? ny + moviliY[j]*3 + 1: ny + moviliY[j]*3 - 1): ny;
                if(comprobarLinea(mapa, nx, ny, finX, finY, j)){
                    llenadoLinea(mapa, nx, ny, j, valor);
                    robotCortes(file, mapa, finX, finY, valor + 1);
                    llenadoLinea(mapa, nx, ny, j, 0);
                }
            }
        }
    }
    return 0;
}

int main (void){
    ofstream file("output.txt", ios::out);
    vector<vector<int>> mapa(N, vector<int>(N, 0));
    robotCortes(file, mapa, -1, -1, 1);
    return 0;
}