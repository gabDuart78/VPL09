#include "Brinquedo.hpp"

Brinquedo::Brinquedo(const std::string& codigo, int ano, 
                     double potencia_kw, int capacidade) 
: _codigo(codigo), _ano(ano), 
_potencia_kw(potencia_kw), _capacidade(capacidade), _pausado(false)
{
}

Brinquedo::~Brinquedo() 
{
}

std::string Brinquedo::codigo() const 
{
    return _codigo;
}

int Brinquedo::ano() const 
{
    return _ano;
}

double Brinquedo::potencia_kw() const 
{
    return _potencia_kw;
}

int Brinquedo::capacidade() const 
{
    return _capacidade;
}

bool Brinquedo::pausado() const 
{
    return _pausado;
}

void Brinquedo::pausar() 
{
    _pausado = true;
}

void Brinquedo::retomar() 
{
    _pausado = false;
}
