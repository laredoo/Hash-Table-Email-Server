#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include "../include/arvore_binaria.h"
#include "../include/email.h"
#include "../include/servidor.h"

using namespace std;

//variaveis globais
int M = -1; //tamanho da tabela Hash
int operacao = -1; //tipo de operacao
int U = 0; //identificador do destinatario da mensagem
int E = 0; //identificador do email (chave para armazenar a mensagem na posicao adequada da arvore)
int N = 0; //numero de palavras da mensagem
string msg[201]; //vetor de palavras
string logNome; //nome do arquivo de entrada
string outNome; //nome do arquivo de saida


void testaNome(string logNome, string outNome) {
    if(logNome.length() <= 0) {
      cout << "-i não definido" << endl;
      exit(1);
    }
    else if(outNome.length() <= 0) {
      cout << "-o não definido" << endl;
      exit(1);
    }
}

void resetaOut() {
    ofstream fileOut(outNome);
    fileOut << "";
}

int main(int argc, char ** argv) {

    string aux;
    Email mail;

    //encontra o nome dos arquivos de entrada e saida
    for(int i = 0; i < argc; i++)
    {
      aux = argv[i];
      if(aux == "-i" || aux == "-I")
        logNome = argv[i+1];
      else if(aux == "-o" || aux == "-O")
        outNome = argv[i+1];
    }

    mail.outNome = outNome;

    //condicao de existencia para o nome de entrada e saida
    testaNome(logNome, outNome);

    //leitura de arquivos
    string line;
    ifstream FILE(logNome);
    if(!FILE.is_open())
    {
      cout << "File could not be opened" << endl;
      exit(1);
    }

    //inicializando arquivo de saida
    ofstream fileOut(outNome, std::ios::app);
    resetaOut();
    if(!fileOut.is_open())
    {
        cout << "Couldn't open the out file" << endl;
        exit(1);
    }

    for (int i = 0; i < 1; i++)
    {
        FILE >> line;
        M = stoi(line);
    }

    Hash_LE arvoreEmail(M);

    while (FILE >> line) {
        if(operacao == 1) {
            U = stoi(line);
            mail.idDestinatario = U;
            FILE >> line;
            E = stoi(line);
            mail.idMensagem = E;
            FILE >> line;
            N = stoi(line);
            mail.tamanhoMensagem = N;
            for(int i = 0; i < N; i++) {
                FILE >> line;
                msg[i] = line;
                mail.msg += line;
                if(i != N-1)
                    mail.msg += " ";
            }
            arvoreEmail.Insere(mail, M);
            mail.msg = "";
            operacao = 0;
        }
        if(operacao == 2) {
            U = stoi(line);
            mail.idDestinatario = U;
            FILE >> line;
            E = stoi(line);
            mail.idMensagem = E;
            FILE >> line;
            arvoreEmail.Pesquisa(mail, M);
            operacao = 0;
        }
        if(operacao == 3) {
            U = stoi(line);
            mail.idDestinatario = U;
            FILE >> line;
            E = stoi(line);
            mail.idMensagem = E;
            FILE >> line;
            arvoreEmail.Remove(mail, M);
            operacao = 0;  
        }
        if(line == "ENTREGA")
            operacao = 1;
        else if(line == "CONSULTA")
            operacao = 2;
        else if(line == "APAGA")
            operacao = 3;
    }

    FILE.close();
    fileOut.close();

    /* 
    cout << " M " << M << endl;
    cout << " U " << U << endl;
    cout << " E " << E << endl;
    cout << " N " << N << endl;
    cout << mail.outNome << endl;

    for(int i = 0; i < N; i++)
        cout << msg[i] << endl; 
    */
    return 1;
}
