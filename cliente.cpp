#include "cliente.hpp"
#include "transacao.hpp"
#include <iostream>
#include <string>
#include <vector>

Cliente::Cliente(string n, string t, string l, string s,
                 double rem, string tipo, double taxa, double sal)
    : Pessoa(n, t, l, s),
      remuneracao(rem),
      tipoDeConta(tipo),
      taxaDeRendimento(taxa),
      saldo(sal)
{
    // a classe foi inicializada acima
}

void Cliente::exibirDados()
{
    Pessoa::exibirDados(); // adiciona a implementacao da classe mae

    // adiciona os dados especificos
    cout << "Remuneração: R$ " << remuneracao << endl;
    cout << "Tipo de Conta: " << tipoDeConta << endl;
    cout << "Saldo Atual: R$ " << saldo << endl;

    // se for poupanca mostra a taxa
    if (tipoDeConta == "poupança" || tipoDeConta == "Poupança")
    {
        cout << "Taxa de Rendimento: " << taxaDeRendimento << "%" << endl;
    }

    cout << "Total de transações realizadas: " << transacoes.size() << endl;
}