#ifndef BATERIAS_SORTING_H
#define BATERIAS_SORTING_H

#include "./bateria.h"

#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>

/**
 * @brief Classe que armazena os algoritmos de ordenação para os vetores de Baterias.
 */
class BateriaSorting {
public:
    // Converte uma string de data no formato "DD/MM/YYYY" para um time_t
    std::time_t dateToTime (const std::string& date);

    // Reordena o vetor <agendamentos> colocando as baterias mais próximas à data do sistema primeiro
    std::vector<Bateria> sortMostRecentFirst (std::vector<Bateria> agendamentos);

    // Reordena o vetor <agendamentos> colocando as baterias mais futuras primeiro
    std::vector<Bateria> sortFutureFirst (std::vector<Bateria> agendamentos);
};

#endif