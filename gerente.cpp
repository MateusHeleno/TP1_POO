#include "gerente.hpp"
#include "cliente.hpp"
#include "auxiliares.hpp"

#include <iostream>
#include <string>
#include <vector>

Gerente::Gerente(string n, string t, string l, string s): Pessoa(n,t,l,s) {}

vector<Cliente*> Gerente::getClientes() {
    return clientes;
}

void Gerente::setCliente(Cliente* c) {
    clientes.push_back(c);
}

void Gerente::exibirDados() {
    Pessoa::exibirDados();

    std::cout << "Quantidade de clientes vinculados: " << clientes.size() << endl;
    std::cout << "Clientes vinculados: " << endl;
    for (const auto& cliente: clientes) {
        cliente->exibirDados();
    }
}

ostream& operator<<(ostream& out, const Gerente& g) {
    out << g.nome << ','
    << g.trabalho << ','
    << g.getLogin() << ','
    << g.getSenha() << ','
    << endl;

    return out;
}

Gerente cadastrarGerente() {
    string nome, trabalho, login, senha;

    cout << "Nome: "; cin >> nome;
    cout << "Trabalho: "; cin >> trabalho;
    cout << "Login: "; cin >> login;
    cout << "Senha: "; cin >> senha;

    return Gerente(nome, trabalho, login, senha);
}

void vincularCliente(vector <Cliente>& clientes, vector <Gerente>& gerentes) {
    string nomeG, nomeC;
    limparBuffer();
    cout << "Nome do Gerente: ";
    getline(cin, nomeG);
    cout << "Nome do Cliente: ";
    getline(cin, nomeC);

    Gerente *gEncontrado = buscaPessoa(gerentes, nomeG);
    Cliente *cEncontrado = buscaPessoa(clientes, nomeC);
    if (gEncontrado == nullptr || cEncontrado == nullptr)
        return;

    gEncontrado->setCliente(cEncontrado); // adiciona o cliente ao gerente
    cout << "Cliente '" << nomeC << "' associado com sucesso ao Gerente '" << nomeG << "'!" << endl;
}

void listarGerentes(vector <Gerente>& gerentes) {
    limparBuffer();
    cout << "=== LISTA DE GERENTES CADASTRADOS ===" << endl;
    if (gerentes.empty())
        cout << "Nenhum gerente cadastrado no sistema." << endl;

    else {
        for (Gerente &g : gerentes) {
            g.exibirDados();
            cout << "-----------------------------------" << endl;
        }
    }
}