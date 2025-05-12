#include "../include/consultas.h"

size_t write_callback(void *ptr, size_t size, size_t nmemb, std::string *data) {
    size_t total_size = size * nmemb;
    data->append((char*)ptr, total_size);
    return total_size;
}

std::vector<Bateria> Consultas::requestNoFilter(const std::string token, const std::string email) {
    nlohmann::json request_data = {
        {"query", "SELECT * FROM desafio.cadastro_baterias_desafio WHERE email = '" + email + "'"},
        {"db", "desafio"}
    };

    return makeRequest(token, request_data);
}

std::vector<Bateria> Consultas::requestScheduledBateries(const std::string token, const std::string email) {
    nlohmann::json request_data = {
        {"query", "SELECT * FROM desafio.cadastro_baterias_desafio WHERE STR_TO_DATE(data_agendamento, '%d/%m/%Y') >= CURDATE() AND email = '" + email + "'"},
        {"db", "desafio"}
    };

    return makeRequest(token, request_data);
}

std::vector<Bateria> Consultas::requestPastBateries (const std::string token, const std::string email) {
    nlohmann::json request_data = {
        {"query", "SELECT * FROM desafio.cadastro_baterias_desafio WHERE STR_TO_DATE(data_agendamento, '%d/%m/%Y') < CURDATE() AND email = '" + email + "'"},
        {"db", "desafio"}
    };

    return makeRequest(token, request_data);
}

std::vector<Bateria> Consultas::makeRequest (const std::string token, nlohmann::json request_data) {
    std::vector <Bateria> agendamentos;
    CURL *curl;
    CURLcode response;
    std::string response_data;

    std::string post_data = request_data.dump();

    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Erro na criação do curl!" << std::endl;
        return agendamentos;
    }

    struct curl_slist *headers = curl_slist_append(NULL, "Content-Type: application/json");
    headers = curl_slist_append(headers, ("Authorization: Bearer " + token).c_str());

    curl_easy_setopt(curl, CURLOPT_URL, "https://appsaccess.automy.com.br/api/api/desafio/custom/do/query");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

    response = curl_easy_perform(curl);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (response != CURLE_OK) {
        std::cerr << "Erro na requisição: " << curl_easy_strerror(response) << std::endl;
        return agendamentos;
    } 

    nlohmann::json response_json = nlohmann::json::parse(response_data);

    try {
        for (const auto& item : response_json) {
            Bateria new_agendamento;

            new_agendamento.data_agendamento    = item["data_agendamento"];
            new_agendamento.datetime_formulario = item["datetime_formulario"];
            new_agendamento.email               = item["email"];
            new_agendamento.horario_agendamento = item["horario_agendamento"];
            new_agendamento.nome                = item["nome"];
            new_agendamento.qtde_pessoas        = item["qtde_pessoas"];
            new_agendamento.telefone            = item["telefone"];

            agendamentos.push_back(new_agendamento);
        }
    } catch (const std::exception &error) {
        std::cerr << "Erro ao processar a resposta JSON: " << error.what() << std::endl;
        return agendamentos;
    }

    return agendamentos;
}
