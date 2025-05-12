#include "../include/autenticacao.h"
#include "../include/consultas.h"
#include "../include/terminal.h"

int main() {
    // flags
    bool processing_login = false;
    bool processing_login_error = false;
    bool logged_in = false;

    Autenticacao user;
    Terminal terminal;
    Consultas requests;
    std::vector <Bateria> responsed_baterias;

    system ("clear");

    while (true) {
        terminal.msgBoasVindas();

        char input_digit = terminal.catchDigit();
        switch (input_digit){
            case '1':
                processing_login = true;
                break;
            case '2':
                return 0;
            case ' ':
                break;
            default:
                terminal.inputErrado();
                break;
        }

        while (processing_login){
            terminal.msgProcessLogin();

            std::string username = terminal.catchUsername();
            std::string password = terminal.catchPassword();
            user.setAttributes(username, password);

            user.setActiveToken(user.requestNewToken());

            if (user.getActiveToken() == "error") {
                processing_login_error = true;

                while (processing_login_error) {
                    terminal.msgProcessLoginError();

                    input_digit = terminal.catchDigit();
                    switch (input_digit){
                        case '1':
                            processing_login_error = false;
                            break;
                        case '2':
                            processing_login = false;
                            processing_login_error = false;
                            break;
                        case ' ':
                            break;
                        default:
                            terminal.inputErrado();
                            break;
                    }
                }
            }

            else {
                processing_login = false;
                logged_in = true;
            }
        }

        while (logged_in){
            terminal.msgLoggedInHomepage(user.getUsername());

            char input_digit = terminal.catchDigit();
            switch (input_digit){
            case '1':
                user.setActiveToken(user.requestNewTokenIfExpired());
                responsed_baterias = requests.requestNoFilter(user.getActiveToken());
                terminal.printRequestResultsAll(responsed_baterias);
                break;
            case '2':
                user.setActiveToken(user.requestNewTokenIfExpired());
                responsed_baterias = requests.requestScheduledBateries(user.requestNewTokenIfExpired());
                terminal.printRequestResultsMostRecent(responsed_baterias);
                break;
            case '3':
                user.setActiveToken(user.requestNewTokenIfExpired());
                responsed_baterias = requests.requestPastBateries(user.requestNewTokenIfExpired());
                terminal.printRequestResultsMostRecent(responsed_baterias);
                break;
            case '4':
                logged_in = false;
                user.setAttributes("","");
                user.setActiveToken("");
                break;
            case ' ':
                break;
            default:
                terminal.inputErrado();
                break;
            }
        }
    }
    return 0;
}
