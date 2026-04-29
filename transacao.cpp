#include "transacao.hpp"
#include "cliente.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <string>

Transacao::Transacao(string t, double v, string d, string h)
    : tipo(t),
      valor(v),
      data(d),
      horario(h)

{
    // a classe foi inicializada acima
}

string Transacao::getTipo()
{

    return tipo;
}

double Transacao::getValor()
{

    return valor;
}

void Transacao::setValor(double v)
{

    if (v >= 0.001)
    {
        valor = v;
    }
    else
        cout << "Erro: Valor invalido";
}

string Transacao::getData()
{

    return data;
}

void Transacao::setData(string d)
{

    data = d;
}

string Transacao::getHorario()
{

    return horario;
}

void Transacao::setHorario(string h)
{

    horario = h;
}

void Transacao::setClientes(Cliente *c)
{
    clientesEnvolvidos.push_back(c);
}

vector<Cliente *> Transacao::getClientes()
{
    return clientesEnvolvidos; // ja eh a colecao de clientes envolvidos completa
}

void Transacao::exibirTransacao()
{
    cout << "Tipo: " << tipo << endl
         << "Valor: R$ " << valor << endl
         << "Data: " << data << endl
         << "Horario: " << horario << endl;

    cout << "Clientes Envolvidos:" << endl; // impressao dos clientes

    if (clientesEnvolvidos.empty()) // verifica se a lista esta vazia
    {
        cout << "  Nenhum cliente registrado nesta transação." << endl;
    }
    else
    {
        for (Cliente *cliente : clientesEnvolvidos)
        {
            cout << "  - " << cliente->nome << endl; // o nome esta publico na classe pessoa
        }
    }
}