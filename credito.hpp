#ifndef CREDITO_HPP
#define CREDITO_HPP
#include "cliente.hpp"
#include "gerente.hpp"

class CartaoCredito {
private:
    double limiteTotal;
    double limiteDisponivel;
    double valorFatura;
    bool bloqueado;

public:
    CartaoCredito();

    //getters
    double getLimiteTotal() const;
    double getLimiteDisponivel() const;
    double getValorFatura() const;
    bool estaBloqueado() const;


    void criar(double remuneracao);
    void alterarLimite(double novoLimite);
    void bloquear();
    void desbloquear();

    bool realizarCompra(double valor);
    bool realizarCompraParcelada(double valorTotal, int parcelas);
    bool pagarFatura(double& saldoCliente);
    void exibirFatura() const;
};

void cartaoMain(vector<Cliente>& clientes, vector<Gerente>& gerentes);
void criarCartaoParaCliente(vector<Cliente>& clientes, vector<Gerente>& gerentes);
bool clienteVinculadoAoGerente(Gerente& gerente, Cliente* cliente);
void bloquearCartao(vector<Cliente>& clientes, vector<Gerente>& gerentes);
void alterarLimite(double novoLimite);

double getLimiteTotal();
double getLimiteDisponivel();
void alterarLimiteCartao(vector<Cliente>& clientes, vector<Gerente>& gerentes);

#endif