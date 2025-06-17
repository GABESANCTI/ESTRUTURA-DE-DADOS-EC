#define MAX_URL 2083
#define MAX_NODES 10
// MODELANDO A ESTRUTURA
typedef struct NODE {
    char url[MAX_URL];
    char data_acesso[12];
    char hora_acesso[20];
    struct NODE *prox;
} NODE;
//prototipos de funções
NODE* Cria_Node();
void Insert_Node(NODE** head); 
void Retorna_Lista(NODE* head);
int Contador(NODE* head);