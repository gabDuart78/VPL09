#ifndef MONTANHARUSSA_HPP
#define MONTANHARUSSA_HPP

#include "Brinquedo.hpp"

class MontanhaRussa : public Brinquedo {
private:
    int _loops;

public:
    MontanhaRussa(const std::string& cod, int ano, double kw, int cap, int loops);
    std::string tipo() const override;
    void imprimir_status() const override;
    void operar_tick(int demanda, int& atendidos, double& receita, double& energia) override;
};

#endif
