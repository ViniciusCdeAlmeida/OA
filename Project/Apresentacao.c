/**
* @file interface_impl.c
* @brief Faz operações de output e input. Trabalhando diretamente com a Lógica de Negócio.
* @author Charles Cardoso de Oliveira
* @version 1.4
* @date Criação: 28/12/2012
* @date Modificação 1: 02/01/2013
* @date Modificação 2: 08/01/2013
* @date Modificação 3: 15/01/2013
* @date Modificação 4: 03/02/2013
*/

/* Includes */
#include "Apresentacao.h"

/*
 Função responsável por imprimir as funcionalidades do BLOG para o Usuário.
*/
void menu_inicial(){

  
    printf("******************** SISTEMA DE BLOG *************************\n");
    printf("**************************************************************\n");
   
    printf("01 - FAZER CADASTRO.\n");
    printf("02 - ALTERAR CADASTRO.\n");
    printf("03 - DESCADASTRAR UMA CONTA.\n");
    printf("04 - FAZER UMA POSTAGEM.\n");
    printf("05 - COMENTAR UMA POSTAGEM.\n");
    printf("06 - LISTAR IDENTIFICADORES DOS USUARIOS.\n");
    printf("07 - LISTAR IDENTIFICADORES DE POSTAGENS.\n");
    printf("08 - LISTAR TEXTO DE POSTAGENS.\n");
    printf("09 - LISTAR COMENTARIOS ASSOCIADOS A POSTAGENS.\n");
    printf("10 - REMOVER COMENTARIOS ASSOCIADOS AS SUAS POSTAGENS.\n");
    printf("11 - AVALIAR ALGUMA POSTAGEM.\n");
    printf("12 - FAZER LOGIN.\n");
    printf("13 - ENCERRAR SECAO (LOGOFF)\n");
    printf("14 - SAIR DO SISTEMA.\n");
    printf("**************************************************************\n");
}

/*
 Função responsável por invocar as diversas funções do BLOG dependendo da escolha do usuário.
*/
void opcao_usuario(){
/* Declarações */
int opcaoUsuario;

    do{
    printf ("POR FAVOR ESCOLHA UMA OPCAO: ");
    scanf ("%d", &opcaoUsuario);
        switch(opcaoUsuario){
            case 1:
                system("CLS");
                cadastro_registro();
                system("PAUSE");
                system("CLS");
                menu_inicial();
                break;
            case 2:
                system("CLS");
                altera_registro();
                system("PAUSE");
                system("CLS");
                menu_inicial();
                break;
            case 3:
                system("CLS");
                deleta_registro();
                system("PAUSE");
                system("CLS");
               menu_inicial();
                break;
            case 13:
                system("CLS");
                break;
            case 14:
                system("CLS");
                printf("O SISTEMA FOI FECHADO COM SUCESSO.\n");
                system("PAUSE");
                break;
            default:
                system("CLS");
                printf("ERRO: OPCAO ESCOLHIDA NAO EXISTE.\n");
                system("PAUSE");
                system("CLS");
                menu_inicial();
                break;
        }
    }while(opcaoUsuario!=14);
}

/*
Recebe da lógica de Negócio um ponteiro de Listagens contendo todos os Identificadores de Usuario.
E se a lista não for vazia, imprime todos esses identificadores.

void lista_identificador_usuario(){
/*Listagens *listagens, *p;

 listagens = preenche_listagens_usuario();
    if(listagens==NULL){
    printf("NAO HA NENHUM USUARIO CADASTRADO.\n");
    }
    else{
        for(p=listagens;p!=NULL;p=p->proximo){
        printf("Identificador Usuario: %s\n", p->informacao);
        }
    }*/
//}
/*
 Função recebe os dados Nome de Usuário, Senha e Identificador do usuário.
 Passa esses dados para a lógica de negócio.
 E por fim informa ao usuário o resultado.

void cadastro_usuario(){
/* Declarações 
char nomeUsuario[TAM_NOME], identificador[TAM_ID], senha[TAM_SENHA];
int respostaLogica;

    printf("********** CADASTRO DE USUARIO **********\n");
    printf("Digite seu nome de usuario (ate 10 digitos): ");
    scanf("%s", nomeUsuario);
    printf("Digite sua senha (ate 6 digitos): ");
    scanf("%s", senha);
    printf("Digite o seu identificador (ate 5 digitos): ");
    scanf("%s", identificador);
/*    respostaLogica = preenche_usuario(nomeUsuario, identificador, senha);
        if(respostaLogica == SUC_FUNCAO){
        printf("CADASTRO EFETUADO COM SUCESSO.\n");
        }
        else{
        printf("IDENTIFICADOR DE USUARIO JA EXISTE. POR FAVOR TENTE NOVAMENTE.\n");
        }
}

/* Verifica se o usuário está autenticado.
Se estiver logado o descadastra e altera o estadoUsuario para USUARIO_DESLOGADO.

void descadastro_usuario(int *estadoUsuario){
    if(*estadoUsuario == USUARIO_DESLOGADO){
    printf("VOCE PRECISA ESTAR LOGADO PARA EXECUTAR ESSA ACAO.\n");
    }
    else {
    /* respostaLogica = elimina_usuario(id); 
    printf ("SUA CONTA FOI DESCADASTRADA COM SUCESSO.\n");
    *estadoUsuario = USUARIO_DESLOGADO;
    }
}

/* Verifica se o usuário está autenticado.
Se estiver recebe as novas informações do usuário e manda para a lógica.
Imprime resultado.

void altera_cadastro(int *estadoUsuario){
char novoNomeUsuario[TAM_NOME], novaSenha[TAM_SENHA];

    if(*estadoUsuario == USUARIO_DESLOGADO){
    printf("VOCE PRECISA ESTAR LOGADO PARA EXECUTAR ESSA ACAO.\n");
    }
    else{
    printf("Digite o novo nome de usuario:");
    scanf("%s", novoNomeUsuario);
    printf("Digite a nova senha:");
    scanf("%s", novaSenha);
    /* repostaLogica = atualiza_usuario(novoUsuario, id, novaSenha); 
    printf("SEUS DADOS FORAM ALTERADOS COM SUCESSO.\n");
    }
}
*/

int main(){
	return 0;
}