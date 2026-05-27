#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "pessoa.hpp"
#include "cliente.hpp"
#include "gerente.hpp"

using namespace std;

void limparTerminal()
{
    system("clear");
}

void limparBuffer()
{
    cin.ignore(100, '\n');
}

int lerValor(int n)
{
    int valor;
    while (true)
    {
        cout << "- ";
        cin >> valor;
        if (cin.fail())
        {
            limparTerminal();
            limparBuffer();
            cout << "Entrada inválida, digite um número: " << endl;
        }
        else if (valor >= 1 && valor <= n)
            return valor;
        else
            cout << "Valor inválido! Escolha entre 1 e " << n << ": " << endl;
    }
}


string toLowerString(string s)
{
    // usando "auto" o compilador deduz automaticamente o tipo da varíavel e usando & passamos por referência, permitindo modificação no objeto
    for (auto &c : s)
        c = tolower(c);

    return s;
}

void carregarClientes(vector<Cliente> &clientes)
{
    ifstream file("clientes.csv");

    if (!file.is_open()) // verifica se o arquivo existe
    {
        return;
    }

    string linha;
    getline(file, linha); // descarta o cabecalho

    while (getline(file, linha)) // leitura do arquivo
    {
        stringstream ss(linha);
        string nome, trabalho, login, senha, tipoConta;
        string rem_str, saldo_str, taxa_str;

        // leitura separada por virgula
        getline(ss, nome, ',');
        getline(ss, trabalho, ',');
        getline(ss, login, ',');
        getline(ss, senha, ',');
        getline(ss, tipoConta, ',');
        getline(ss, rem_str, ',');
        getline(ss, saldo_str, ',');
        getline(ss, taxa_str, ',');

        // converte as strings numericas pra double
        double rem = stod(rem_str);
        double saldo = stod(saldo_str);
        double taxa = stod(taxa_str);

        // adiciona no programa
        clientes.push_back(Cliente(nome, trabalho, login, senha, rem, tipoConta, taxa, saldo, false));
    }
    file.close();
}

void carregarGerentes(vector<Gerente> &gerentes)
{
    ifstream file("gerentes.csv");

    if (!file.is_open())
    {
        return;
    }

    string linha;
    getline(file, linha);

    while (getline(file, linha))
    {
        stringstream ss(linha);
        string nome, trabalho, login, senha;

        getline(ss, nome, ',');
        getline(ss, trabalho, ',');
        getline(ss, login, ',');
        getline(ss, senha, ',');

        gerentes.push_back(Gerente(nome, login, senha));
    }
    file.close();
}