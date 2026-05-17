# Sistema de Gerenciamento de Banco

Este projeto consiste em um sistema de gerenciamento bancário simulado via linha de comando (CLI), desenvolvido como o Trabalho Prático I da disciplina **BCC 221 - Programação Orientada a Objetos (POO)**. O sistema manipula entidades como Clientes, Gerentes e Transações, aplicando conceitos fundamentais de POO, persistência de dados em arquivos CSV e uso extensivo da biblioteca padrão do C++ (STL).

## 🚀 Recursos e Funcionalidades

O sistema simula as operações do dia a dia de uma agência bancária, divididas em:

### Funcionalidades Principais
* **Cadastro e Vínculos:** Cadastro de clientes e gerentes, permitindo a associação direta entre eles.
* **Contas Bancárias:** Suporte a Conta Corrente e Conta Poupança, com cálculo automático de rendimentos baseado na remuneração do cliente.
* **Operações Financeiras:** Criação de transações de depósito, saque e transferência entre contas, registrando data, horário e os envolvidos.
* **Persistência Automática:** Todos os dados de clientes e gerentes são salvos e carregados de forma automatizada através de arquivos `.csv`.

### 🌟 Funcionalidade Extra (Cartão de Crédito)
Menu administrativo e de autoatendimento integrado para gerenciamento de cartões de crédito:
* Definição e alteração de limite com base na remuneração.
* Realização de transações parceladas.
* Bloqueio e desbloqueio do cartão (por cliente ou gerente).
* Visualização e pagamento de fatura com débito automático no saldo da conta.

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++ (padrão C++17 ou superior recomendado)
* **Biblioteca Padrão (STL):** Uso de containers (`std::vector`, `std::map`), strings (`std::string`), gerenciamento de fluxos de arquivos (`std::fstream`) e manipulação de entrada/saída.
* **Paradigma:** Programação Orientada a Objetos (Herança, Polimorfismo, Encapsulamento e Associação).

---

<!-- ## 📂 Estrutura do Projeto

O código está organizado de forma modular, separando as especificações (`.h`) das implementações (`.cpp`): -->

<!-- ```text
├── src/
│   ├── Pessoa.h / Pessoa.cpp               # Classe base (Herança)
│   ├── Cliente.h / Cliente.cpp             # Classe derivada de Pessoa
│   ├── Gerente.h / Gerente.cpp             # Classe derivada de Pessoa
│   ├── Transacao.h / Transacao.cpp         # Registro de movimentações
│   ├── BancoController.h / BancoController.cpp # Lógica de controle e persistência
│   └── main.cpp                            # Ponto de entrada e Menu CLI
├── data/
│   ├── clientes.csv                        # Base de dados dos clientes
│   └── gerentes.csv                        # Base de dados dos gerentes
├── Makefile                                # Automação do build (opcional)
└── README.md                               # Este arquivo -->