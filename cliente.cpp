#include "cliente.hpp"
#include "transacao.hpp"
#include "auxiliares.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

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