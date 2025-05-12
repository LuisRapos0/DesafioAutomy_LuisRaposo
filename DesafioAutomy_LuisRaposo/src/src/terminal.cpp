#include "../include/terminal.h"

void Terminal::msgBoasVindas () {
    system ("clear");
    std::cout << "---------------------------------------------------------------" << "\n";
    std::cout << "    Seja bem vindo ao sistema de consultas do kartódromo!" << "\n";
    std::cout << "---------------------------------------------------------------" << "\n";
    std::cout << "\n";
    std::cout << "Para navegar no sistema, digite o número correspondente à opção desejada." << "\n";
    std::cout << "\n";
    std::cout << "1 - Realizar login" << "\n";
    std::cout << "2 - Encerrar sessão" << "\n";
    std::cout << std::endl;
}

void Terminal::msgProcessLogin () {
    system ("clear");
    std::cout << "---------------------------------------------------------------" << "\n";
    std::cout << "       Iniciando Login, por favor digite os seus dados:" << "\n";
    std::cout << "---------------------------------------------------------------" << "\n";
    std::cout << std::endl;
}

void Terminal::msgProcessLoginError () {
    std::cout << "Escolha como proceder: " << "\n";
    std::cout << "\n";
    std::cout << "1 - Tentar Novamente" << "\n";
    std::cout << "2 - Retornar ao menu principal" << "\n";
    std::cout << std::endl;
}

void Terminal::msgLoggedInHomepage (std::string username) {
    system ("clear");
    std::cout << "---------------------------------------------------------------" << "\n";
    std::cout << "Olá senhor(a) " << username << "! Como podemos te auxiliar hoje?" << "\n";
    std::cout << "---------------------------------------------------------------" << "\n";
    std::cout << "\n";
    std::cout << "1 - Consultar todas as baterias" << "\n";
    std::cout << "2 - Consultar próximas baterias" << "\n";
    std::cout << "3 - Consultar baterias passadas" << "\n";
    std::cout << "4 - Fazer Logout" << "\n";
    std::cout << std::endl;
}

void Terminal::inputErrado () {
    std::cout << "\n";
    std::cout << "Por favor insira um dígito valido.\n";
    std::cout << "Pressione enter para continuar." << std::endl;
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char Terminal::catchDigit () {
    std::string digito;
    std::cin >> digito;

    if (digito.length() != 1) {
        inputErrado();

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ' ';
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return digito.at(0);
}

std::string Terminal::catchUsername () {
    std::string username;
    std::cout << "Usuário: ";
    std::getline (std::cin, username);

    return username;
}

std::string Terminal::catchPassword () {
    std::string password;
    std::cout << "Senha: ";
    std::getline (std::cin, password);
    std::cout << std::endl;

    return password;
}

std::string Terminal::catchEmail () {
    std::string email;
    std::cout << "---------------------------------------------------------------" << "\n";
    std::cout << "      Antes de prosseguir, por favor insira o seu e-mail:" << "\n";
    std::cout << "---------------------------------------------------------------" << "\n";
    std::cout << "\n";
    std::cout << "E-mail: ";
    std::getline (std::cin, email);
    std::cout << std::endl;
    
    return email;
}

void Terminal::printRequestResultsAll (std::vector<Bateria> baterias) {
    system ("clear");

    std::vector<Bateria> sortedBaterias = bateria_sorting.sortFutureFirst(baterias);

    if (sortedBaterias.empty()){
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << "Requisição feita com sucesso, mas nenhuma bateria foi encontrada."<< "\n";
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << "\n";
        std::cout << "Por favor, verifique o e-mail de consulta!" << "\n";
        std::cout << "\n";
    }
    else {
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << " Requisição feita com sucesso. Exibindo todas as baterias:" << "\n";
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << "\n";

        for (size_t i = 0; i+1 < sortedBaterias.size(); ++i) {
            std::cout << "=========================================================================" << "\n";
            std::cout << "Bateria " << i+1 << ":" << "\n";
            std::cout << "Agendada para o dia " << sortedBaterias[i].data_agendamento << " às " << sortedBaterias[i].horario_agendamento<< "\n";
            std::cout << "Reservada no nome de " << sortedBaterias[i].nome << "\n";
            std::cout << "Reserva feita para " << sortedBaterias[i].qtde_pessoas << " pessoas" << "\n";
        }

        std::cout << "=========================================================================" << "\n";
        std::cout << "\n";
        }
    std::cout << "Pressione Enter para retornar ao menu de consultas."; 
    std::cout << std::endl;

    std::cin.get(); 
}

void Terminal::printRequestResultsFuture (std::vector<Bateria> baterias) {
    system ("clear");

    std::vector<Bateria> sortedBaterias = bateria_sorting.sortMostRecentFirst(baterias);

    if (sortedBaterias.empty()){
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << "Requisição feita com sucesso, mas nenhuma bateria foi encontrada."<< "\n";
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << "\n";
        std::cout << "Por favor, verifique o e-mail de consulta!" << "\n";
        std::cout << "\n";
    }
    else {
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << " Requisição feita com sucesso. Exibindo as baterias agendadas:" << "\n";
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << "\n";

        for (size_t i = 0; i+1 < sortedBaterias.size(); ++i) {
            std::cout << "=========================================================================" << "\n";
            std::cout << "Bateria " << i+1 << ":" << "\n";
            std::cout << "Agendada para o dia " << sortedBaterias[i].data_agendamento << " às " << sortedBaterias[i].horario_agendamento<< "\n";
            std::cout << "Reservada no nome de " << sortedBaterias[i].nome << "\n";
            std::cout << "Reserva feita para " << sortedBaterias[i].qtde_pessoas << " pessoas" << "\n";
        }

        std::cout << "=========================================================================" << "\n";
        std::cout << "\n";
        }
    std::cout << "Pressione Enter para retornar ao menu de consultas."; 
    std::cout << std::endl;

    std::cin.get(); 
}

void Terminal::printRequestResultsPast (std::vector<Bateria> baterias) {
    system ("clear");

    std::vector<Bateria> sortedBaterias = bateria_sorting.sortMostRecentFirst(baterias);

    if (sortedBaterias.empty()){
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << "Requisição feita com sucesso, mas nenhuma bateria foi encontrada."<< "\n";
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << "\n";
        std::cout << "Por favor, verifique o e-mail de consulta!" << "\n";
        std::cout << "\n";
    }
    else {
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << " Requisição feita com sucesso. Exibindo as baterias passadas:" << "\n";
        std::cout << "---------------------------------------------------------------" << "\n";
        std::cout << "\n";

        for (size_t i = 0; i+1 < sortedBaterias.size(); ++i) {
            std::cout << "=========================================================================" << "\n";
            std::cout << "Bateria " << i+1 << ":" << "\n";
            std::cout << "Agendada para o dia " << sortedBaterias[i].data_agendamento << " às " << sortedBaterias[i].horario_agendamento<< "\n";
            std::cout << "Reservada no nome de " << sortedBaterias[i].nome << "\n";
            std::cout << "Reserva feita para " << sortedBaterias[i].qtde_pessoas << " pessoas" << "\n";
        }

        std::cout << "=========================================================================" << "\n";
        std::cout << "\n";
        }
    std::cout << "Pressione Enter para retornar ao menu de consultas."; 
    std::cout << std::endl;

    std::cin.get(); 
}