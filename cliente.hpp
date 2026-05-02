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
    // Construtor: deve passar os parâmetros básicos para a classe Pessoa
    Cliente(string n, string t, string l, string s, double rem, string tipo, double taxa, double sal);

    // Sobrescrita do método exibirDados
    void exibirDados() override;

    // Métodos específicos do Cliente (Getters e Setters)
    void setTransacao(Transacao *t);
    vector<Transacao *> getExtrato();

    string getTipoDeConta();
    void setTipoDeConta(string tipo);

    double getSaldo();
    void setSaldo(double s);

    double getRendimento();
    void setRendimento(double r);
};

#endif