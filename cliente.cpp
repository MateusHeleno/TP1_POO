#include "cliente.hpp"
#include "transacao.hpp"
#include "auxiliares.hpp"
#include "pessoa.hpp"
#include "credito.hpp"
#include <iostream>
#include <string>
#include <vector>

Cliente::Cliente(string n, string t, string l, string s, double rem, string tipo, double taxa, double sal, bool temCartao) : Pessoa(n, t, l, s),
                                                                                                             remuneracao(rem),
                                                                                                             taxaDeRendimento(taxa),
                                                                                                             saldo(sal),
                                                                                                             tipoDeConta(tipo),
                                                                                                             temCartao(temCartao)
{
    if(temCartao == true){
        cartao.criar(remuneracao);
    }
}

void Cliente::exibirDados()
{
    Pessoa::exibirDados(); // adiciona a implementacao da classe mae

    // adiciona os dados especificos
    cout << "Remuneração: R$ " << remuneracao << endl;
    cout << "Tipo de Conta: " << tipoDeConta << endl;
    cout << "Saldo Atual: R$ " << saldo << endl;

    string tipoLower = toLowerString(tipoDeConta);

    // se for poupanca mostra a taxa
    if (tipoLower == "poupança")
        cout << "Valor do rendimento mensal: " << taxaDeRendimento << endl;

    cout << "Total de transações realizadas: " << transacoes.size() << endl;
    for (auto &t : transacoes)
        t->exibirTransacao();
}

string Cliente::getTipoDeConta()
{
    return tipoDeConta;
}

void Cliente::setTipoDeConta(string tipo)
{
    tipoDeConta = tipo;
    if (toLowerString(tipoDeConta) == "corrente")
        taxaDeRendimento = 0.0;
}

double Cliente::getSaldo()
{
    return saldo;
}

void Cliente::setSaldo(double s)
{
    saldo = s;
}

void Cliente::setTransacao(Transacao *t)
{
    transacoes.push_back(t);
}

vector<Transacao *> Cliente::getExtrato()
{
    return transacoes;
}

double Cliente::getRendimento()
{
    return taxaDeRendimento;
}

double Cliente::getRemuneracao() {
    return remuneracao;
}

void Cliente::setRemuneracao(double novaRemuneracao) {
    if (novaRemuneracao < 0) {
        cout << "Erro: a remuneração não pode ser negativa." << endl;
        return;
    }

    remuneracao = novaRemuneracao;

    if (toLowerString(tipoDeConta) == "poupança") {
        taxaDeRendimento = remuneracao * 0.05;
    }
}

// só possui taxa de rendimento se o tipo da conta for poupança
void Cliente::setRendimento(double r)
{
    string tipoConta = getTipoDeConta();
    if (tipoConta == "poupança")
        taxaDeRendimento = r;
}

// realiza a sobrecarga do operador << para poder salvar os dados no arquivo csv usando {file << cliente} para melhor legibilidade do código
ostream &operator<<(ostream &out, const Cliente &c)
{
    out << c.getNome() << ','
        << c.getTrabalho() << ','
        << c.getLogin() << ','
        << c.getSenha() << ','
        << c.tipoDeConta << ','
        << c.remuneracao << ','
        << c.saldo << ','
        << c.taxaDeRendimento
        << endl;

    return out;
}

Cliente cadastrarCliente() {
    string nome, trabalho, login, senha, tipoDeConta;
    double remuneracao, taxaRendimento, saldo;

    limparBuffer();
    cout << "Nome: ";
    getline(cin, nome);
    cout << "Trabalho: ";
    getline(cin, trabalho);
    cout << "Login: ";
    getline(cin, login);
    cout << "Senha: ";
    getline(cin, senha);

    cout << "Tipo de conta: ";
    cin >> tipoDeConta;
    while (toLowerString(tipoDeConta) != "poupança" && toLowerString(tipoDeConta) != "corrente") {
        cout << "Tipos disponíveis: Poupança ou Corrente" << endl;
        cout << "Tipo de Conta: ";
        cin >> tipoDeConta;
    }

    cout << "Remuneração: ";
    cin >> remuneracao;

    taxaRendimento = 0.0;
    if (toLowerString(tipoDeConta) == "poupança") {
        taxaRendimento = remuneracao * 0.05;
        cout << "Valor do Rendimento: " << taxaRendimento << endl;
    }

    cout << "Saldo: ";
    cin >> saldo;
    cout << endl;

    return Cliente(nome, trabalho, login, senha, remuneracao, tipoDeConta, taxaRendimento, saldo, false);
}

void listarCliente(vector <Cliente>& clientes) {
    limparBuffer();
    cout << "=== LISTA DE CLIENTES CADASTRADOS ===" << endl;
    if (clientes.empty())
        cout << "Nenhum cliente cadastrado no sistema." << endl;

    else {
        for (Cliente &c : clientes) {
            c.exibirDados();
            cout << "-----------------------------------" << endl;
        }
    }
}


void mostrarDadosCliente(vector<Cliente> &clientes) {
    string nome;
    limparBuffer();
    cout << "Insira o nome do cliente: ";
    getline(cin, nome);

    Cliente *cliente = buscaPessoa(clientes, nome);
    if (cliente == nullptr)
        return;

    cliente->exibirDados();
}

//Cartão de crédito -------------------------------------

void Cliente::criarCartao() {
    if (temCartao) {
        cout << "Este cliente já possui cartão de crédito." << endl;
        return;
    }

    cartao.criar(remuneracao);
    temCartao = true;

    cout << "Cartão criado com sucesso!" << endl;
}

bool Cliente::possuiCartao() const {
    return temCartao;
}

CartaoCredito& Cliente::getCartao() {
    return cartao;
}