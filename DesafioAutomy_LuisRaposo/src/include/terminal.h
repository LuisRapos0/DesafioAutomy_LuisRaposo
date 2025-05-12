#ifndef TERMINAL_H
#define TERMINAL_H

#include "./bateria.h"
#include "./baterias_sorting.h"

#include <iostream>
#include <string>
#include <limits>

/**
 * @brief Classe que gerencia as interações com o terminal da aplicação.
 */
class Terminal {
public:
    // Printa no terminal a mensagem de boas vindas
    void msgBoasVindas ();

    // Printa no terminal a mensagem de processamento de login
    void msgProcessLogin ();

    // Printa no terminal a mensagem de erro de autenticacao no Login
    void msgProcessLoginError ();

    // Printa no terminal a mensagem da homepage do usuário logado
    void msgLoggedInHomepage (std::string username);

    // Printa uma mensagem de erro caso o input tenha sido inválido e limpa o buffer
    void inputErrado ();

    // Recebe um dígito do terminal e limpa o buffer. Caso uma string seja inserida, retorna como padrão ' ' e chama inputErrado()
    char catchDigit ();

    // Printa a interface e recebe o valor "username" do terminal
    std::string catchUsername ();

    // Printa a interface e recebe o valor "password" do terminal
    std::string catchPassword ();

    // Printa a interface e recebe o valor "email" do terminal
    std::string catchEmail ();

    // Printa no terminal os resultados de uma consulta de todas as baterias associadas ao usuário
    void printRequestResultsAll (std::vector<Bateria> baterias);

    // Printa no terminal os resultados de uma consulta das baterias que ainda não ocorreram associadas ao usuário
    void printRequestResultsFuture (std::vector<Bateria> baterias);

    // Printa no terminal os resultados de uma consulta das baterias que já ocorreram associadas ao usuário
    void printRequestResultsPast (std::vector<Bateria> baterias);
    
private:
    BateriaSorting bateria_sorting;
};



#endif