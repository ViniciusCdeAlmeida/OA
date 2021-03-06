
#ifndef PERSISTENCIA_U_H
#define PERSISTENCIA_U_H
#ifdef PERSISTENCIA_U_SERV
#define EXT_PU
#else
#define EXT_PU extern
#endif

/* Includes */

#include "Padroes.h"
#include "Logica.h"

/* Prot�tipos das fun��es */

/**
*   @brief Inicializa��o da persist�ncia
*   @param
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int inicializa_persistencia_u(void);

/**
*   @brief Armazena um usu�rio em arquivo
*   @param usuario: informa��es a serem armazenadas, deve vir preenchido
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int atualiza_usuario(int nrr, Usuario *usuario);

/**
*   @brief Remove um usu�rio do arquivo
*   @param identificador: identificador do registro a ser removido
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int remove_usuario(char *identificador);

/**
*   @brief Procura sequencialmente pelo usu�rio pelo seu identificador e preenche um objeto com suas informa��es
*   @param identificador: chave prim�ria do usu�rio, usuario: conter� as informa��es atuais do registro, deve vir alocado
*   @return Retorna o nrr do registro
*/
EXT_PU int recupera_usuario(char *identificador, Usuario *usuario);

/**
*   @brief Procura sequencialmente pelo usu�rio pelo seu nrr e preenche um objeto com suas informa��es
*   @param nrr: posi��o do registro no arquivo, usuario: conter� as informa��es atuais do registro, deve vir alocado
*   @return Retorna o pr�ximo nrr ou fim de lista
*/
EXT_PU int recupera_usuario_nrr(int nrr, Usuario *usuario);
#endif /* PERSISTENCIA_U_H */
