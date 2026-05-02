#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "pessoa.hpp"
#include "cliente.hpp"
#include "gerente.hpp"
#include "transacao.hpp"
#include "auxiliares.hpp"

using namespace std;

int main() {
    int valor;
    do {
        limparTerminal();

        cout << "====== SISTEMA DE GERENCIAMENTO DE BANCO MASTER ====== " << endl;
        cout << "===== By Vorcaro =====" <<endl;
        cout << "1.Cadastrar Cliente" << endl
        << "2.Cadastrar Gerente" << endl
        << "3.Criar transacao" << endl
        << "4.Exibir extrato de um Cliente" << endl
        << "5.Associar gerente a cliente" << endl
        << "6.Listar clientes" << endl
        << "7.Listar gerentes" << endl
        << "8.Salvar dados e sair" << endl;
        cout << "======================================================" << endl;
        valor = lerValor();

        limparTerminal();
        switch (valor) {
            case 1: {
                Cliente cliente = cadastrarCliente();
                cliente.exibirDados();

                break;
            }
            case 2: {

                break;
            }

            case 3: {
                break;
            }

            case 4: {
                break;
            }

            case 5: {
                break;
            }

            case 6: {
                break;
            }

            case 7: {
                break;
            }

            case 8: {
                break;
            }

            default: {
                break;
            }
        }

        if (valor != 8) {
            cout << endl
                 << "Pressione Enter para voltar ao menu!" << endl;
            cin.ignore(100, '\n');
            cin.get();
        }

    } while (valor != 8);

    return 0;
}