#ifndef RODAGIGANTE_HPP
#define RODAGIGANTE_HPP

#include "Brinquedo.hpp"

class RodaGigante : public Brinquedo {
private:
    int _cabines;

public:
    RodaGigante(const std::string& cod, int ano, double kw, int cap, int cabines);
    std::string tipo() const override;
    void imprimir_status() const override;
    void operar_tick(int demanda, int& atendidos, double& receita, double& energia) override;
};

#endif
