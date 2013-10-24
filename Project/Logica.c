
#define LOGICA_SERV

/* Includes */

#include "Logica.h"
#include "Persistencia.h"

//Funções de Manipulação de lista
Listagens* cria_lista(){
    return NULL;
}

Listagens* insere_lista(Listagens* lista, char* info){
    Listagens* novo=(Listagens*)malloc(sizeof(Listagens));
    novo->informacao=info;
    novo->proximo=lista;
    return novo;
}

void deleta_lista(Listagens* lista){
    Listagens* p=lista;
    while(p!=NULL){
        Listagens* t=p->proximo;
        free(p);
        p=t;
    }
}

//Funções de procura
Usuario* procura_usuario(char* ID){
    int temp;
    Usuario* user;
    temp=recupera_usuario(ID,user);
    if(temp==INX_USUARIO) return NULL;
    return user;
}

int elimina_usuario(char* ID){

}

int atualiza(char* novoUser, char* novaSenha, char* ID){
    Usuario *user=(Usuario*)malloc(sizeof(Usuario));
    user=procura_usuario(ID);
    if(user==NULL) return FRACASSO_LN;
    else preenche_usuario(novoUser,ID,novaSenha);//como enviar o byteoffset??
}
