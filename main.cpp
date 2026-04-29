#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "pessoa.hpp"
#include "cliente.hpp"
#include "gerente.hpp"
#include "transacao.hpp"

using namespace std;

int main()
{

    while (true){
        int valor;
        cout << "====== SISTEMA DE GERENCIAMENTO DE BANCO MASTER ====== " << endl;
        cout<< "===== By Vorcaro =====" <<endl;
        cout << "1.Cadastrar Cliente" << endl 
        << "2.Cadastrar Gerente" << endl 
        << "3.Criar transacao" << endl 
        << "4.Exibir extrato de um Cliente" << 
        endl << "5.Associar gerente a cliente" << 
        endl << "6.Listar clientes" << endl 
        << "7.Listar gerentes" << endl <<
         "8.Salvar dados e sair" << endl;
        cout << "======================================================" << endl;
        cout <<"- ";
        cin >> valor;

        if(valor == 8){
            break;
        }

        system("clear");

    }
    

    

    return 0;
}