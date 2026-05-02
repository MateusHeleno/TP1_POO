#include <iostream>

using namespace std;

int lerValor() {
    int valor;
    while (true) {
        cout << "- ";
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada inválida, digite um número: " << endl;
        }
        else if (valor >= 1 && valor <= 8)
            return valor;
        else
            cout << "Valor inválido! Escolha entre 1 e 8: " << endl;
    }
}