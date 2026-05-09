#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <string>
#include "pessoa.hpp"
#include "cliente.hpp"
#include "gerente.hpp"


int lerValor();
void limparTerminal();
string toLowerString(string s);
Cliente cadastrarCliente();
Gerente cadastrarGerente();

// o template é um tipo genérico que permite a função trabalhar com tipos genéricos, o que permite escrever uma função ao invés de duas ou mais pra tipos diferentes
template<typename T>
void escreverCSV(const string arquivo, vector<T> vector);

#endif