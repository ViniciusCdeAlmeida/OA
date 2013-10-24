
#define PERSISTENCIA_U_SERV

/* Includes */

#include "Persistencia.h"
#include "Logica.h"

int inicializa_persistencia_u() {
    /* Declara��o de Vari�veis */
    FILE *arqUsuario;
    /* Verifica se existe o arquivo */
    arqUsuario = fopen(DB_USUARIO, "r");
    if(arqUsuario == NULL) {
        /* Caso n�o exista, abre o arquivo e inicia o primeiro espa�o livre como final da LED */
        arqUsuario = fopen(DB_USUARIO, "w");
        fprintf(arqUsuario, "%d\n", FIM_LISTA);
    }
    /* Fecha o arquivo (existindo anteriormente ou n�o) */
    fclose(arqUsuario);
    return SUC_FUNCAO;
}

int atualiza_registro(int nrr, Registro *registro) {
    /* Declara��o de Vari�veis */
    FILE *arqUsuario;
    /* Abertura de arquivos */
    arqUsuario = fopen(DB_USUARIO, "r+");
    /* Faz o posicionamento no local desejado (nrr) */
    fseek(arqUsuario, TAM_REGUSUARIO * nrr + 4, SEEK_SET);
    /* Sobrescreve */

    /* Fechamento do arquivo */
    fclose(arqUsuario);
    return SUC_FUNCAO;
}

int remove_usuario(char *identificador) {
    /* Declara��o de Vari�veis */
    FILE *arqUsuario;
    Usuario *usuario;
    int byteOffset, proximo;
    /* Procura pelo usu�rio correspondente */
    byteOffset = recupera_usuario(identificador, usuario);
    /* Indica a posi��o do registro removido como primeiro espa�o livre */
    arqUsuario = fopen(DB_USUARIO, "r+");
    fscanf(arqUsuario, "%d", &proximo); /* Armazena o primeiro espa�o livre anterior */
    fseek(arqUsuario, 0, SEEK_SET);
    fprintf(arqUsuario, "%.5d", byteOffset);
    /* Comp�e a Lista Invertida */
    fseek(arqUsuario, byteOffset, SEEK_SET);
    fprintf(arqUsuario, "%.5d", proximo);
    /* Fechamento dos arquivos */
    free(usuario);
    fclose(arqUsuario);
    return SUC_FUNCAO;
}

int recupera_usuario(char *identificador, Usuario *usuario) {
    /* Declara��o de Vari�veis */
    FILE *arqUsuario;
    int ativo, linha = 0, proximo;
    /* Abertura dos arquivos */
    arqUsuario = fopen(DB_USUARIO, "r");
    fscanf(arqUsuario, "%d", &proximo);
    /* Procura usu�rio correspondente */
    while(!feof(arqUsuario)) {
        fscanf(arqUsuario, "%d%s", &ativo, usuario->identificador);
        fgets(usuario->nome, TAM_NOME, arqUsuario);
        fscanf(arqUsuario, "%s%d%d", usuario->senha, &usuario->primPostagem, &usuario->primComentario);
        if(ativo == REG_ENABLE) /* S� compara registros habilitados */
            if(!strcmp(usuario->identificador, identificador)) {
                fclose(arqUsuario);
                return CTE_CABECALHO + linha * TAM_REGUSUARIO;
            }
        linha++;
    }
    /* Fechamento dos arquivos */
    fclose(arqUsuario);
    return SUC_FUNCAO;
}

int recupera_usuario_nrr(int nrr, Usuario *usuario) {
    FILE *arqUsuario;
    int ativo, proximo;
    /* Abertura dos arquivos */
    arqUsuario = fopen(DB_USUARIO, "r");
    fscanf(arqUsuario, "%d", &proximo);
    /* Faz o posicionamento no local desejado (nrr) */
    fseek(arqUsuario, TAM_REGUSUARIO * nrr + 5, SEEK_SET);
    /* Recupera o usu�rio, se existir */
    fscanf(arqUsuario, "%d", &ativo);
    if(!feof(arqUsuario)) {
        if(ativo == REG_ENABLE) {
            fscanf(arqUsuario, "%s", usuario->identificador);
            fgets(usuario->nome, TAM_NOME, arqUsuario);
            fscanf(arqUsuario, "%s%d%d", usuario->senha, &usuario->primPostagem, &usuario->primComentario);
            fclose(arqUsuario);
            return SUC_FUNCAO;
        }
    }
    /* Sen�o, retorna INX_REGISTRO */
    fclose(arqUsuario);
//    return INX_REGISTRO;
}
