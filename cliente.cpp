#include "cliente.hpp"
#include "transacao.hpp"
#include "auxiliares.hpp"
#include "pessoa.hpp"

#include <iostream>
#include <string>
#include <vector>

Cliente::Cliente(string n, string t, string l, string s, double rem, string tipo, double taxa, double sal):
    Pessoa(n, t, l, s),
    remuneracao(rem),
    tipoDeConta(tipo),
    taxaDeRendimento(taxa),
    saldo(sal)
{}

void Cliente::exibirDados() {
    Pessoa::exibirDados(); // adiciona a implementacao da classe mae

    // adiciona os dados especificos
    cout << "Remuneração: R$ " << remuneracao << endl;
    cout << "Tipo de Conta: " << tipoDeConta << endl;
    cout << "Saldo Atual: R$ " << saldo << endl;

    string tipoLower = toLowerString(tipoDeConta);

    // se for poupanca mostra a taxa
    if (tipoLower == "poupança")
        cout << "Taxa de Rendimento: " << taxaDeRendimento << "%" << endl;

    cout << "Total de transações realizadas: " << transacoes.size() << endl;
    for (auto &t: transacoes)
        t->exibirTransacao();
}

string Cliente::getTipoDeConta() {
    return tipoDeConta;
}

void Cliente::setTipoDeConta(string tipo) {
    tipoDeConta = tipo;
    if (toLowerString(tipoDeConta) == "corrente")
        taxaDeRendimento = 0.0;
}

double Cliente::getSaldo() {
    return saldo;
}

void Cliente::setSaldo(double s) {
    saldo = s;
}

void Cliente::setTransacao(Transacao *t) {
    transacoes.push_back(t);
}

vector<Transacao *> Cliente::getExtrato() {
    return transacoes;
}

double Cliente::getRendimento() {
    return taxaDeRendimento;
}

// só possui taxa de rendimento se o tipo da conta for poupança
void Cliente::setRendimento(double r) {
    string tipoConta = getTipoDeConta();
    if (tipoConta == "poupança")
        taxaDeRendimento = r;
}

// realiza a sobrecarga do operador << para poder salvar os dados no arquivo csv usando {file << cliente} para melhor legibilidade do código
ostream& operator<<(ostream& out, const Cliente& c) {
    out << c.getNome() << ','
    << c.getTrabalho() << ','
    << c.getLogin() << ','
    << c.getSenha() << ','
    << c.tipoDeConta << ','
    << c.remuneracao << ','
    << c.saldo << ','
    << c.taxaDeRendimento
    << endl;

    return out;
}

Cliente cadastrarCliente() {
    string nome, trabalho, login, senha, tipoDeConta;
    double remuneracao, taxaRendimento, saldo;

    cout << "Nome: "; cin >> nome;
    cout << "Trabalho: "; cin >> trabalho;
    cout << "Login: "; cin >> login;
    cout << "Senha: "; cin >> senha;

    cout << "Tipo de conta: "; cin >> tipoDeConta;
    while (toLowerString(tipoDeConta) != "poupança" && toLowerString(tipoDeConta) != "corrente") {
        cout << "Tipos disponíveis: Poupança ou Corrente" << endl;
        cout << "Tipo de Conta: "; cin >> tipoDeConta;
    }

    cout << "Remuneração: "; cin >> remuneracao;

    taxaRendimento = 0.0;
    if (toLowerString(tipoDeConta) == "poupança") {
        cout << "Taxa de Rendimento: "; cin >> taxaRendimento;
    }

    cout << "Saldo: "; cin >> saldo;
    cout << endl;

    return Cliente(nome, trabalho, login, senha, remuneracao, tipoDeConta, taxaRendimento, saldo);
}

void mostrarDadosCliente(vector <Cliente>& clientes) {
    string nome;
    limparBuffer();
    cout << "Insira o nome do cliente: "; getline(cin, nome);

    Cliente *cliente = buscaCliente(clientes, nome);
    if (cliente == nullptr)
        return;

    cliente->exibirDados();
}