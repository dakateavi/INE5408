#include "Lancamento.h"

Lancamento::Lancamento(char* nome, double valor){
        this->nome = new char[strlen(nome) + 1];
        strcpy(this->nome,nome);
        this->valor = valor;
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