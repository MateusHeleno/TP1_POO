#include "credito.hpp"
#include <iostream>
#include"auxiliares.hpp"


void cartaoMain(vector<Cliente>& clientes, vector<Gerente>& gerentes){
    limparTerminal();
    cout << "Digite o que deseja: "<< endl
    << "1. Criar cartão" << endl
    << "2. Bloquear cartão" << endl
    << "3. Alterar limite de crédito" << endl 
    << "4. Pagamento parcelado"
    << "5. Acessar fatura"<< endl; // aqui dentro ele irá realizar o pagamento ou não
    int valor = lerValor(5);
    switch (valor){

        case 1: {

            criarCartaoParaCliente(clientes, gerentes);
            break;

        }

        case 2: {

            bloquearCartao(clientes, gerentes);
            break;

        }

        case 3: {


            alterarLimiteCartao(clientes, gerentes);
            break;

        }

        

        case 5: {

            acessarFatura(clientes);
            break;

        }

        default:
            break;
    
    
    }

}

//Parte de criar cartão ---------------------------------------

void criarCartaoParaCliente(vector<Cliente>& clientes, vector<Gerente>& gerentes) {
    string nomeGerente, nomeCliente;

    limparBuffer();
    limparTerminal();

    cout << "Nome do gerente: ";
    getline(cin, nomeGerente);

    Gerente* gerente = buscaPessoa(gerentes, nomeGerente);
    if (gerente == nullptr)
        return;

    cout << "Nome do cliente: ";
    getline(cin, nomeCliente);

    Cliente* cliente = buscaPessoa(clientes, nomeCliente);
    if (cliente == nullptr)
        return;

    if (!clienteVinculadoAoGerente(*gerente, cliente)) {
        cout << "Este cliente não está vinculado a esse gerente." << endl;
        return;
    }

    cliente->criarCartao();
}

bool clienteVinculadoAoGerente(Gerente& gerente, Cliente* cliente) {
    if (cliente == nullptr) {
        return false;
    }

    vector<Cliente*> clientesDoGerente = gerente.getClientes();

    for (Cliente* c : clientesDoGerente) {
        if (c == cliente) {
            return true;
        }
    }

    return false;
}



void CartaoCredito::criar(double remuneracao){

    limiteTotal = remuneracao * 2;
    limiteDisponivel = limiteTotal;
    valorFatura = 0.0;
    bloqueado = false;

}

//----------------------------------------


// Bloquear cartão ------------------------------


void CartaoCredito::bloquear() {
    bloqueado = true;
    cout << "Cartão bloqueado com sucesso!" << endl;
}

bool CartaoCredito::estaBloqueado() const {
    return bloqueado;
}

void bloquearCartao(vector<Cliente>& clientes, vector<Gerente>& gerentes) {
    int opcao;

    limparTerminal();
    cout << "Quem está solicitando o bloqueio?" << endl;
    cout << "1. Cliente" << endl;
    cout << "2. Gerente" << endl;

    opcao = lerValor(2);

    if (opcao == 1) {
        string nomeCliente;

        limparBuffer();
        cout << "Nome do cliente: ";
        getline(cin, nomeCliente);

        Cliente* cliente = buscaPessoa(clientes, nomeCliente);
        
        if (cliente == nullptr) {
            return;
        }

        if (!cliente->possuiCartao()) {
            cout << "Este cliente ainda não possui cartão de crédito." << endl;
            return;
        }

        if (cliente->getCartao().estaBloqueado()) {
            cout << "Este cartão já está bloqueado." << endl;
            return;
        }

        cliente->getCartao().bloquear();
    }

    else if (opcao == 2) {
        string nomeGerente;
        string nomeCliente;

        limparBuffer();

        cout << "Nome do gerente: ";
        getline(cin, nomeGerente);

        Gerente* gerente = buscaPessoa(gerentes, nomeGerente);

        if (gerente == nullptr) {
            return;
        }

        cout << "Nome do cliente: ";
        getline(cin, nomeCliente);

        Cliente* cliente = buscaPessoa(clientes, nomeCliente);

        if (cliente == nullptr) {
            return;
        }

        if (!clienteVinculadoAoGerente(*gerente, cliente)) {
            cout << "Este cliente não está vinculado a esse gerente." << endl;
            return;
        }

        if (!cliente->possuiCartao()) {
            cout << "Este cliente ainda não possui cartão de crédito." << endl;
            return;
        }

        if (cliente->getCartao().estaBloqueado()) {
            cout << "Este cartão já está bloqueado." << endl;
            return;
        }

        cliente->getCartao().bloquear();
    }
}

//----------------------------------

//Alterar limite -------------------------------

