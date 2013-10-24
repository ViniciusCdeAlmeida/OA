#include "Huffman.h"

int no_usado = 256;

int achar_baixo(hufftree vet[]){
    int i, conta = 0;
    baixo_simb.parte_baixa_1 = -1;
    baixo_simb.parte_baixa_2 = -1;

    for(i = 0; i < NO; i++) 
        if(vet[i].freq){
            conta++;
            if(baixo_simb.parte_baixa_1 < 0 || vet[i].freq < vet[baixo_simb.parte_baixa_1].freq)
                baixo_simb.parte_baixa_1 = i;
        }

    if(conta > 1)
        for(i = 0; i < NO; i++){
            if(vet[i].freq && i != baixo_simb.parte_baixa_1){
                if(baixo_simb.parte_baixa_2 < 0 || vet[i].freq < vet[baixo_simb.parte_baixa_2].freq){
                    baixo_simb.parte_baixa_2 = i;
                }
            }
        }
    return baixo_simb.parte_baixa_2;
}

void faz_arvore(int s1, int s2, hufftree vet[]){
    int node = no_usado++;
    
    vet[node].freq = vet[s1].freq + vet[s2].freq;
    vet[node].esquerda = s1;
    vet[node].direita = s2;
    vet[s1].pai = node;
    vet[s2].pai = node;

    vet[s1].freq = 0;
    vet[s2].freq = 0;
}

void escreve_bits(FILE *saida, int bit, int flush){
    static int count_bits = 0;
    static char buff = 0;
 
    if(flush && count_bits > 0){
        fwrite(&buff, 1, sizeof(buff), saida);
        buff = 0;
        count_bits = 0;
        return;
    }

    if(bit)
        buff |= 1 << count_bits;
 
    if(++count_bits >= 8){
        fwrite(&buff, 1, sizeof(buff), saida);
        buff = 0;
        count_bits = 0;
    }
}

void codifica(char *arquivo_entrada, FILE *saida, hufftree vet[]){
    unsigned i, buff_p = 0;
    char buff[512], simb[1];
    FILE *entrada = fopen(arquivo_entrada, "rb");
 
    memset(buff, 0, sizeof(buff));
    memset(simb, 0, sizeof(simb));
 
    while(fread(simb, 1, 1, entrada)){
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
            escreve_bits(saida, buff[--buff_p], 0);
        }
    }
    escreve_bits(saida, 0, 1);
}

int Bit_a_Bit(FILE *arquivo_entrada){
    static int count_bits = 0;
    static unsigned char bits = 0;
       
    if(count_bits < 1){
        fread (&bits, 1, 1, arquivo_entrada);
        count_bits = 8;
    }
    count_bits--;
       
    if ((bits >> (7-count_bits)) & 1)
        return 1;
    else
        return 0;
}

void decofica(char *arquivo_entrada, char *arquivo_saida, hufftree tfd[]){
    int i = 0, raiz, bit;
    FILE * entrada = fopen(arquivo_entrada, "rb");
    FILE * saida = fopen(arquivo_saida, "wb");
    no_usado = 256;

    while(i < 256){
        fread(&tfd[i].freq, 1, sizeof(tfd[i].freq), entrada);
        i++;
    }

    while(achar_baixo(tfd) >= 0)
        faz_arvore(baixo_simb.parte_baixa_1, baixo_simb.parte_baixa_2, tfd);

    raiz = baixo_simb.parte_baixa_1;

    i = raiz;
    while(!feof(entrada)){
        bit = Bit_a_Bit(entrada);
        if(i < 256){
            fwrite(&i, 1, 1, saida);
            i = raiz;
        }
        if(bit)
            i = tfd[i].direita;
        else
            i = tfd[i].esquerda;
    }
    fclose(entrada);
    fclose(saida);
}

int main(int argc, char **argv){
    int i = 0;
    char simb[1];
    FILE * entrada;
    FILE * saida;

    hufftree vet[NO], tfd[NO];

    memset(vet, 0, sizeof(vet));
    memset(simb, 0, sizeof(simb));

        if(argc != 4){
                printf("");
                exit(1);
        }

    if(*argv[1] == 'c'){//(*argv[1] == 'c','o','m','p','r','i','m','e'){
        entrada = fopen(argv[2], "rb");
        saida = fopen(argv[3], "wb");

        if(!entrada || !saida){
            printf("Falha na abertura do arquivo.\n");
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
            faz_arvore(baixo_simb.parte_baixa_1, baixo_simb.parte_baixa_2, vet);
        }
    
        vet[baixo_simb.parte_baixa_1].pai = -1;
        codifica(argv[2], saida, vet);
        fclose(saida);
    }else if(*argv[1] == 'd'){//(*argv[1] == 'd','e','s','c','o','m','p'){
        decofica(argv[2], argv[3], tfd);
    }else{
        printf("Argumentos errados\n");
        exit(1);
    }
    printf("Acho que foi!\n");
    getchar();
    return 0;
}
