#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <iostream>

using namespace std;

class Pessoa{
    private:
        string login;
        string senha;
    public:
        string nome;
        string trabalho;
        void exibirDados();
        string getTrabalho();
        void setTrabalho(string t);
        void setSenha(string s);
        Pessoa(string n,string t, string l,string s);
};

#endif