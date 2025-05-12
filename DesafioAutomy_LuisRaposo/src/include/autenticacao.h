#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include "./consultas.h"
#include <string>
#include <chrono>
#include <iostream>

// Valor constante em minutos para a duração do Token
constexpr int TOKEN_DURATION_MINUTES = 14;

/**
 * @brief Classe que contêm as atividades ligadas à autenticação da sessão.
 * 
 * Esta classe é usada para administrar questões relacionadas à sessão do usuário,
 * incluindo o gerenciamento do token JWT e os Atributos do usuário da sessão.
 */
class Autenticacao {
public:
    // Retorna o <username> do usuário da seção
    std::string getUsername ();

    // Retorna o <active_token> do usuário da seção
    std::string getActiveToken ();

    // Seta o <username> e <password> da seção
    void setAttributes (std::string new_username, std::string new_password);

    // Seta o <active_token> da seção
    void setActiveToken (std::string new_active_token);

    // Faz uma requisicao de um novo token
    std::string requestNewToken ();

    // Retorna o <active_tocken> se ainda não expirou, caso contrário retorna um novo
    std::string requestNewTokenIfExpired ();

    // Testa se o token está expirado
    bool isTokenExpired ();

    // Seta o horário de expiração do token para daqui <minutes> minutos
    void setExpirationTimeMinutes (unsigned int minutes);

private:
    std::chrono::system_clock::time_point expiration_time;
    std::string username;
    std::string password;
    std::string active_token;
};

#endif
