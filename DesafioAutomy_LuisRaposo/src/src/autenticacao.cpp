#include "../include/autenticacao.h" 

std::string Autenticacao::getUsername () {
    return username;
}

std::string Autenticacao::getActiveToken () {
    return active_token;
}

std::string Autenticacao::getEmail () {
    return email;
}

void Autenticacao::setAttributes (std::string new_username, std::string new_password) {
    username = new_username;
    password = new_password;
}

void Autenticacao::setActiveToken (std::string new_active_token) {
    active_token = new_active_token;
}

void Autenticacao::setEmail (std::string new_email) {
    email = new_email;
}

std::string Autenticacao::requestNewTokenIfExpired () {
    if (isTokenExpired()) {
        std::cout << "\n";
        std::cout << "O token está expirado, fazendo uma nova requisição..." << std::endl;
        active_token = requestNewToken();
    }
    return active_token;
}

std::string Autenticacao::requestNewToken () {
    CURL *curl;
    CURLcode response;
    std::string response_data;

    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Erro na criação do curl!" << std::endl;
        return "error";
    }

    nlohmann::json request_data = {
        {"username", username},
        {"password", password}
    };
    std::string POST_data = request_data.dump();
    struct curl_slist *headers = curl_slist_append(NULL, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, "https://appsaccess.automy.com.br/login");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, POST_data.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

    response = curl_easy_perform(curl);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (response != CURLE_OK) {
        std::cerr << "Ocorreu um erro na requisição: " << curl_easy_strerror(response) << std::endl;
        return "error";
    }

    nlohmann::json response_json = nlohmann::json::parse(response_data);

    if (response_json.contains("token")) {
        setExpirationTimeMinutes (TOKEN_DURATION_MINUTES);
        return response_json["token"];
    } 
    else {
        std::cerr << "Usuário e/ou senha incorretos." << std::endl;
    }

    return "error";
}

bool Autenticacao::isTokenExpired () {
    return std::chrono::system_clock::now() >= expiration_time;
}

void Autenticacao::setExpirationTimeMinutes (unsigned int minutes) {
    expiration_time = std::chrono::system_clock::now() + std::chrono::minutes(minutes);
}