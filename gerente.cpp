#include "gerente.hpp"
#include "cliente.hpp"
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
