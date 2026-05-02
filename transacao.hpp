#ifndef TRANSACAO_HPP
#define TRANSACAO_HPP

#include <string>
#include <vector>

using namespace std;

class Cliente; // tem que avisar que a classe existe pra nao ter que chamar o arquivo aq

class Transacao {
private:
    double valor;
    string tipo;
    string data;
    string horario;
    vector<Cliente *> clientesEnvolvidos; // Coleção de clientes exigida

public:
    // Construtor (opcionalmente você pode passar os clientes envolvidos já aqui,
    // mas deixei o básico de acordo com os atributos simples)
    Transacao(string t, double v, string d, string h);

    // Métodos Getters e Setters de acordo com o UML
    string getTipo();

    double getValor();
    void setValor(double v);

    string getData();
    void setData(string d);

    string getHorario();
    void setHorario(string h);

    vector<Cliente *> getClientes();
    void setClientes(Cliente *c);

    // Método para exibir as informações da transação
    void exibirTransacao();
};

#endif