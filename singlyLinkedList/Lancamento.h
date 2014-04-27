#ifndef _LANCAMENTO_H_
#define _LANCAMENTO_H_
#include <cstring>

class Lancamento{
public:
        Lancamento(char*,const double&);

        double pegarValor() const;
        char* pegarNome() const;
        bool operator<(const Lancamento&) const;

private:
        double valor;
        char* nome;
};


#endif
