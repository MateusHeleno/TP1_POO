#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <iostream>

using namespace std;

class Pessoa {
protected:
    string nome;
    string trabalho;
private:
    string login;
    string senha;
public:
    virtual void exibirDados();
    void setTrabalho(string t);
    void setSenha(string s);
    void setNome(string n);
    string getSenha();
    string getLogin();
    string getTrabalho();
    string getNome();

    Pessoa(string n = "NOME", string t = "TRABALHO", string l = "LOGIN", string s = "SENHA");
    virtual ~Pessoa() = default; // destrutor de classe virtual
};

#endif