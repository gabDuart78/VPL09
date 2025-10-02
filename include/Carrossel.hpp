#ifndef CARROSSEL_HPP
#define CARROSSEL_HPP

#include "Brinquedo.hpp"

class Carrossel : public Brinquedo {
private:
    int _bichos;

public:
    Carrossel(const std::string& cod, int ano, double kw, int cap, int bichos);
    std::string tipo() const override;
    void imprimir_status() const override;
    void operar_tick(int demanda, int& atendidos, double& receita, double& energia) override;
};

#endif
