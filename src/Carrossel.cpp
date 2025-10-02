#include "Carrossel.hpp"
#include <algorithm>
#include <iomanip>

const double tax = 6.0;
const double factor = 0.75;

Carrossel::Carrossel(const std::string& cod, int ano, double kw, int cap, int bichos)
    : Brinquedo(cod, ano, kw, cap), _bichos(bichos) 
{
}

std::string Carrossel::tipo() const {
   return "Carrossel"; 
}

void Carrossel::imprimir_status() const {
    std::cout << codigo() << ' ' << tipo() << ' ' << ano() << ' ' 
        << capacidade() << ' ' << std::fixed << std::setprecision(1) 
        << potencia_kw() << ' ';
    if (pausado()) 
        std::cout << "pausado";
    else 
        std::cout << "ativo";
    std::cout << " bichos " << _bichos << '\n'; 
}

void Carrossel::operar_tick(int demanda, int& atendidos, double& receita, double& energia) {
    if (demanda == 0) return;

    atendidos = demanda >= capacidade() ? capacidade() : demanda;
    receita = (tax + factor * _bichos) * atendidos;

        energia = potencia_kw() * .3;
}
