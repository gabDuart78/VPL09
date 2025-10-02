#ifndef PARQUE_HPP
#define PARQUE_HPP

#include "Brinquedo.hpp"
#include <string>

const int MAX_BRINQUEDOS = 100;

class Parque {
private:
    Brinquedo* _brinquedos[MAX_BRINQUEDOS];
    int _num_brinquedos;
    int _demanda;
    double _energia_acum;
    double _receita_acum;
    int _atendidos_acum;

    // Dica: Um método auxiliar para encontrar um brinquedo pelo código é muito útil
    // para os comandos pausar, retomar e status.
    Brinquedo* find_brinquedo(const std::string& cod) const;

public:
    Parque();
    ~Parque();
    void adicionar(Brinquedo* b);
    void definir_demanda(int d);
    void pausar(const std::string& cod);
    void retomar(const std::string& cod);
    void rodar(int T);
    void status(const std::string& cod) const;
    void painel() const;
};

#endif
