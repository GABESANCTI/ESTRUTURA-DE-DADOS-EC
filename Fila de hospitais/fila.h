#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Paciente {
    char cpf[12];
    char nome[100];
    char especialidade[50];
    char medico[100];
    char tipoCirurgia[20]; // "eletiva" ou "emergência"
    struct Paciente *prox;
} Paciente;

// Definição da Fila
typedef struct Fila {
    Paciente *inicio;
    Paciente *fim;
    int quantidade
} Fila;
Fila* cria_fila();
void cadastra_paciente(Fila *fila, Paciente paciente);
Paciente* retira_paciente(Fila *fila);
void destroi_fila(Fila *fila);
int quantidade_pacientes(Fila *fila);
void menu();