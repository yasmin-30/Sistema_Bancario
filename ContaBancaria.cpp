#include <iostream>
#include <string>
#include "Cliente.h"
#include "ContaBancaria.h"

//construtor parametrizado para passar os valores do númeor, titular e saldo
ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo) {
    this->numero = numero;
    this->titular = titular;
    
    //verificação se o valor do saldo é válido
    if(saldo >= 0) {
        this->saldo = saldo;
    }else{
        std::cout << "O valor do saldo é inválido, sua conta será aberta com R$0!" << std::endl;
        this->saldo = 0;
    }
}

//destrutor
ContaBancaria::~ContaBancaria() {

}

//função getter do número
int ContaBancaria::getNumero() {
    return this->numero;
}

//função getter do saldo
double ContaBancaria::getSaldo() {
    return this->saldo;
}

//função getter do titular
Cliente ContaBancaria::getTitular() {
    return this->titular;
}

//depositar
void ContaBancaria::depositar(double valor) {
    if(valor < 0){
        std::cout << "Valor inválido para depósito!" << std::endl;
        return;
    }
    
    this->saldo += valor;
}

//verificação se o valor de saque é válido
bool ContaBancaria::verificacao_valor(double valor){
    if(valor > this->saldo || valor < 0) {
        std::cout << "Saldo insuficiente ou valor inválido para a transferência!\n";
        return false;
    } 
    return true;
}

//sacar
void ContaBancaria::sacar(double valor) {
    //verificar se o valor é válido
    if(verificacao_valor(valor)){
        this->saldo -= valor;
    }
}

//transferir dinheiro para outra conta
void ContaBancaria::transferir(double valor, ContaBancaria &destino) {

    //verificar se o valor é válido
    if(verificacao_valor(valor)){
        sacar(valor);;
        destino.depositar(valor);
        std::cout << "Transferido: R$ " << valor << " da conta " << getNumero() << " para a conta " << destino.getNumero() << std::endl;
    }
}

//transferir dinheiro para outras duas contas
void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {

    //verificar se o valor é válido
    if(verificacao_valor(valor)){
        sacar(valor);
        destino1.depositar(valor/2);
        destino2.depositar(valor/2);
        std::cout << "Transferido: R$ " << valor/2 << " para cada conta (" << destino1.getNumero() << " e " << destino2.getNumero() << ") da conta " << getNumero() << std::endl;
    }
}

//exibir o saldo atual da conta
void ContaBancaria::exibirSaldo() {
    std::cout << "Saldo atual da conta " << getNumero() << ": R$ " << getSaldo() << std::endl;
}

//exibir as informações do titular e da conta
void ContaBancaria::exibirInformacoes() {
    std::cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << std::endl;
    std::cout << "Número da conta: " << getNumero() << ", Saldo: R$ " << getSaldo() << std::endl;
}
