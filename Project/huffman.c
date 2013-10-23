#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOS 1000

//511

int nos_usados = 256;

struct parte_baixa{
    short parte_baixa_1;
    short parte_baixa_2;
} baixo_simb;

typedef struct{
    unsigned freq;
    int esquerda;
    int direita;
    int pai;
} hufftree;

int achar_baixo(hufftree vet[]){
    int i=0;
    int flag = 0;
    baixo_simb.parte_baixa_1 = -1;
    baixo_simb.parte_baixa_2 = -1;

    for(i = 0; i < NOS; i++) 
        if(vet[i].freq){
            flag++;
            if(baixo_simb.parte_baixa_1 < 0 || vet[i].freq < vet[baixo_simb.parte_baixa_1].freq)
                baixo_simb.parte_baixa_1 = i;
        }

    if(flag > 1)
        for(i = 0; i < NOS; i++)
            if(vet[i].freq && i != baixo_simb.parte_baixa_1)
                if(baixo_simb.parte_baixa_2 < 0 || vet[i].freq < vet[baixo_simb.parte_baixa_2].freq)
                    baixo_simb.parte_baixa_2 = i;
        
    return baixo_simb.parte_baixa_2;
}

void faz_Htree(int esq, int dir, hufftree vet[]){
    int no = nos_usados++;
    
    vet[no].freq = vet[esq].freq + vet[dir].freq;
    vet[no].esquerda = esq;
    vet[no].direita = dir;
    vet[esq].pai = no;
    vet[dir].pai = no;

    vet[esq].freq = 0;
    vet[dir].freq = 0;
}

void escreve(FILE *arquivo_saida, int bit, int flush){
    static int conta_bits = 0;
    static char buff = 0;
 
    if(flush && conta_bits > 0){
        fwrite(&buff, 1, sizeof(buff), arquivo_saida);
        buff = 0;
        conta_bits = 0;
        return;
    }

    if(bit)
        buff |= 1 << conta_bits;
 
    if(++conta_bits >= 8){
        fwrite(&buff, 1, sizeof(buff), arquivo_saida);
        buff = 0;
        conta_bits = 0;
    }
}

void codifica(char *entrada, FILE *arquivo_saida, hufftree vet[]){
    unsigned i, buff_p = 0;
    char buff[512], simb[1];
    FILE *arquivo_entrada = fopen(entrada, "rb");
 
    memset(buff, 0, sizeof(buff));
    memset(simb, 0, sizeof(simb));
 
    while(fread(simb, 1, 1, arquivo_entrada)){
        i = simb[0];
        memset(buff, 0, sizeof(buff));
 
        if(vet[vet[i].pai].esquerda == i)
            buff[buff_p++] = 0;
        else if(vet[vet[i].pai].direita == i)
            buff[buff_p++] = 1;
 
        while(vet[i].pai >= 0){
            i = vet[i].pai;
            if(vet[vet[i].pai].esquerda == i)
                buff[buff_p++] = 0;
            else if(vet[vet[i].pai].direita == i)
                buff[buff_p++] = 1;
        }
       
        while(buff_p){
            escreve(arquivo_saida, buff[--buff_p], 0);
        }
    }
    escreve(arquivo_saida, 0, 1);
}

int pega_bit(FILE *arquivo_entrada){
    static int conta_bits = 0;
    static unsigned char bits = 0;
       
    if(conta_bits < 1){
        fread (&bits, 1, 1, arquivo_entrada);
        conta_bits = 8;
    }
    conta_bits--;
       
    if ((bits >> (7-conta_bits)) & 1)
        return 1;
    else
        return 0;
}

void decodifica(char *entrada, char *saida, hufftree tfd[]){
    int i = 0, raiz, bit;
    FILE * arquivo_entrada = fopen(entrada, "rb");
    FILE * arquivo_saida = fopen(saida, "wb");
    nos_usados = 256;

    while(i < 256){
        fread(&tfd[i].freq, 1, sizeof(tfd[i].freq), arquivo_saida);
        i++;
    }

    while(achar_baixo(tfd) >= 0)
        faz_Htree(baixo_simb.parte_baixa_1, baixo_simb.parte_baixa_2, tfd);

    raiz = baixo_simb.parte_baixa_1;

    i = raiz;

    while(!feof(arquivo_entrada)){
        bit = pega_bit(arquivo_entrada);
        if(i < 256){
            fwrite(&i, 1, 1, arquivo_saida);
            i = raiz;
        }
        if(bit)
            i = tfd[i].direita;
        else
            i = tfd[i].esquerda;
    }
    fclose(arquivo_entrada);
    fclose(arquivo_saida);
}

int main(int argc, char **argv){
    int i = 0;
    char simb[1];
    FILE * entrada;
    FILE * saida;

    hufftree vet[NOS], tfd[NOS];

    memset(vet, 0, sizeof(vet));
    memset(simb, 0, sizeof(simb));

	if(argc != 4){
		printf("Argumentos errados.\n");
		exit(1);
	}

    if(*argv[1] == 'e'){
        entrada = fopen(argv[2], "rb");
        saida = fopen(argv[3], "wb");

        if(!entrada || !saida){
            printf("Error: can\'t open the file. The program will exit now.\n");
            exit(1);
        }
        while(fread(simb, 1, 1, entrada))
            vet[(int)simb[0]].freq++;
        fclose(entrada);
    
        while(i < 256){
            fwrite(&vet[i].freq, 1, sizeof(vet[i].freq), saida);
            i++;
        }
    
        while(achar_baixo(vet) >= 0){
            faz_Htree(baixo_simb.parte_baixa_1, baixo_simb.parte_baixa_2, vet);
        }
    
        vet[baixo_simb.parte_baixa_1].pai = -1;
        codifica(argv[2], saida, vet);
        fclose(saida);
    }else if(*argv[1] == 'd'){
        decodifica(argv[2], argv[3], tfd);
    }else{
        printf("Wrong arguments. The program will exit now.\n");
        exit(1);
    }
    printf("Acho que foi.\n");
    getchar();
    return 0;
}
