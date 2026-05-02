#include "pessoa.hpp"
#include <string>
#include <iostream>

Pessoa::Pessoa(string n, string t, string l, string s) :
    nome(n),
    trabalho(t),
    login(l),
    senha(s)
{}

void Pessoa::setTrabalho(string t) {
    this->trabalho = t;
}

string Pessoa::getSenha() {
    return senha;
}

string Pessoa::getLogin() {
    return login;
}

string Pessoa::getTrabalho() {
    return trabalho;
}

string Pessoa::getNome() {
    return nome;
}

void Pessoa::setSenha(string s) {
    this->senha = s;
}

void Pessoa::setNome(string n) {
    this->nome = n;
}

void Pessoa::exibirDados() { // ESSA FUNCAO EH VIRTUAL
    cout << "Nome: " << nome << endl;
    cout << "Trabalho: " << trabalho << endl;
    cout << "Login: " << login << endl;
}