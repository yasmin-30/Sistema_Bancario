#include <iostream>
#include <string>
#include "Cliente.h"

//construtor padrão para inicializar as strings nome e cpf
Cliente::Cliente() {
    this->nome = "";
    this->cpf = "";
}

//construtor parametrizado para passar os valores de nome e cpf
Cliente::Cliente(std::string nome, std::string cpf) {
    this->nome = nome;
    this->cpf = cpf;
}

//destrutor
Cliente::~Cliente() {

}

//método getter para acessar o nome do cliente
std::string Cliente::getNome() {
    return this->nome;
}

//método getter para acessar o CPF do cliente
std::string Cliente::getCpf() {
    return this->cpf;
}