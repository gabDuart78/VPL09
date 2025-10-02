#include <iostream>
#include <string>

#include "Parque.hpp"
#include "MontanhaRussa.hpp"
#include "Carrossel.hpp"
#include "RodaGigante.hpp"

const std::string carrossel = "car";
const std::string montanha_russa = "mr";
const std::string roga_gigante = "rod";

enum Command {LOAD, DEMAND, RUN, PAUSE, RESUME, STATUS, PAINEL, EXIT, INVALID};

const std::string commands[] = {"carregar", "demanda", "rodar" , "pausar", "retomar","status", "painel", "encerrar"};

Command convert_to_command(const std::string& s)
{
    if (commands[0] == s) return LOAD;
    if (commands[1] == s) return DEMAND;
    if (commands[2] == s) return RUN;
    if (commands[3] == s) return PAUSE;
    if (commands[4] == s) return RESUME;
    if (commands[5] == s) return STATUS; 
    if (commands[6] == s) return PAINEL;
    if (commands[7] == s) return EXIT;

    return INVALID;
}

void carregar_brinquedos(Parque *p, int n)
{
    std::string iden, cod;
    int year, cap, el;
    double pow;

    for (int i = 0; i < n; i++) {
        std::cin >> iden >> cod >> year >> pow >> cap >> el;
        Brinquedo *b = nullptr;

        if (carrossel == iden) 
            b = new Carrossel(cod, year, pow, cap, el);
        
        if (montanha_russa == iden) 
            b = new MontanhaRussa(cod, year, pow, cap, el);

        if (roga_gigante == iden)
            b = new RodaGigante(cod, year, pow, cap, el);

        p->adicionar(b);
    }

}

int main() 
{
    Parque *p = new Parque();
    std::string comd, cod;
    int n;
    bool is_running = true;

    while(is_running) {
        std::cin >> comd;
        Command command = convert_to_command(comd);

        switch (command) {
            case LOAD:
                std::cin >> n;
                carregar_brinquedos(p, n);
                break;
            case DEMAND:
                std::cin >> n; 
                p->definir_demanda(n);
                break;
            case RUN:
                std::cin >> n;
                p->rodar(n);
                break;
            case STATUS:
                std::cin >> cod;
                p->status(cod);
                break;
            case PAUSE:
                std::cin >> cod;
                p->pausar(cod);
                break;
            case RESUME:
                std::cin >> cod;
                p->retomar(cod);
                break;
            case PAINEL:
                p->painel();
                break;
            case EXIT:
                is_running = false;
                break;
            case INVALID:
                std::cout << "Invalid command.\n";
                break;
            default:
                break;
        }
    }

    delete p;

    return 0;
}
