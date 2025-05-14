#ifndef _CONTABANCARIA_H_
#define _CCONTABANCARIA_H_

#include <string>
#include "Cliente.h"

class ContaBancaria {
    private:
        int numero;
        double saldo;
        Cliente titular;
    public:
        ContaBancaria(int numero, Cliente titular, double saldo = 0);
        ~ContaBancaria();
        int getNumero();
        double getSaldo();
        Cliente getTitular();
        void depositar(double valor);
        bool verificacao_valor(double valor);
        void sacar(double valor);
        void transferir(double valor, ContaBancaria &destino);
        bool pode_transferir;
        void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2);
        void exibirSaldo();
        void exibirInformacoes();

};

#endif