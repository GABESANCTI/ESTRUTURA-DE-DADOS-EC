#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct {
    float *items;
    int top;
    int maxSize;
} Pilha;

Pilha *cria_pilha(int tamanho);
void destroi_pilha(Pilha *p);
void empilha(float c, Pilha *p);
void menu();
float desempilha(Pilha *p);
float topo(Pilha *p);
int vaziap(Pilha *p);
int prio(char c);
char *posfixa(char *e);
float avalia_posfixa(char *posfixa, Pilha *pilhaVariaveis);
float obtem_valor_variavel(char variavel, Pilha *pilhaVariaveis);