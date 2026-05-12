#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "pessoa.hpp"
#include "cliente.hpp"
#include "gerente.hpp"

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

Gerente cadastrarGerente() {
    string nome, trabalho, login, senha;

    cout << "Nome: "; cin >> nome;
    cout << "Trabalho: "; cin >> trabalho;
    cout << "Login: "; cin >> login;
    cout << "Senha: "; cin >> senha;

    return Gerente(nome, trabalho, login, senha);
}

bool checkListaCliente(vector<Cliente>& clientes, string nome) {
    bool existe = false;
    for (auto& cliente: clientes)
        if (cliente.getNome() == nome) {
            existe = true;
            return existe;
        }

    return existe;
}

Transacao* criarTransacao(vector<Cliente>& clientes) {
    double valor;
    string tipo, data, horario;

    cout << "Tipo da Transação: "; cin >> tipo;
    cout << "Valor: "; cin >> valor;
    cout << "Data: "; cin >> data;
    cout << "Horário: "; cin >> horario;

    Transacao t(tipo, valor, data, horario);
    // se o tipo é transferência, precisamos do nome dos clientes que estão envolvidos na transação e verificar se eles estão no vetor de clientes
    if (toLowerString(tipo) == "transferencia") {
        string pessoa1, pessoa2;
        cout << "Cliente 1: "; getline(cin, pessoa1); // usa o getline para pegar nomes que possuem espaço
        cout << "Cliente 2: "; getline(cin, pessoa2);

        bool checkP1 = checkListaCliente(clientes, pessoa1);
        bool checkP2 = checkListaCliente(clientes, pessoa2);
        if (!checkP1 || !checkP2) {
            cout << "Algum dos clientes não está na lista de clientes" << endl;
            return nullptr;
        }
    }

    return new Transacao(t);
}
