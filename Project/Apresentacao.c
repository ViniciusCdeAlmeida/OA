/**
* @file interface_impl.c
* @brief Faz opera��es de output e input. Trabalhando diretamente com a L�gica de Neg�cio.
* @author Charles Cardoso de Oliveira
* @version 1.4
* @date Cria��o: 28/12/2012
* @date Modifica��o 1: 02/01/2013
* @date Modifica��o 2: 08/01/2013
* @date Modifica��o 3: 15/01/2013
* @date Modifica��o 4: 03/02/2013
*/

/* Includes */
#include "Apresentacao.h"

/*
 Fun��o respons�vel por imprimir as funcionalidades do BLOG para o Usu�rio.
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
 Fun��o respons�vel por invocar as diversas fun��es do BLOG dependendo da escolha do usu�rio.
*/
void opcao_usuario(){
/* Declara��es */
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
Recebe da l�gica de Neg�cio um ponteiro de Listagens contendo todos os Identificadores de Usuario.
E se a lista n�o for vazia, imprime todos esses identificadores.

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
 Fun��o recebe os dados Nome de Usu�rio, Senha e Identificador do usu�rio.
 Passa esses dados para a l�gica de neg�cio.
 E por fim informa ao usu�rio o resultado.

void cadastro_usuario(){
/* Declara��es 
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

/* Verifica se o usu�rio est� autenticado.
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

/* Verifica se o usu�rio est� autenticado.
Se estiver recebe as novas informa��es do usu�rio e manda para a l�gica.
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