#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "pessoa.hpp"
#include "cliente.hpp"
#include "gerente.hpp"

using namespace std;

int lerValor(int n) {
    int valor;
    while (true) {
        cout << "- ";
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada inválida, digite um número: " << endl;
        }
        else if (valor >= 1 && valor <= n)
            return valor;
        else
            cout << "Valor inválido! Escolha entre 1 e "<< n << ": "<< endl;
    }
}

void limparTerminal() {
    system("clear");
}

void limparBuffer() {
    cin.ignore(100, '\n');
}

string toLowerString(string s) {
    // usando "auto" o compilador deduz automaticamente o tipo da varíavel e usando & passamos por referência, permitindo modificação no objeto
    for (auto& c: s)
        c = tolower(c);

    return s;
}