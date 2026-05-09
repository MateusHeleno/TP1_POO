#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "pessoa.hpp"
#include "transacao.hpp" // Necessário para o vector de transações
#include <vector>
#include <string>

using namespace std;

class Cliente : public Pessoa {
private:
    double remuneracao;
    double taxaDeRendimento;
    double saldo;
    string tipoDeConta;
    vector<Transacao *> transacoes; // Coleção exigida pelo diagrama eh o extrato

public:
    Cliente(string n, string t, string l, string s, double rem, string tipo, double taxa, double sal);

    void exibirDados() override;

    void setTransacao(Transacao *t);
    vector<Transacao *> getExtrato();

    string getTipoDeConta();
    void setTipoDeConta(string tipo);

    double getSaldo();
    void setSaldo(double s);

    double getRendimento();
    void setRendimento(double r);

    // realiza sobrecarga do operador <<
    friend ostream& operator<<(ostream& os, const Cliente& c);
};

#endif