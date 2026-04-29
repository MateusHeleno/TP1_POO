#include "gerente.hpp"
#include "cliente.hpp"
#include <iostream>
#include <string>
#include <vector>

Gerente::Gerente(string n, string t, string l, string s): Pessoa(n,t,l,s)
{
 // o vetor de clientes eh iniciado automaticamente
}

vector<Cliente*> Gerente::getClientes()
{
    return clientes;
}

void Gerente::setCliente(Cliente* c)
{
    clientes.push_back(c);
}

void Gerente ::exibirDados()
{
    Pessoa::exibirDados();

    cout << "Quantidade de clientes vinculados: " << clientes.size() << endl;
    // ... loop para listar os nomes dos clientes, se desejar [cite: 92]
}
