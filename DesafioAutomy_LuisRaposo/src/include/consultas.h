#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "./bateria.h"

#include <string>
#include <vector>
#include <iostream>

#include <curl/curl.h>
#include <nlohmann/json.hpp>

// Esta função é usada para lidar com os dados recebidos em uma requisição de rede. Ela adiciona os dados a uma string fornecida como parâmetro.
size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* output);

/**
 * @brief Classe que contêm as consultas possíveis de se realizar no db.
 * 
 * Esta classe é usada para proteger a função que de fato faz a requisição no db,
 * e facilitar possíveis expansões
 */
class Consultas {
public:
    // Faz uma requisição no db sem filtros e retorna um vetor com todos os agendamentos relevantes
    std::vector <Bateria> requestNoFilter (const std::string token, const std::string email);

    // Faz uma requisição no db por baterias futuras e retorna um vetor com todos os agendamentos relevantes
    std::vector <Bateria> requestScheduledBateries (const std::string token, const std::string email);

    // Faz uma requisição no db por baterias passadas e retorna um vetor com todos os agendamentos relevantes
    std::vector <Bateria> requestPastBateries (const std::string token, const std::string email);

private:
    // Faz a requisição <request_data> no db e retorna um vetor com todos os agendamentos relevantes
    std::vector <Bateria> makeRequest(const std::string token, nlohmann::json request_data);
};

#endif
