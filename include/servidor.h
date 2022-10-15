#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "../include/arvore_binaria.h"
#include "../include/email.h"

class Hash_LE
{
    public:
        Hash_LE(int M);
        int hashId(Email msg, int M);
        Email Pesquisa(Email mensagem, int M);
        void Insere(Email item, int M);
        void Remove(Email chave, int M);
        ArvoreBinaria *Arvore;
};

#endif