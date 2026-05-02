#include <iostream>
#include <string>

#include "cliente.hpp"

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

void limparTerminal() {
    system("clear");
}

string toLowerString(string s) {
    // usando "auto" o compilador deduz automaticamente o tipo da varíavel e usando & passamos por referência, permitindo modificação no objeto
    for (auto& c: s)
        c = tolower(c);

    return s;
}

Cliente cadastrarCliente() {
    string nome, trabalho, login, senha, tipoDeConta;
    double remuneracao, taxaRendimento, saldo;

    cout << "Nome: "; cin >> nome;
    cout << "Trabalho: "; cin >> trabalho;
    cout << "Login: "; cin >> login;
    cout << "Senha: "; cin >> senha;

    cout << "Tipo de conta: "; cin >> tipoDeConta;
    while (toLowerString(tipoDeConta) != "poupança" && toLowerString(tipoDeConta) != "corrente") {
        cout << "Tipos disponíveis: Poupança ou Corrente" << endl;
        cout << "Tipo de Conta: "; cin >> tipoDeConta;
    }

    cout << "Remuneração: "; cin >> remuneracao;

    taxaRendimento = 0.0;
    if (toLowerString(tipoDeConta) == "poupança") {
        cout << "Taxa de Rendimento: "; cin >> taxaRendimento;
    }

    cout << "Saldo: "; cin >> saldo;
    cout << endl;

    return Cliente(nome, trabalho, login, senha, remuneracao, tipoDeConta, taxaRendimento, saldo);
}