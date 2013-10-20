
#ifndef LOGICA_H
#define LOGICA_H
#ifdef LOGICA_SERV
#define EXT_LOG
#else
#define EXT_LOG extern
#endif

/* Includes */

#include "Padroes.h"

/* Estruturas utilizadas */

/**
*   @brief Estrutura que define uma lista de strings
*/
typedef struct listagens{
    char *informacao;
    struct listagens *proximo;
} Listagens;

/**
*   @brief Estrutura que define um comentário
*/


/**
*   @brief Estrutura que define uma postagem
*/
typedef struct postagem {
    char idUsuario[TAM_ID],
         titulo[TAM_TITULO],
         conteudo[TAM_POST],
         identificador[TAM_ID],
         permissaoComentario;
    int avaliacaoSoma, avaliacaoQuantidade;
    int dia, mes, ano;
    int quantidadeComentarios;
    int byteOffset;
    char* primComentario, proxRelativoUsuario;
} Postagem;

/**
*   @brief Estrutura que define um usuário
*/
typedef struct usuario {
    char nome[TAM_NOME],
         senha[TAM_SENHA],
         identificador[TAM_ID];
    int byteOffset;
    char* primPostagem, primComentario;
} Usuario;

/**Funções de manipulação da lista*/
//lembrando que n estao completas nos prototipos e tem de haver uma revisão da lógica destes prototipos
/**
*   @brief cria uma estrutura de dados do tipo "lista" vazia
*   @param <nada>
*   @return retorna uma lista vazia
*/
EXT_LOG Listagens* cria_lista();//OK

/**
*   @brief insere elementos do tipo string dentro da lista
*   @param lista:estrutura de dados do tipo lista(vazia ou não)
*   @param info: uma string contendo a informação que se quer armazenar
*   @return retorna a lista inicial mais o elemento(info)
*/
EXT_LOG Listagens* insere_lista(Listagens* lista, char* info);//OK

/**
*   @brief deleta da memória a lista desejada
*   @param lista: estrutura de dados do tipo lista
*   @return <nada>
*/
EXT_LOG void deleta_lista(Listagens* lista);//OK


/**Funções de requisitos funcionais*/

/**
*   @brief fornece os dados de usuário, devidamente encaixados dentro da estrutura, para a persistência
*   @param name:nome do usuário
*   @param ID:identificador do usuário
*   @param senha:senha de acesso do usuário
*   @return retorna se foi bem sucedido ou não
*/
EXT_LOG int preenche_usuario(char* name,char* ID,char* senha);//OK?

/**
*   @brief procura o usuário desejado
*   @param ID: identificador do usuário a ser pesquisado
*   @return retorna uma estrutura de dados do tipo usuário com as informações do usuário
*/
EXT_LOG Usuario* procura_usuario(char* ID);//OK, ajuste no retorno da função recupera

/**
*   @brief procura a postagem desejada
*   @param ID:identificador da postagem
*   @param post:estrutura de dados que aramzenará as informações da postagem
*   @return retorna uma estrutura de dados do tipo postagem com as informações da postagem
*/

EXT_LOG int descadastro(char* ID);

/**
*   @brief fornece as novas informações do usuário a serem atualidas na persistência
*   @param novoUser: novo nome de usuário
*   @param novaSenha: nova senha de acesso do usuário
*   @param ID:identificador do usuário(fixo, portanto não será alterado)
*   @return retorna se foi bem sucedido ou não
*/
EXT_LOG int atualiza(char* novoUser, char* novaSenha, char* ID);//incompleto

/**
*   @brief elimina usuario
*   @param ID:identificador do usuário a ser eliminado
*   @return retorna se foi bem sucedido ou não
*/
EXT_LOG int elimina_usuario(char* ID);

/**
*   @brief armazena as informações dentro da estrutura Postagem e envia para a persistência
*   @param ID_User: identificador do usuário
*   @param Titulo: título da postagem
*   @param Texto: conteúdo da postagem
*   @param identificador: identificador da postagem
*   @param validacao: permissão de haver comentário
*   @return retorna se houve sucesso ou não
*/
EXT_LOG int preenche_postagem(char* ID_User,char* Titulo,char* Texto,char* identificador,char validacao);

EXT_LOG Listagens* preenche_listagens_usuario();

/**
*   @brief cria uma lista com todas as postagens daquele usuário
*   @param ID:identificador do usuário a ser pesquisado
*   @return lista contendo os identificadore das postagens
*/
EXT_LOG Listagens* preenche_listagens_postagem(char* ID);

/**
*   @brief cria uma lista de todos os comentários relacionados a uma certa postagem
*   @param ID_Post:identificador da postagem
*   @return lista contendo os identificadores
*/
EXT_LOG Listagens* preenche_listagens_comentario(char * ID_Post);

/**
*   @brief remove um certo comentario
*   @param ID_User:identificador de usuário
*   @param ID_Post:identificador da postagem
*   @param ID_Coment:identificador do comentário
*   @return retorna se houve sucesso ou não
*/
EXT_LOG int remove_comentario_usuario(char* ID_User,char* ID_Post,char* ID_Coment);

/**
*   @brief calcula a média da avaliação de uma certa postagem
*   @param nota: nova nota atribuída àquela postagem
*   @param ID_Post:identificador da postagem
*   @return retorna se houve secesso ou não
*/
EXT_LOG int atribui_avaliacao_postagem(int nota, char* ID_Post);

#endif /* LOGICA_H */
