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

int main()
{
    int valor;
    vector<Cliente> clientes;
    clientes.reserve(100);
    vector<Gerente> gerentes;
    vector<Transacao> transacoes;

    do
    {
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
        switch (valor)
        {
        // Cadastrar cliente
        case 1:
        {
            Cliente novoCliente = cadastrarCliente();
            novoCliente.exibirDados();
            clientes.push_back(novoCliente);

            break;
        }
        // Cadastrar gerente
        case 2:
        {
            Gerente novoGerente = cadastrarGerente();
            novoGerente.exibirDados();
            gerentes.push_back(novoGerente);

            break;
        }
        // Criar transação
        case 3:
        {
            Transacao *t = criarTransacao(clientes);
            if (t != nullptr)
            {
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
        case 4:
        {
            mostrarDadosCliente(clientes);

            break;
        }

        case 5:
        {
            string nomeG, nomeC;
            limparBuffer();
            cout << "Nome do Gerente: ";
            getline(cin, nomeG);
            cout << "Nome do Cliente: ";
            getline(cin, nomeC);

            // Busca o gerente no vetor
            Gerente *gEncontrado = nullptr;
            for (Gerente &g : gerentes) // procura o gerente pelo nome
            {
                if (g.getNome() == nomeG)
                {
                    gEncontrado = &g; // Pega o endereço de memória do gerente no vetor
                    break;
                }
            }
            // Busca o cliente usando a sua função auxiliar já pronta
            Cliente *cEncontrado = buscaCliente(clientes, nomeC);

            if (gEncontrado == nullptr) // se nao encontrar o gerente
            {
                cout << "Gerente '" << nomeG << "' não encontrado no sistema." << endl;
            }
            else if (cEncontrado != nullptr) // se encontrar o cliente
            {
                gEncontrado->setCliente(cEncontrado); // adiciona o cliente ao gerente
                cout << "Cliente '" << nomeC << "' associado com sucesso ao Gerente '" << nomeG << "'!" << endl;
            }
            break;
        }
        case 6:
        {
            limparBuffer();
            cout << "=== LISTA DE CLIENTES CADASTRADOS ===" << endl;
            if (clientes.empty()) // verifica se o vetor esta vazio
            {
                cout << "Nenhum cliente cadastrado no sistema." << endl;
            }
            else
            {
                for (Cliente &c : clientes) // percorre todo o vetor e imprime clientes
                {
                    c.exibirDados();
                    cout << "-----------------------------------" << endl;
                }
            }
            break;
        }

        case 7:
        {
            limparBuffer();
            cout << "=== LISTA DE GERENTES CADASTRADOS ===" << endl;
            if (gerentes.empty())
            {
                cout << "Nenhum gerente cadastrado no sistema." << endl;
            }
            else
            {
                for (Gerente &g : gerentes)
                {
                    g.exibirDados();
                    cout << "-----------------------------------" << endl;
                }
            }
            break;
        }

        case 8:
        {
            cout << "Salvando registros nos arquivos. Por favor aguarde!" << endl;
            escreverCSV("clientes.csv", clientes);
            escreverCSV("gerentes.csv", gerentes);

            break;
        }

        default:
        {
            break;
        }
        }

        if (valor != 8)
        {
            cout << endl
                 << "Pressione Enter para voltar ao menu!" << endl;
            limparBuffer();
        }
    } while (valor != 8);

    return 0;
}
