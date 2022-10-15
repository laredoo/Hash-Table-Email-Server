#include "../include/servidor.h"
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

Hash_LE::Hash_LE(int M) {
    this->Arvore = new ArvoreBinaria[M];
}

int Hash_LE::hashId(Email msg, int M) {
    return (msg.idDestinatario % M);
}

Email Hash_LE::Pesquisa(Email mensagem, int M){
    ofstream fileOut(mensagem.outNome, std::ios::app);
    int pos;
    Email item;
    pos = hashId(mensagem, M);
    item = Arvore[pos].Pesquisa(mensagem);

    if(item.idMensagem == -1 || item.idDestinatario != mensagem.idDestinatario) 
        fileOut << "CONSULTA " << mensagem.idDestinatario << " " << mensagem.idMensagem << ": MENSAGEM INEXISTENTE" << endl;
    else
        fileOut << "CONSULTA " << item.idDestinatario << " " << item.idMensagem << ": " << item.msg << endl;

    return mensagem;
}

void Hash_LE::Insere(Email item, int M){
    ofstream fileOut(item.outNome, std::ios::app);
    int pos;
    pos = hashId(item, M);
    Arvore[pos].Insere(item);
    fileOut << "OK: MENSAGEM " << item.idMensagem << " PARA " << item.idDestinatario << " ARMAZENADA EM " << pos << endl;
    fileOut.close();
}

void Hash_LE::Remove(Email chave, int M){
    ofstream fileOut(chave.outNome, std::ios::app);
    int pos;
    pos = hashId(chave, M);
    Email aux;
    aux = Arvore[pos].Pesquisa(chave);
    if(aux.idMensagem == -1)
        fileOut << "ERRO: MENSAGEM INEXISTENTE" << endl;
    else{
        Arvore[pos].Remove(chave);
        fileOut << "OK: MENSAGEM APAGADA" << endl;
    }
        
    fileOut.close();
}


