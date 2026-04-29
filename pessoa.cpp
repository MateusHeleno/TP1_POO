#include "pessoa.hpp"
#include <string>
#include <iostream>

void Pessoa::setTrabalho(string t)
{
    trabalho = t;
}

string Pessoa::getSenha()
{
    return senha;
}

string Pessoa::getLogin()
{
    return login;
}

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

Pessoa::Pessoa(string n, string t, string l, string s) //inicializa com dados vazios se nao receber parametros
{
    nome = n;
    trabalho = t;
    login = l;
    senha = s;
}