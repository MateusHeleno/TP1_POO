#include "transacao.hpp"
#include "cliente.hpp"
#include "pessoa.hpp"
#include "auxiliares.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <string>

Transacao::Transacao(string t, double v, string d, string h)
    : valor(v),
      tipo(t),
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
        valor = v;
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
        cout << "  Nenhum cliente registrado nesta transação." << endl;
    else
        for (Cliente *cliente : clientesEnvolvidos)
        {
            string nome = cliente->getNome();
            cout << "  - " << nome << endl; // o nome esta protegido na classe pessoa -> usamos getter
        }
}

Transacao *criarTransacao(vector<Cliente> &clientes)
{
    double valor;
    string tipo, data, horario;

    cout << "Tipo da Transação: ";
    cin >> tipo;
    cout << "Valor: ";
    cin >> valor;
    cout << "Data: ";
    cin >> data;
    cout << "Horário: ";
    cin >> horario;

    Transacao t(tipo, valor, data, horario);

    if (toLowerString(tipo) == "transferencia")
    {
        if (!processarTransferencia(t, clientes, valor))
            return nullptr;
    }

    else if (toLowerString(tipo) == "saque")
    {
        if (!processarSaque(t, clientes, valor))
            return nullptr;
    }

    else if (toLowerString(tipo) == "deposito")
    {
        if (!processarDeposito(t, clientes, valor))
            return nullptr;
    }

    else
    {
        cout << "Tipo de transação inválido. Os tipos disponíveis são: Transferência, Saque e Depósito" << endl;
        return nullptr;
    }

    return new Transacao(t);
}

// se o tipo é transferência, precisamos do nome dos clientes que estão envolvidos na transação e verificar se eles estão no vetor de clientes
bool processarTransferencia(Transacao &t, vector<Cliente> &clientes, double valor)
{
    string pessoa1, pessoa2;

    limparBuffer();
    cout << "Cliente 1 (Pagador): ";
    getline(cin, pessoa1);
    cout << "Cliente 2 (Destinatário): ";
    getline(cin, pessoa2);

    Cliente *c1 = buscaCliente(clientes, pessoa1);
    Cliente *c2 = buscaCliente(clientes, pessoa2);
    if (c1 == nullptr || c2 == nullptr)
        return false;

    if (!verificaSaldo(*c1, valor))
        return false;

    // c1->setTransacao(&t);
    // c2->setTransacao(&t);
    c1->setSaldo(c1->getSaldo() - valor);
    c2->setSaldo(c2->getSaldo() + valor);

    t.setClientes(c1);
    t.setClientes(c2);
    return true;
}

bool processarSaque(Transacao &t, vector<Cliente> &clientes, double valor)
{
    string pessoa;
    limparBuffer();
    cout << "Nome do dono da conta: ";
    getline(cin, pessoa);

    Cliente *c = buscaCliente(clientes, pessoa);
    if (c == nullptr)
        return false;

    if (!verificaSaldo(*c, valor))
        return false;

    // c->setTransacao(&t);
    c->setSaldo(c->getSaldo() - valor);
    t.setClientes(c);

    return true;
}

bool processarDeposito(Transacao &t, vector<Cliente> &clientes, double valor)
{
    string pessoa;
    limparBuffer();
    cout << "Nome do dono da conta: ";
    getline(cin, pessoa);

    Cliente *c = buscaCliente(clientes, pessoa);
    if (c == nullptr)
        return false;

    // c->setTransacao(&t);
    c->setSaldo(c->getSaldo() + valor);
    t.setClientes(c);

    return true;
}

bool verificaSaldo(Cliente &c, double valor)
{
    if (c.getSaldo() - valor < 0)
    {
        cout << "Você não tem saldo suficiente para essa operação." << endl;
        return false;
    }
    return true;
}