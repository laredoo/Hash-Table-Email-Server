#ifndef ARVORE_H
#define ARVORE_H

#include "../include/email.h"

class TipoNo
{
    public:
        TipoNo();
        Email msg;
        TipoNo *esq;
        TipoNo *dir;
    friend class ArvoreBinaria;
};

class ArvoreBinaria
{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void Insere(Email item);
        void Caminha(int tipo);
        Email Pesquisa(Email msg);
        void Remove(Email chave);
        void Limpa();
        void InsereRecursivo(TipoNo* &p, Email item);
        void ApagaRecursivo(TipoNo* p);
        Email PesquisaRecursivo(TipoNo *no, Email msg);
        void RemoveRecursivo(TipoNo* &p, Email chave);
        void Antecessor(TipoNo* q, TipoNo* &r);
    TipoNo *raiz;
};

#endif