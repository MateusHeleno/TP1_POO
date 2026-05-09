#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "pessoa.hpp"
#include <vector>
#include <string>

using namespace std;

// Forward declaration para evitar dependência circular
class Cliente;

class Gerente : public Pessoa {
private:
    vector<Cliente *> clientes; // clientes vinculados

public:
    Gerente(string n, string t, string l, string s);

    void exibirDados() override;

    vector<Cliente *> getClientes();
    void setCliente(Cliente *c);

    string getHeader() override {
        return "nome,trabalho";
    }

    friend ostream& operator<<(ostream& out, const Gerente& g);
};

#endif