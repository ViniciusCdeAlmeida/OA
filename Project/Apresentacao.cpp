
/* Includes */
#include "Apresentacao.h"

/*
 Função responsável por imprimir as funcionalidades do BLOG para o Usuário.
*/
void menu_inicial(){

    printf("********************  Melhores Bandas de Todos os Tempos: *************************\n");
    printf("**************************************************************\n");
   
    printf("01 - Eliminar Banda.\n");
    printf("02 - Editar Banda.\n");
    printf("03 - Adicionar Banda.\n");
    printf("04 - Rank.\n");
	 printf("05 - Sair do sistema.\n");
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
				void deleta_registro();
                system("PAUSE");
                system("CLS");
                menu_inicial();
                break;
            case 2:
                system("CLS");
                void altera_registro();
                system("PAUSE");
                system("CLS");
                menu_inicial();
                break;
            case 3:
                system("CLS");
                void cadastro_registro();
                system("PAUSE");
                system("CLS");
                menu_inicial();
                break;
			 case 4:
                system("CLS");
                void lista_resgistro();
                system("PAUSE");
                system("CLS");
                menu_inicial();
                break;
            case 5:
                system("CLS");
                printf("O SISTEMA FOI FECHADO COM SUCESSO.\n");
                system("PAUSE");
                break;
            default:
                system("CLS");
                printf("ERRO: OPCAO ESCOLHIDA NAO EXISTE.\n");
                system("PAUSE");
                system("CLS");
                void menu_inicial();
                break;
        }
    }while(opcaoUsuario!=5);
}

/*
Recebe da lógica de Negócio um ponteiro de Listagens contendo todos os Identificadores de Usuario.
E se a lista não for vazia, imprime todos esses identificadores.

void lista_resgistro(){
/*Listagens *listagens, *p;

 listagens = lista_resgistro();
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

void cadastro_registro(){
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
/*  respostaLogica = preenche_usuario(nomeUsuario, identificador, senha);
		if(respostaLogica == SUC_FUNCAO){
			printf("CADASTRO EFETUADO COM SUCESSO.\n");
        }
        else{
			printf("IDENTIFICADOR DE USUARIO JA EXISTE. POR FAVOR TENTE NOVAMENTE.\n");
        }
}

/* Verifica se o usuário está autenticado.
Se estiver logado o descadastra e altera o estadoUsuario para USUARIO_DESLOGADO.

void deleta_registro(int *estadoUsuario){
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
	menu_inicial();
	opcao_usuario();
	return 0;
}
