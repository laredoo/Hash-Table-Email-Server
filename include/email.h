#ifndef EMAIL_H
#define EMAIL_H
#include <iostream>

using namespace std;

class Email {
    public:
        int idMensagem;
        int idDestinatario;
        int tamanhoMensagem;
        string msg;
        string outNome;
        Email() {
            idMensagem = -1;
            idDestinatario = -1;
            tamanhoMensagem = -1;
            msg = "";
        };
};

#endif