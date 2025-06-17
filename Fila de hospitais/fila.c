#include"fila.h"

// Função para iniciar a estrutura
Fila* cria_fila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->quantidade = 0;
    return f;
}

// Função para cadastrar um paciente na fila *** estrutura como parâmetro
void cadastra_paciente(Fila *fila, Paciente paciente) {
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    *novo = paciente;  // Copia os dados do paciente para o novo node
    novo->prox = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    fila->quantidade++;
}


Paciente* retira_paciente(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("A fila está vazia.\n");
        return NULL;
    }
    Paciente *removido = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    fila->quantidade--;

    printf("Paciente %s, sob responsabilidade do médico %s, encaminhado para cirurgia de %s, em modo %s.\n",
           removido->nome, removido->medico, removido->especialidade, removido->tipoCirurgia);

    return removido;
}


void destroi_fila(Fila *fila) {
    while (fila->inicio != NULL) {
        Paciente *removido = retira_paciente(fila);
        free(removido);
    }
    printf("Fila destruída.\n");
}

int quantidade_pacientes(Fila *fila) {
    return fila->quantidade;
}
//menu e função principal de inicio 
void menu() {
    Fila *filaEletiva = cria_fila();
    Fila *filaEmergencia = cria_fila();
    int opcao, tipo;
    Paciente paciente;

    do { printf("\n\n_______________________________________________");
        printf("\n Filas de Cirurgias\n");
        printf("1. Cadastrar paciente\n");
        printf("2. Retirar paciente da fila de emergência\n");
        printf("3. Retirar paciente da fila eletiva\n");
        printf("4. Mostrar quantidade de pacientes em cada fila\n");
        printf("5. Destruir filas\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        printf("\n_______________________________________________\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o CPF do paciente: ");
                scanf("%s", paciente.cpf);
                printf("Digite o nome do paciente: ");
                scanf("%s", paciente.nome);
                printf("Digite a especialidade da cirurgia: ");
                scanf("%s", paciente.especialidade);
                printf("Digite o nome do médico: ");
                scanf("%s", paciente.medico);

                // Solicitar tipo de cirurgia (1 para eletiva, 2 para emergência)
                printf("Selecione o tipo de cirurgia: (1) Eletiva (2) Emergência: ");
                scanf("%d", &tipo);

                if (tipo == 1) {
                    strcpy(paciente.tipoCirurgia, "eletiva");
                    cadastra_paciente(filaEletiva, paciente);
                } else if (tipo == 2) {
                    strcpy(paciente.tipoCirurgia, "emergência");
                    cadastra_paciente(filaEmergencia, paciente);
                } else {
                    printf("Tipo de cirurgia inválido!\n");
                }
                break;
            case 2:
                retira_paciente(filaEmergencia);
                break;
            case 3:
                retira_paciente(filaEletiva);
                break;
            case 4:
                printf("Quantidade de pacientes na fila eletiva: %d\n", quantidade_pacientes(filaEletiva));
                printf("Quantidade de pacientes na fila de emergência: %d\n", quantidade_pacientes(filaEmergencia));
                break;
            case 5:
                destroi_fila(filaEletiva);
                destroi_fila(filaEmergencia);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 6);

    free(filaEletiva);
    free(filaEmergencia);
}