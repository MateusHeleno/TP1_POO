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

void carregarClientes(vector<Cliente> &clientes) {
    ifstream file("arquivos/clientes.csv");

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

void carregarGerentes(vector<Gerente> &gerentes) {
    ifstream file("arquivos/gerentes.csv");

    if (!file.is_open())
        return;

    string linha;
    getline(file, linha);

    while (getline(file, linha)) {
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

void escreverTransacoes(const string& arquivo, const vector<Transacao*>& transacoes) {
    if (transacoes.empty())
        return;

    ofstream file(arquivo);
    file << "tipo,valor,data,horario,clientesEnvolvidos\n";

    for (Transacao* t : transacoes)
        file << *t;

    file.close();
}

void carregarTransacoes(const string& arquivo, vector<Transacao*>& transacoes, vector<Cliente>& clientes) {
    ifstream file(arquivo);
    if (!file.is_open())
        return;

    string linha;
    getline(file, linha); // descarta o header

    while (getline(file, linha)) {
        if (linha.empty()) continue;

        stringstream ss(linha);
        string tipo, valorStr, data, horario, nomeCliente;

        getline(ss, tipo,     ',');
        getline(ss, valorStr, ',');
        getline(ss, data,     ',');
        getline(ss, horario,  ',');

        Transacao* t = new Transacao(tipo, stod(valorStr), data, horario);

        while (getline(ss, nomeCliente, ',')) {
            if (nomeCliente.empty()) continue;

            // Busca o cliente pelo nome no vetor
            for (Cliente& c : clientes) {
                if (c.getNome() == nomeCliente) {
                    t->setClientes(&c);
                    c.setTransacao(t);
                    break;
                }
            }
        }

        transacoes.push_back(t);
    }

    file.close();
}