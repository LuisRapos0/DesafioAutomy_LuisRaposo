#ifndef BATERIA_H
#define BATERIA_H

#include <string>

/**
 * @brief Estrutura que representa uma bateria agendada por um usuário.
 * 
 * Esta estrutura é usada para armazenar as informações relacionadas a uma bateria,
 * incluindo dados pessoais do usuário que fez a reserva, horário e data do agendamento,
 */
struct Bateria {
    std::string data_agendamento;
    std::string datetime_formulario;
    std::string email;
    std::string horario_agendamento;
    std::string nome;
    std::string qtde_pessoas;
    std::string telefone;  
};

#endif