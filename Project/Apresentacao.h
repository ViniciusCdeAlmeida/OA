

#ifndef APRESENTACAO_H
#define APRESENTACAO_H
#define _CRT_SECURE_NO_WARNINGS 10
/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Padroes.h"

/* Protótipos das funções */
/* Parametros e retornos ainda não são definitivos */
/**
* @brief Listará de uma vez os identificadores de todos os usuários.
*/
void lista_resgistro();

void menu_inicial();
/**
* @brief Função que invoca opção do usuário.
*/
void opcao_usuario();

void lista_resgistro();

void deleta_registro();

void altera_registro();

void cadastro_registro();


#endif 
