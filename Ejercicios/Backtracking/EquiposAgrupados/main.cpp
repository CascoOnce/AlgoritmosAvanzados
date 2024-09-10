
// Casco_Once

#include <iostream>
#include <string>
using namespace std;

int impresion(string s, string im, int pos){
    if(pos == s.length()){
        cout << im << endl;
        return 0;
    }
    im += s[pos];
    if(!impresion(s, im, pos + 1) && pos+1 < s.length()){
        im += " ";
        impresion(s, im, pos + 1);
    }return 0;
}

int main (void){
    string s = "";
    if(impresion("4592", s, 0)) cout << "Termino";
    return 0;
}