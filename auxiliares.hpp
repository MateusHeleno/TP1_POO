#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <string>
#include <fstream>
#include <vector>

#include "pessoa.hpp"
#include "cliente.hpp"
#include "gerente.hpp"
#include "transacao.hpp"

int lerValor();
void limparTerminal();
string toLowerString(string s);
Cliente cadastrarCliente();
Gerente cadastrarGerente();
Transacao* criarTransacao(vector<Cliente>& clientes);
bool checkListaCliente(vector<Cliente>& clientes, string nome);

// o template é um tipo genérico que permite a função trabalhar com tipos genéricos, o que permite escrever uma função ao invés de duas ou mais pra tipos diferentes
template<typename T>
void escreverCSV(const string arquivo, vector<T> vec) {
    ofstream file(arquivo);

    file << vec[0].getHeader() << endl;
    for (auto& item: vec)
        file << item;

    file.close();
}

#endif