#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "pessoa.hpp"
#include <vector>
#include <string>

using namespace std;

// Forward declaration para evitar dependência circular
class Cliente;

class Gerente : public Pessoa
{
private:
    vector<Cliente *> clientes; // Coleção de clientes vinculados

public:
    // Construtor
    Gerente(string n, string t, string l, string s);

    // Sobrescrita do método exibirDados
    void exibirDados() override;

    // Métodos específicos do Gerente
    vector<Cliente *> getClientes();
    void setCliente(Cliente *c);
};

#endif