void CartaoCredito::alterarLimite(double novoLimite) {
    if (novoLimite <= 0) {
        cout << "Erro: o limite deve ser maior que zero." << endl;
        return;
    }

    double valorUtilizado = limiteTotal - limiteDisponivel;

    if (novoLimite < valorUtilizado) {
        cout << "Erro: o novo limite não pode ser menor que o valor já utilizado." << endl;
        cout << "Valor já utilizado: R$ " << valorUtilizado << endl;
        return;
    }

    limiteTotal = novoLimite;
    limiteDisponivel = novoLimite - valorUtilizado;

    cout << "Limite alterado com sucesso!" << endl;
    cout << "Novo limite total: R$ " << limiteTotal << endl;
    cout << "Novo limite disponível: R$ " << limiteDisponivel << endl;
}

void alterarLimiteCartao(vector<Cliente>& clientes, vector<Gerente>& gerentes) {
    string nomeGerente;
    string nomeCliente;
    double novoLimite;

    limparBuffer();
    limparTerminal();

    cout << "Nome do gerente: ";
    getline(cin, nomeGerente);

    Gerente* gerente = buscaPessoa(gerentes, nomeGerente);
    if (gerente == nullptr) {
        return;
    }

    cout << "Nome do cliente: ";
    getline(cin, nomeCliente);

    Cliente* cliente = buscaPessoa(clientes, nomeCliente);
    if (cliente == nullptr) {
        return;
    }

    if (!clienteVinculadoAoGerente(*gerente, cliente)) {
        cout << "Este cliente não está vinculado a esse gerente." << endl;
        return;
    }

    if (!cliente->possuiCartao()) {
        cout << "Este cliente ainda não possui cartão de crédito." << endl;
        return;
    }

    double limiteAtual = cliente->getCartao().getLimiteTotal();
    double limiteDisponivel = cliente->getCartao().getLimiteDisponivel();
    double valorUtilizado = limiteAtual - limiteDisponivel;

    double limiteMaximoPermitido = cliente->getRemuneracao() * 2;

    cout << "Limite atual: R$ " << limiteAtual << endl;
    cout << "Limite disponível: R$ " << limiteDisponivel << endl;
    cout << "Valor já utilizado: R$ " << valorUtilizado << endl;
    cout << "Limite máximo permitido pela remuneração: R$ " << limiteMaximoPermitido << endl;

    cout << "Novo limite: R$ ";
    cin >> novoLimite;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada inválida para limite." << endl;
        return;
    }

    if (novoLimite > limiteMaximoPermitido) {
        cout << "Erro: o novo limite ultrapassa o limite máximo permitido para este cliente." << endl;
        return;
    }

    cliente->getCartao().alterarLimite(novoLimite);
}


//------------------------------------------------------------------------------

//getters ---------------------------------------------------------------------

double CartaoCredito::getLimiteTotal() const {
    return limiteTotal;
}

double CartaoCredito::getLimiteDisponivel() const {
    return limiteDisponivel;
}

//-----------------------------------------------------------------------------

// pagar fatura ----------------------------------------------------------------

void acessarFatura(vector<Cliente>& clientes) {
    string nomeCliente;

    limparBuffer();
    cout << "Nome do cliente: ";
    getline(cin, nomeCliente);

    Cliente* cliente = buscaPessoa(clientes, nomeCliente);

    if (cliente == nullptr) {
        return;
    }

    if (!cliente->possuiCartao()) {
        cout << "Este cliente ainda não possui cartão de crédito." << endl;
        return;
    }

    cout << "1. Ver fatura" << endl;
    cout << "2. Pagar fatura" << endl;

    int opcao = lerValor(2);

    if (opcao == 1) {
        cliente->getCartao().exibirFatura();
    }
    else if (opcao == 2) {
        double saldoAtual = cliente->getSaldo();

        if (cliente->getCartao().pagarFatura(saldoAtual)) {
            cliente->setSaldo(saldoAtual);
        }
    }
}


bool CartaoCredito::pagarFatura(double& saldoCliente) {
    if (valorFatura <= 0) {
        cout << "Não há fatura em aberto." << endl;
        return false;
    }

    if (saldoCliente < valorFatura) {
        cout << "Saldo insuficiente para pagar a fatura." << endl;
        return false;
    }

    saldoCliente -= valorFatura;

    limiteDisponivel += valorFatura;

    if (limiteDisponivel > limiteTotal) {
        limiteDisponivel = limiteTotal;
    }

    valorFatura = 0.0;

    cout << "Fatura paga com sucesso!" << endl;
    return true;
}

void CartaoCredito::exibirFatura() const {
    cout << "===== FATURA DO CARTÃO =====" << endl;
    cout << "Valor da fatura: R$ " << valorFatura << endl;
    cout << "Limite total: R$ " << limiteTotal << endl;
    cout << "Limite disponível: R$ " << limiteDisponivel << endl;

    if (bloqueado)
        cout << "Status: Bloqueado" << endl;
    else
        cout << "Status: Ativo" << endl;
}