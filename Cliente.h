#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include <string>

class Cliente {
    private:
        std::string nome;
        std::string cpf;
    public:
        Cliente();
        Cliente(std::string nome, std::string cpf);
        ~Cliente();
        std::string getNome();
        std::string getCpf();
};

#endif