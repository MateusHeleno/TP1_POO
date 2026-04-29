#include "transacao.hpp"
#include "cliente.hpp"
#include <iostream>
#include <string>
#include <vector>
#include<string>

Transacao::Transacao(string t, double v, string d, string h)
    : tipo(t),
    valor(v),
    data(d),
    horario(h)
     
{
    // a classe foi inicializada acima
}

string Transacao::getTipo(){

    return tipo;

}

double Transacao::getValor(){

    return valor;

}

void Transacao::setValor(double v){

    if(v >= 0.001){
        valor = v;

    }

}

string Transacao::getData(){

    return data;

}

void Transacao::setData(string d){

    data = d;

}

string Transacao::getHorario(){

    return horario;

}

void Transacao::setHorario(string h){

    horario = h;

}

