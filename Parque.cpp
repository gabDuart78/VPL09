#include "Parque.hpp"
#include <iostream>
#include <iomanip>

Parque::Parque(): _num_brinquedos(0), _demanda(0), _energia_acum(0), 
_receita_acum(0), _atendidos_acum(0) 
{
}

Parque::~Parque() 
{
    for (int i = 0; i < _num_brinquedos; i++) 
        delete _brinquedos[i];
}

Brinquedo* Parque::find_brinquedo(const std::string& cod) const 
{
    for (int i = 0; i < _num_brinquedos; i++) {
        if (_brinquedos[i]->codigo() == cod)
            return _brinquedos[i];
    }
    
    return nullptr;
}

void Parque::adicionar(Brinquedo* b) 
{
    if (_num_brinquedos >= MAX_BRINQUEDOS || b == nullptr) return;

    _brinquedos[_num_brinquedos] = b;
    _num_brinquedos++; 
}

void Parque::definir_demanda(int d) 
{
    _demanda = d;
}

void Parque::pausar(const std::string& cod) 
{
    Brinquedo* b = find_brinquedo(cod);

    if (b == nullptr) {
        std::cout << "Brinquedo informado nao existe.\n";
        return;
    }

    if (b->pausado()) {
        std::cout << "Brinquedo ja esta pausado.\n";
        return;
    }

    b->pausar();
}

void Parque::retomar(const std::string& cod) 
{
     Brinquedo* b = find_brinquedo(cod);

    if (b == nullptr) {
        std::cout << "Brinquedo informado nao existe.\n";
        return;
    }

    if (!b->pausado()) {
        std::cout << "Brinquedo ja esta em operacao.\n";
        return;
    }

    b->retomar();
}

void Parque::rodar(int T) 
{
    for (int i = 0; i < T; i++ ) {
        int demanda_per_tick = _demanda;
        for (int i = 0; i < _num_brinquedos; i++) {
            Brinquedo* b = _brinquedos[i];

            if (b->pausado()) continue;

            int atendidos = 0;
            double receita = 0;
            double energia = 0;

            b->operar_tick(demanda_per_tick, atendidos, receita, energia);

            _atendidos_acum += atendidos;
            demanda_per_tick -= atendidos;
            _receita_acum += receita;
            _energia_acum += energia;
        }
    }
}

void Parque::status(const std::string& cod) const 
{
    Brinquedo*  b = find_brinquedo(cod);

    if (b == nullptr) {
        std::cout << "Brinquedo informado nao existe.\n";
        return;
    }
    
    b->imprimir_status();
}

void Parque::painel() const 
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << _energia_acum << ' ' << _receita_acum << ' ' << _atendidos_acum << '\n';
}

