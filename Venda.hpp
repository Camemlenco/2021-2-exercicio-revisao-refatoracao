////NOTA DE ALTERA��ES
//Classe Venda passa a receber um ponteiro para os clientes ao inv�s do nome
//Classe Venda passa a receber um ponteiro para os clientes ao inv�s de uma c�pia do elemento
//Vari�vel valor foi alterada para os padr�es de nomeclatura
//Cria��o de m�todo construtor
//Remo��o de c�digos n�o utilizados

#ifndef VENDA_HPP
#define VENDA_HPP

#include "Funcionario.hpp"
#include "Cliente.hpp"
#include "Especialista.hpp"

using namespace std;

class Venda{

public:
    //Dados das vendas
    double valor;
    string descricao;
    Especialista* esp;
    Cliente* clientPointer;

    //Inicializa��o dos atributos da classe
    Venda(Cliente* _cPointer, Especialista* _ePointer,string _descricao, double _valor) {
        this->clientPointer = &_cPointer;
        this->esp = &_ePointer;
        this->descricao = _descricao;
        this->valor = _valor;
        
        //Atribui��o dos valores de comiss�o e qtd de atendimentos do especialista
        esp->comissaoValor += esp->comissao(this->valor);
        esp->numAtendimentos++;
    }

    //Impress�o de infos da venda
    void print() {

        std::cout << "Especialista: ";
        cout << esp->nome;

        std::cout << " Cliente: ";
        cout << clientPointer->nome;

        cout << " Descricao: " << this->descricao << endl;
    }
};

#endif
