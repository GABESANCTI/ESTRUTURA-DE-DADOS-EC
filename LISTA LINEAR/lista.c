#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

NODE* Cria_Node() {
    NODE* NodeNovo = (NODE*)malloc(sizeof(NODE));
    if (NodeNovo == NULL) {
        printf("Erro no Malloc!\n");
        exit(1);
    }
    
    // Coleta de dados
    printf("\nInsira a URL: ");
    scanf("%s", NodeNovo->url);

    printf("Insira a data de acesso(DD/MM/AAAA): ");
    scanf("%s", NodeNovo->data_acesso);

    printf("Insira a em que a URL foi acessada (HH:MM:SS): ");
    scanf("%s", NodeNovo->hora_acesso);
    printf("_________________________________________________");
    NodeNovo->prox = NULL;
    return NodeNovo;
}
//Função de insert, realiza inserção no fim da lista
void Insert_Node(NODE** head) {
    NODE* NodeNovo = Cria_Node();//recebe de cria_node
    if (*head == NULL) {
        *head = NodeNovo;
    } else {
        // temp ta servindo de aux na iteração até o ultimo nó(null)
        NODE* temp = *head;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = NodeNovo;
    }
    printf("\n\nURL cadastrada com sucesso :D.\n");
}

// exibindo a lista, bem direto 
void Retorna_Lista(NODE* head) {
    if (head == NULL) {
        printf("ESTRUTURA VAZIA :(\n");
        return;
    }
    NODE* temp = head;
    printf("A LISTA ENCHEU! \n\nEstes são os dados cadastrados:\n");
    while (temp != NULL) {
        printf("\nURL : %s\nDATA: %s\nHORA: %s\n\n", temp->url, temp->data_acesso, temp->hora_acesso);
        temp = temp->prox;
    }
}

// verificando a qtd de node
int Contador(NODE* head) {
    int count = 0;
    NODE* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->prox;
    }
    return count;
}