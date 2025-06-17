/******************************************************************************
Aluno: Erick Gabriel Santiago de Araujo

*******************************************************************************/
#include <stddef.h>
#include "lista.h"
int main() {
    NODE* head = NULL;
    while (Contador(head) < MAX_NODES) {
        Insert_Node(&head);
    }
    Retorna_Lista(head);
    return 0;
}
