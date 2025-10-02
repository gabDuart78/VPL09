#include "RodaGigante.hpp"
#include <algorithm>
#include <iomanip>

const double tax = 8.0;
const double factor = 0.5;

RodaGigante::RodaGigante(const std::string& cod, int ano, double kw, int cap, int cabines)
    : Brinquedo(cod, ano, kw, cap), _cabines(cabines) 
{
}

std::string RodaGigante::tipo() const 
{
    return "RodaGigante";
}

void RodaGigante::imprimir_status() const 
{
    std::cout << codigo() << ' ' << tipo() << ' ' << ano() << ' ' 
        << capacidade() << ' ' << std::fixed << std::setprecision(1) 
        << potencia_kw() << ' ';
    if (pausado()) 
        std::cout << "pausado";
    else 
        std::cout << "ativo";
    std::cout << " cabines " << _cabines << '\n'; 
}

void RodaGigante::operar_tick(int demanda, int& atendidos, double& receita, double& energia) 
{
    if (demanda == 0) return;

    atendidos = demanda >= capacidade() ? capacidade() : demanda;
    receita = (tax + factor * _cabines) * atendidos;

    energia = potencia_kw() * .5;
}
