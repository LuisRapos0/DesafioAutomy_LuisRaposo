#include "../include/baterias_sorting.h" 

std::time_t BateriaSorting::dateToTime (const std::string& date) {
    std::tm tm = {};
    std::stringstream ss(date);
    ss >> std::get_time(&tm, "%d/%m/%Y"); 
    return std::mktime(&tm); 
}

std::vector<Bateria> BateriaSorting::sortMostRecentFirst (std::vector<Bateria> baterias) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);

    // Faz um sort no vetor baterias, com aquelas cuja data é mais próxima da data do sistema colocadas em primeiro
    std::sort(baterias.begin(), baterias.end(), [this, current_time] (const Bateria& a, const Bateria& b) {

        std::time_t a_time = dateToTime(a.data_agendamento);
        std::time_t b_time = dateToTime(b.data_agendamento);

        int a_diff = std::abs(std::difftime(a_time, current_time));
        int b_diff = std::abs(std::difftime(b_time, current_time));

        return a_diff < b_diff; 
    });

    return baterias;
}

std::vector<Bateria> BateriaSorting::sortFutureFirst (std::vector<Bateria> baterias) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);

    // Faz um sort no vetor baterias, começando por aquelas cuja data é a mais futura
    std::sort(baterias.begin(), baterias.end(), [this, current_time] (const Bateria& a, const Bateria& b) {

        std::time_t a_time = dateToTime(a.data_agendamento);
        std::time_t b_time = dateToTime(b.data_agendamento);

        return a_time > b_time; 
    });

    return baterias;
}