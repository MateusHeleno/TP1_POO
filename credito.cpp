#include "credito.hpp"
#include <iostream>
#include"auxiliares.hpp"

CartaoCredito::CartaoCredito(): 
      limiteTotal(0.0),
      limiteDisponivel(0.0),
      valorFatura(0.0),
      bloqueado(false),
      faturaGerada(false)
{};

void cartaoMain(vector<Cliente>& clientes, vector<Gerente>& gerentes){
    limparTerminal();
    cout << "Digite o que deseja: "<< endl
    << "1. Criar cartão" << endl
    << "2. Bloquear cartão" << endl
    << "3. Alterar limite de crédito" << endl 
    << "4. Pagamento parcelado" << endl
    << "5. Acessar fatura"<< endl
    << "6. Desbloquear cartão" << endl; // aqui dentro ele irá realizar o pagamento ou não
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

        case 4: {

            realizarCompraParcelada(clientes);
            break;
        }
        

        case 5: {

            acessarFatura(clientes);
            break;

        }
        case 6: {

            desbloquearCartao(clientes, gerentes);
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
    faturaGerada = false;
    comprasParceladas.clear();

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

void CartaoCredito::desbloquear() {
    bloqueado = false;
    cout << "Cartão desbloqueado com sucesso!" << endl;
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

void desbloquearCartao(vector<Cliente>& clientes, vector<Gerente>& gerentes) {
    int opcao;

    limparTerminal();
    cout << "Quem está solicitando o desbloqueio?" << endl;
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

        if (!cliente->getCartao().estaBloqueado()) {
            cout << "Este cartão já está desbloqueado." << endl;
            return;
        }

        cliente->getCartao().desbloquear();
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

        if (!cliente->getCartao().estaBloqueado()) {
            cout << "Este cartão já está desbloqueado." << endl;
            return;
        }

        cliente->getCartao().desbloquear();
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

bool CompraParcelada::estaQuitada() const {
    return parcelasPagas >= quantidadeParcelas;
}

int CompraParcelada::getParcelasRestantes() const {
    return quantidadeParcelas - parcelasPagas;
}

string CompraParcelada::getDescricao() const {
    return descricao;
}

double CompraParcelada::getValorTotal() const {
    return valorTotal;
}

int CompraParcelada::getQuantidadeParcelas() const {
    return quantidadeParcelas;
}

double CompraParcelada::getValorParcela() const {
    return valorParcela;
}

int CompraParcelada::getParcelasPagas() const {
    return parcelasPagas;
}

double CartaoCredito::getValorFatura() const {
    return valorFatura;
}

//-----------------------------------------------------------------------------

// pagar fatura ----------------------------------------------------------------

void acessarFatura(vector<Cliente>& clientes) {
    string nomeCliente;

    limparBuffer();
    limparTerminal();

    cout << "===== ACESSAR FATURA =====" << endl;

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

    cout << "===== MENU DA FATURA =====" << endl;
    cout << "1. Ver fatura" << endl;
    cout << "2. Gerar fatura" << endl;
    cout << "3. Pagar fatura" << endl;
    cout << "4. Listar compras parceladas" << endl;

    int opcao = lerValor(4);

    switch (opcao) {
        case 1: {
            cliente->getCartao().exibirFatura();
            break;
        }

        case 2: {
            cliente->getCartao().gerarFatura();
            break;
        }

        case 3: {
            double saldoAtual = cliente->getSaldo();

            if (cliente->getCartao().pagarFatura(saldoAtual)) {
                cliente->setSaldo(saldoAtual);
            }

            break;
        }

        case 4: {
            cliente->getCartao().exibirComprasParceladas();
            break;
        }

        default:
            break;
    }
}

/*
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
*/


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

// Compras parceladas ----------------------------------------------------------

CompraParcelada::CompraParcelada(string descricao, double valorTotal, int quantidadeParcelas)
    : descricao(descricao),
      valorTotal(valorTotal),
      quantidadeParcelas(quantidadeParcelas),
      valorParcela(valorTotal / quantidadeParcelas),
      parcelasPagas(0)
{}



bool CartaoCredito::realizarCompraParcelada(string descricao, double valorTotal, int parcelas) {
    if (bloqueado) {
        cout << "Cartão bloqueado. Compra não autorizada." << endl;
        return false;
    }

    if (valorTotal <= 0) {
        cout << "Valor da compra inválido." << endl;
        return false;
    }

    if (parcelas <= 0) {
        cout << "Quantidade de parcelas inválida." << endl;
        return false;
    }

    if (valorTotal > limiteDisponivel) {
        cout << "Limite insuficiente para essa compra." << endl;
        return false;
    }

    CompraParcelada compra(descricao, valorTotal, parcelas);
    comprasParceladas.push_back(compra);

    limiteDisponivel -= valorTotal;

    cout << "Compra parcelada realizada com sucesso!" << endl;
    cout << "Valor da parcela: R$ " << compra.getValorParcela() << endl;

    return true;
}

void CartaoCredito::gerarFatura() {
    if (faturaGerada) {
        cout << "A fatura já foi gerada e ainda não foi paga." << endl;
        cout << "Valor atual da fatura: R$ " << valorFatura << endl;
        return;
    }

    valorFatura = 0.0;

    for (const CompraParcelada& compra : comprasParceladas) {
        if (!compra.estaQuitada()) {
            valorFatura += compra.getValorParcela();
        }
    }

    if (valorFatura <= 0) {
        cout << "Não há compras parceladas em aberto para gerar fatura." << endl;
        return;
    }

    faturaGerada = true;

    cout << "Fatura gerada com sucesso!" << endl;
    cout << "Valor da fatura: R$ " << valorFatura << endl;
}

void CompraParcelada::pagarUmaParcela() {
    if (!estaQuitada()) {
        parcelasPagas++;
    }
}

bool CartaoCredito::pagarFatura(double& saldoCliente) {
    if (!faturaGerada || valorFatura <= 0) {
        cout << "Não há fatura em aberto." << endl;
        return false;
    }

    if (saldoCliente < valorFatura) {
        cout << "Saldo insuficiente para pagar a fatura." << endl;
        return false;
    }

    saldoCliente -= valorFatura;

    for (CompraParcelada& compra : comprasParceladas) {
        if (!compra.estaQuitada()) {
            compra.pagarUmaParcela();
        }
    }

    limiteDisponivel += valorFatura;

    if (limiteDisponivel > limiteTotal) {
        limiteDisponivel = limiteTotal;
    }

    valorFatura = 0.0;
    faturaGerada = false;

    cout << "Fatura paga com sucesso!" << endl;
    return true;
}

void realizarCompraParcelada(vector<Cliente>& clientes) {
    string nomeCliente;
    string descricao;
    double valorTotal;
    int parcelas;

    limparTerminal();
    limparBuffer();

    cout << "===== REALIZAR COMPRA PARCELADA =====" << endl;

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
        cout << "O cartão deste cliente está bloqueado. Compra não autorizada." << endl;
        return;
    }

    cout << "Descrição da compra: ";
    getline(cin, descricao);

    cout << "Valor total da compra: R$ ";
    cin >> valorTotal;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada inválida para o valor da compra." << endl;
        return;
    }

    cout << "Quantidade de parcelas: ";
    cin >> parcelas;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada inválida para a quantidade de parcelas." << endl;
        return;
    }

    bool compraRealizada = cliente->getCartao().realizarCompraParcelada(
        descricao,
        valorTotal,
        parcelas
    );

    if (compraRealizada) {
        cout << "Compra registrada no cartão do cliente." << endl;
    }
}

void CartaoCredito::exibirComprasParceladas() const {
    cout << "===== COMPRAS PARCELADAS =====" << endl;

    if (comprasParceladas.empty()) {
        cout << "Nenhuma compra parcelada registrada." << endl;
        return;
    }

    for (const CompraParcelada& compra : comprasParceladas) {
        compra.exibirCompra();
        cout << "-----------------------------" << endl;
    }
}

void CompraParcelada::exibirCompra() const {
    cout << "Descrição: " << descricao << endl;
    cout << "Valor total: R$ " << valorTotal << endl;
    cout << "Quantidade de parcelas: " << quantidadeParcelas << endl;
    cout << "Valor da parcela: R$ " << valorParcela << endl;
    cout << "Parcelas pagas: " << parcelasPagas << endl;
    cout << "Parcelas restantes: " << getParcelasRestantes() << endl;

    if (estaQuitada()) {
        cout << "Status: Quitada" << endl;
    }
    else {
        cout << "Status: Em aberto" << endl;
    }
}