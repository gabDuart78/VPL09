#ifndef BRINQUEDO_HPP
#define BRINQUEDO_HPP

#include <string>
#include <iostream>

class Brinquedo {
protected:
    std::string _codigo;
    int _ano;
    double _potencia_kw;
    int _capacidade;
    bool _pausado;

public:
    Brinquedo(const std::string& codigo, int ano, double potencia_kw, int capacidade);
    virtual ~Brinquedo();

    std::string codigo() const;
    int ano() const;
    double potencia_kw() const;
    int capacidade() const;
    bool pausado() const;

    void pausar();
    void retomar();

    virtual std::string tipo() const = 0;
    virtual void imprimir_status() const = 0;
    virtual void operar_tick(int demanda, int& atendidos, double& receita, double& energia) = 0;
};

#endif
