#include "../include/arvore_binaria.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

TipoNo::TipoNo()
{
    esq = NULL;
    dir = NULL;
}

ArvoreBinaria::ArvoreBinaria()
{
   raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
   Limpa();
}

Email ArvoreBinaria::Pesquisa(Email msg) {
    return PesquisaRecursivo(raiz, msg);
}

Email ArvoreBinaria::PesquisaRecursivo(TipoNo *no, Email msg) {
    Email aux;
    if (no == NULL) {
        aux.idMensagem = -1; // Flag para item não presente
        return aux;
    }
    if (msg.idMensagem < no->msg.idMensagem)
        return PesquisaRecursivo(no->esq, msg);
    else if (msg.idMensagem >no->msg.idMensagem)
        return PesquisaRecursivo(no->dir, msg);
    else
        return no->msg;
}

void ArvoreBinaria::Insere(Email msg){
    InsereRecursivo(raiz,msg);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, Email msg){
    if(p==NULL){
        p = new TipoNo();
        p->msg = msg;
    }
    else{
        if(msg.idMensagem < p->msg.idMensagem)
            InsereRecursivo(p->esq, msg);
        else
            InsereRecursivo(p->dir, msg);
    }
}

void ArvoreBinaria::Remove(Email msg) {
    return RemoveRecursivo(raiz, msg);
}

void ArvoreBinaria::RemoveRecursivo(TipoNo* &no, Email msg){
    TipoNo *aux;
    if (no == NULL) {
        cout << "Item nao está presente" << endl;
    }
    if (msg.idMensagem < no->msg.idMensagem)
        return RemoveRecursivo(no->esq, msg);
    else if (msg.idMensagem > no->msg.idMensagem)
        return RemoveRecursivo(no->dir, msg);
    else {
        if (no->dir == NULL) {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if(no->esq == NULL) {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
            Antecessor(no, no->esq);
    }
}

void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo* &r){
    if(r->dir != NULL) {
        Antecessor(q, r->dir);
        return;
    }
    q->msg = r->msg;
    q = r;
    r = r->esq;
    free(q);
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p)
{
   if (p != NULL)
   {
      ApagaRecursivo(p->esq);
      ApagaRecursivo(p->dir);
      delete p;
   }
}

void ArvoreBinaria::Limpa()
{
   ApagaRecursivo(raiz);
   raiz = NULL;
}