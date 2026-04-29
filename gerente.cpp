#include "gerente.hpp"
#include "cliente.hpp"
#include <iostream>
#include <string>
#include <vector>

void Gerente ::exibirDados()
{
    Pessoa::exibirDados();

    cout << "Quantidade de clientes vinculados: " << clientes.size() << endl;
    // ... loop para listar os nomes dos clientes, se desejar [cite: 92]
}

