#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <iostream>

using namespace std;

class Pessoa
{
private:
    string login;
    string senha;

public:
    string nome;
    string trabalho;

    virtual void exibirDados();
    string getTrabalho();
    void setTrabalho(string t);
    void setSenha(string s);
    string getSenha();
    string getLogin();

    Pessoa(string n = "NOME", string t = "TRABALHO", string l = "LOGIN", string s = "SENHA");
    virtual ~Pessoa() = default; // destrutor de classe virtual
};

#endif