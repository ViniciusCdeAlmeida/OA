
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NO 511


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

#endif
