#include "MontanhaRussa.hpp"
#include <algorithm>
#include <iomanip>

const double tax = 12.0;
const double factor = 0.25;

MontanhaRussa::MontanhaRussa(const std::string& cod, int ano, double kw, int cap, int loops)
    : Brinquedo(cod, ano, kw, cap), _loops(loops) {
}

std::string MontanhaRussa::tipo() const 
{
    return "MontanhaRussa";
}

void MontanhaRussa::imprimir_status() const 
{
  std::cout << codigo() << ' ' << tipo() << ' ' << ano() << ' ' 
        << capacidade() << ' ' << std::fixed << std::setprecision(1) 
        << potencia_kw() << ' ';
    if (pausado()) 
        std::cout << "pausado";
    else 
        std::cout << "ativo";
    std::cout << " loops " << _loops << '\n'; 
}

void MontanhaRussa::operar_tick(int demanda, int& atendidos, double& receita, double& energia) 
{
    if (demanda == 0)
        return;

    atendidos = demanda >= capacidade() ? capacidade() : demanda;
    receita = (tax + factor * _loops) * atendidos;

    energia = potencia_kw() * 0.8;
}
