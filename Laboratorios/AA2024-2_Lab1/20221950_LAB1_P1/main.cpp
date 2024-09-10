
// Casco_Once

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void imprimirNoAptos(vector<int> peso, vector<int> almacen, int cantidad, int &noAdmitidos, int &quedaActual){
    cout << setw(4) << ' ' << "No admitidos: ";
    for(int j = 0, t = 0; j < cantidad; t++, j++){
        if(almacen[t] != j){
            noAdmitidos++;
            cout << "P" << j + 1 << ' ';
            quedaActual += peso[j];
            if(almacen[t] > j) t--;
        }
    }
    cout << endl;
}

void porcentaje(vector<int> peso, vector<int> almacen, int cantidad, int &quedaActual){
    int noAdmitidos = 0;
    imprimirNoAptos(peso, almacen, cantidad, noAdmitidos, quedaActual);
    cout << setprecision(2) << fixed;
    cout << setw(4) << ' ' << "Porcentaje: " << ((cantidad - (double)noAdmitidos)/cantidad) * 100 << '%' << endl;
}

void imprimeDatos(int pisoMayor, int pisoMenor, int pisoQMayor, int pisoQMenor){
    cout << endl << "DATOS:" << endl;
    cout << "Piso que mas ocupa: " << pisoMayor+1 << endl;
    cout << "Piso que menos ocupa: " << pisoMenor+1 << endl;
    cout << "Piso que mas sobra: " << pisoQMayor+1 << endl;
    cout << "Piso que menos sobra: " << pisoQMenor+1 << endl;
}

void imprimeTablero(vector<vector<int>> edif, vector<vector<int>> almacen, vector<int> cantidades){
    int pesoActual = 0, pesoMayor = 0, pesoMenor = 51, pisoMayor, pisoMenor; 
    int quedaActual = 0, quedaMayor = 0, quedaMenor = 9999999, pisoQMayor, pisoQMenor;
    for(int i = 0; i < 5; i++){
        pesoActual = 0, quedaActual = 0;
        cout << "Piso " << i+1 << ":" << endl << setw(4) << ' ';
        for(int aux: almacen[i]){
            pesoActual += edif[i][aux];
            cout << "P" << aux+1 << ' ';
        }
        cout << endl;
        if(pesoActual > pesoMayor) pesoMayor = pesoActual, pisoMayor = i;
        if(pesoActual < pesoMenor) pesoMenor = pesoActual, pisoMenor = i;
        porcentaje(edif[i], almacen[i], cantidades[i], quedaActual);
        if(quedaActual > quedaMayor) quedaMayor = quedaActual, pisoQMayor = i;
        if(quedaActual < quedaMenor) quedaMenor = quedaActual, pisoQMenor = i;
    }
    imprimeDatos(pisoMayor, pisoMenor, pisoQMayor, pisoQMenor);
}

int lavanderia(vector<int> kilosRopa, int pos, int N, int pesoLab, vector<int> &optima, vector<int> actual, int &pesoOptimo){
    if(pesoLab < 0) return 0;
    if(pos >= N){
        int canOptima = optima.size(), canActual = actual.size();
        if(canOptima < canActual || (canOptima == canActual && pesoLab > pesoOptimo)){
            pesoOptimo = pesoLab;
            optima = actual;
        }
        return 0;
    }
    actual.push_back(pos);
    lavanderia(kilosRopa, pos + 1, N, pesoLab - kilosRopa[pos], optima, actual, pesoOptimo);
    actual.pop_back();
    return lavanderia(kilosRopa, pos + 1, N, pesoLab, optima, actual, pesoOptimo);
}

int main(void) {
    vector<int> cantidades = {6, 7, 4, 5, 2}, costo = {5, 6, 8, 5, 9};
    vector<vector<int>> solucionOptima(5), solucionActual(5), edif = {
        {14, 11 ,10 ,19 ,14 ,11, 0},
        {20 ,11 ,11 ,10 ,15 ,17 ,8},
        {15 ,16 ,15 ,16, 0, 0, 0},
        {11 ,4 ,19 ,12 ,10, 0, 0},
        {18, 12, 0, 0, 0, 0, 0}
    };
    for(int i = 0, peso = 50; i < 5; i++) lavanderia(edif[i], 0, cantidades[i], 50, solucionOptima[i], solucionActual[i], peso);
    imprimeTablero(edif, solucionOptima, cantidades);
    return 0;
}

