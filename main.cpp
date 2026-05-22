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
    vector<Cliente> clientes;
    vector<Gerente> gerentes;
    clientes.reserve(100);
    gerentes.reserve(100);
    vector<Transacao> transacoes;

    do {
        limparTerminal();

        cout << "====== SISTEMA DE GERENCIAMENTO DE BANCO MASTER ====== " << endl;
        cout << "===== By Vorcaro =====" << endl;
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
            // Cadastrar cliente
            case 1: {
                Cliente novoCliente = cadastrarCliente();
                novoCliente.exibirDados();
                clientes.push_back(novoCliente);

                break;
            }
            // Cadastrar gerente
            case 2: {
                Gerente novoGerente = cadastrarGerente();
                novoGerente.exibirDados();
                gerentes.push_back(novoGerente);

                break;
            }
            // Criar transação
            case 3:{
                Transacao *t = criarTransacao(clientes);
                if (t != nullptr) {
                    transacoes.push_back(*t);

                    Transacao *tNoVetor = &transacoes.back();
                    for (Cliente *c : t->getClientes())
                        c->setTransacao(tNoVetor);
                    t->exibirTransacao();

                    delete t;
                }

                break;
            }
            // Exibir extrato de um cliente
            case 4: {
                mostrarDadosCliente(clientes);

                break;
            }
            // Associar cliente a gerente
            case 5: {
                vincularCliente(clientes, gerentes);

                break;
            }
            case 6: {
                listarCliente(clientes);

                break;
            }

            case 7: {
                listarGerentes(gerentes);

                break;
            }

            case 8: {
                cout << "Salvando registros nos arquivos. Por favor aguarde!" << endl;
                escreverCSV("clientes.csv", clientes);
                escreverCSV("gerentes.csv", gerentes);

                break;
            }

            default: {
                break;
            }
        }

        if (valor != 8) {
            cout << endl
                 << "Pressione Enter para voltar ao menu!" << endl;
            limparBuffer();
        }
    } while (valor != 8);

    return 0;
}
