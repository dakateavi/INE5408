#include "Lancamento.h"

Lancamento::Lancamento(char* nome,const double& valor):
	valor(valor)
{
    this->nome = new char[strlen(nome) + 1];
    strcpy(this->nome,nome);
}

bool Lancamento::operator<(const Lancamento& aSerComparado) const {
        return (pegarValor() < aSerComparado.pegarValor());
}

double Lancamento::pegarValor() const {
        return this->valor;
}
char* Lancamento::pegarNome() const {
        return this->nome;
}