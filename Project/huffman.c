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
    int parente;
} hufftree;

int achar_baixo(hufftree vet[]){
    int i;
    flag = 0;
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

void faz_Htree(int s1, int s2, hufftree vet[]){
    int node = nodesused++;
    
    array[node].freq = array[s1].freq + array[s2].freq;
    array[node].left = s1;
    array[node].right = s2;
    array[s1].parent = node;
    array[s2].parent = node;

    array[s1].freq = 0;
    array[s2].freq = 0;
}

void write_bits(FILE *output, int bit, int flush){
    static int count_bits = 0;
    static char buff = 0;
 
    if(flush && count_bits > 0){
        fwrite(&buff, 1, sizeof(buff), output);
        buff = 0;
        count_bits = 0;
        return;
    }

    if(bit)
        buff |= 1 << count_bits;
 
    if(++count_bits >= 8){
        fwrite(&buff, 1, sizeof(buff), output);
        buff = 0;
        count_bits = 0;
    }
}

void encode(char *inp, FILE *output, htree array[]){
    unsigned i, bufp = 0;
    char buff[512], symbol[1];
    FILE *input = fopen(inp, "rb");
 
    memset(buff, 0, sizeof(buff));
    memset(symbol, 0, sizeof(symbol));
 
    while(fread(symbol, 1, 1, input)){
        i = symbol[0];
        memset(buff, 0, sizeof(buff));
 
        if(array[array[i].parent].left == i)
            buff[bufp++] = 0;
        else if(array[array[i].parent].right == i)
            buff[bufp++] = 1;
 
        while(array[i].parent >= 0){
            i = array[i].parent;
            if(array[array[i].parent].left == i)
                buff[bufp++] = 0;
            else if(array[array[i].parent].right == i)
                buff[bufp++] = 1;
        }
       
        while(bufp){
            write_bits(output, buff[--bufp], 0);
        }
    }
    write_bits(output, 0, 1);
}

int getBit(FILE *fi){
    static int count_bits = 0;
    static unsigned char bits = 0;
       
    if(count_bits < 1){
        fread (&bits, 1, 1, fi);
        count_bits = 8;
    }
    count_bits--;
       
    if ((bits >> (7-count_bits)) & 1)
        return 1;
    else
        return 0;
}

void decode(char *inp, char *out, htree tfd[]){
    int i = 0, root, bit;
    FILE * input = fopen(inp, "rb");
    FILE * output = fopen(out, "wb");
    nodesused = 256;

    while(i < 256){
        fread(&tfd[i].freq, 1, sizeof(tfd[i].freq), input);
        i++;
    }

    while(findLow(tfd) >= 0)
        buildTree(lowsym.low1, lowsym.low2, tfd);

    root = lowsym.low1;

    i = root;
    while(!feof(input)){
        bit = getBit(input);
        if(i < 256){
            fwrite(&i, 1, 1, output);
            i = root;
        }
        if(bit)
            i = tfd[i].right;
        else
            i = tfd[i].left;
    }
    fclose(input);
    fclose(output);
}

int main(int argc, char **argv){
    int i = 0;
    char symbol[1];
    FILE * input;
    FILE * output;

    htree array[NODES], tfd[NODES];

    memset(array, 0, sizeof(array));
    memset(symbol, 0, sizeof(symbol));

	if(argc != 4){
		printf("Argumentos errados.\n");
		exit(1);
	}

    if(*argv[1] == 'e'){
        input = fopen(argv[2], "rb");
        output = fopen(argv[3], "wb");

        if(!input || !output){
            printf("Error: can\'t open the file. The program will exit now.\n");
            exit(1);
        }
        while(fread(symbol, 1, 1, input))
            array[(int)symbol[0]].freq++;
        fclose(input);
    
        while(i < 256){
            fwrite(&array[i].freq, 1, sizeof(array[i].freq), output);
            i++;
        }
    
        while(findLow(array) >= 0){
            buildTree(lowsym.low1, lowsym.low2, array);
        }
    
        array[lowsym.low1].parent = -1;
        encode(argv[2], output, array);
        fclose(output);
    }else if(*argv[1] == 'd'){
        decode(argv[2], argv[3], tfd);
    }else{
        printf("Wrong arguments. The program will exit now.\n");
        exit(1);
    }
    printf("Acho que foi.\n");
    getchar();
    return 0;
}
