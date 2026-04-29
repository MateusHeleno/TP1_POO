#include "pessoa.hpp"
#include <string>
#include <iostream>

void Pessoa::setTrabalho(string t)
{
    trabalho = t;
};

string Pessoa::getTrabalho()
{
    return trabalho;
}

void Pessoa::setSenha(string s)
{
    senha = s;
}

void Pessoa::exibirDados() // ESSA FUNCAO EH VIRTUAL
{
    cout << "Nome: " << nome << endl;
    cout << "Trabalho: " << trabalho << endl;
    cout << "Login: " << login << endl;
}

Pessoa::Pessoa(string n = "NOME", string t = "TRABALHO", string l = "LOGIN", string s = "SENHA") //inicializa com dados vazios se nao receber parametros
{
    nome = n;
    trabalho = t;
    login = l;
    senha = s;
}