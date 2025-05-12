# Desafio Automy

Solução proposta para o Desafio Automy Github.

# Tecnologias Utilizadas

    C++: desenvolvimento do backend e uma interface simples no terminal bash.

# Como Rodar o Projeto Localmente
1. **Clonar o Repositório**

Clone o repositório com o seguinte comando:

    git clone https://github.com/LuisRapos0/DesafioAutomy_LuisRaposo.git

2. **Navegue até a pasta com o DockerFile**

Basta executar os seguintes comandos:

    cd DesafioAutomy_LuisRaposo/DesafioAutomy_LuisRaposo

3. **Build do Container**

Já no diretório correto, execute o comando para construir o container:

    docker-compose build

3. **Executar a Aplicação**

Depois de construir o container, execute a aplicação com:

    docker-compose run app

Este comando irá então iniciar a aplicação em um terminal bash gerado no container.

# Como Utilizar o App

1. Logo após executar o app, você será redirecionado a uma tela de Boas vindas.

2. Para navegar pelos menus, basta digitar o número correspondente à opção desejada.

3. Ao selecionar a opção login, você deve se autenticar com um par Usuário/Senha válidos no banco de dados. Nesse caso, utilizar (sem as aspas):

    Usuário: "fldoaogopdege"

    Senha: "ygalepsm"

4. Feita a autenticação, você será redirecionado a uma página onde estão disponíveis os tipos de consulta especificados no desafio. Novamente, digite o número correspondente à opção desejada.

5. Feita a requisição, insira o email a ser utilizado na consulta. Nesse caso, utilizar (sem as aspas):

    E-mail: "john.doe@gmail.com"

6. O usuário pode então fazer quantas consultas quiser, e o token será automaticamente renovado se estiver para expirar.

# Funções Disponíveis

1. Sistema de Login/Logout simples.

2. Sistema de requisição e autenticação do token como especificado.

3. Interface no terminal bash para navegação do app.

4. Realizar consultas no banco de dados por meio de Query's, com esse projeto especificando requisições de baterias futuras, passadas e todas atreladas ao usuário.

5. Feitas as consultas, receber e tratar os dados para produzir no terminal bash relatórios contendo as informações relevantes.
