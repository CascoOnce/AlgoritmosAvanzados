
// Casco_Once

#include <iostream>
#include <vector>
using namespace std;
#define N 9

void imprimeTablero(vector<vector<int>> tablero){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << tablero[i][j] << ' ';
        cout << endl;
    }
}

int valida(vector<vector<int>> sudoku, int fila, int columna, int num){
    for(int i = 0; i < N; i++) if(sudoku[i][columna] == num) return 0;
    for(int i = 0; i < N; i++) if(sudoku[fila][i] == num) return 0;
    int x = fila/3, y = columna/3;
    for(int i = x*3; i < (x+1)*3; i++){
        for(int j = y*3; j < (y+1)*3; j++){
            if(sudoku[i][j] == num) return 0;
        }
    }
    return 1;
}

int resuelve(vector<vector<int>> &sudoku, int valor, int fila){
    if(fila == N) return 1;
    for(int i = 0; i < N; i++){
        if(sudoku[fila][i] == valor){
            i = -1;
            if(valor == 9){
                if(resuelve(sudoku, 1, fila+1)) return 1;
                else return 0;
            }
            valor++;
            continue;
        }
        if(sudoku[fila][i] == 0 && valida(sudoku, fila, i, valor)){
            sudoku[fila][i] = valor;
            int sePuede;
            if(valor == 9) sePuede = resuelve(sudoku, 1, fila+1);
            else sePuede = resuelve(sudoku, valor+1, fila);
            if(sePuede) return 1;
            else sudoku[fila][i] = 0;
        }
    }
    return 0;
}

int main (void){
    vector<vector<int>> sudoku = {
        {0, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    if(resuelve(sudoku, 1, 0)){
        cout << "ENCONTRO: " << endl;
        imprimeTablero(sudoku);
    }else cout << "NO ENCONTRO" << endl;
    return 0;
}