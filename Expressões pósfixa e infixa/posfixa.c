    #include "posfixa.h"
    //Quick notes: 
    // Operador: +-*/^ e tals
    // Operandos: 0-9 ABCD
    //criar pilha
    Pilha *cria_pilha(int tamanho) 
    {
        Pilha *p = (Pilha *)malloc(sizeof(Pilha));
        p->items = (float *)malloc(tamanho * sizeof(float));
        p->top = -1;
        p->maxSize = tamanho;
        return p;
    }
   
    void destroi_pilha(Pilha *p) 
    {
        free(p->items);
        free(p);
    }
   
    void empilha(float c, Pilha *p) 
    {
        if (p->top == p->maxSize - 1) 
        {
            fprintf(stderr, "Erro: pilha cheia :( \n");
            exit(EXIT_FAILURE);
        }
        p->items[++(p->top)] = c;
    }
  
    float desempilha(Pilha *p) 
    {
        if (vaziap(p)) 
        {
            fprintf(stderr, "Erro: pilha vazia\n");
            exit(EXIT_FAILURE);
        }
        return p->items[(p->top)--];
    }
    //obter o elemento do topo da pilha
    float topo(Pilha *p) 
    {
        if (vaziap(p)) 
        {
            fprintf(stderr, "Erro: pilha vazia\n");
            exit(EXIT_FAILURE);
        }
        return p->items[p->top];
    }

    int vaziap(Pilha *p) 
    {
        return p->top == -1;
    }
    //definindo prioridade de um operador
    int prio(char c) 
    {
        if (c == '^')
            return 3;  // Prioridade mais alta para ^
        else 
        if (c == '+' || c == '-')
            return 1;
        else if (c == '*' || c == '/')
            return 2;
        else
            return 0;  //menor prioridade
    }
    //converter expressão infixa para posfixa
    char *posfixa(char *e) 
    {
        static char s[256];
        int j = 0;
        Pilha *P = cria_pilha(256);
        for (int i = 0; e[i]; i++) 
        {
            if (e[i] == '(')
                empilha('(', P);
            else if (isalpha(e[i]) || isdigit(e[i])) // Considera algarismos alfabéticos 
                s[j++] = e[i]; //como variáveis assim podemos inserir o  valor depois
            else if (strchr("+-/*", e[i])) {
                while (!vaziap(P) && prio(topo(P)) >= prio(e[i]))
                    s[j++] = desempilha(P);
                empilha(e[i], P);
            }
            else if (e[i] == ')') {
                while (topo(P) != '(')
                    s[j++] = desempilha(P);
                desempilha(P);
            }else if (e[i] == '^') 
            {
                while (!vaziap(P) && prio(topo(P)) > prio(e[i]))
                    s[j++] = desempilha(P);
                empilha(e[i], P);
            }
             else if (isalpha(e[i])) 
            {
                s[j++] = e[i];
                // Verifica se existe um operador (+-/*)antes do operando (ABC)
                if (i > 0 && strchr("+-/*", e[i - 1])) 
                {
                    printf("Erro: Falta operador entre operandos.\n");
                    return NULL;
                }
            }
        }
        while (!vaziap(P))
        s[j++] = desempilha(P);
        s[j] = '\0';
        destroi_pilha(P);
        return s;
    }
    
        float avalia_posfixa(char *posfixa, Pilha *pilhaVariaveis) 
        {
            Pilha *P = cria_pilha(256);
            for (int i = 0; posfixa[i]; i++) 
            {
                if (isdigit(posfixa[i])) 
                {
                    empilha(posfixa[i] - '0', P);
                } else if (isalpha(posfixa[i])) 
                {
                   
                    empilha(obtem_valor_variavel(posfixa[i], pilhaVariaveis), P);
                } else 
                {
                    float operand2 = desempilha(P);
                    float operand1 = desempilha(P);
                    switch (posfixa[i]) 
                    {
                        case '+':
                            empilha(operand1 + operand2, P);
                            break;
                        case '-':
                            empilha(operand1 - operand2, P);
                            break;
                        case '*':
                            empilha(operand1 * operand2, P);
                            break;
                        case '/':
                            empilha(operand1 / operand2, P);
                            break;
                        case '^':
                            empilha(pow(operand1, operand2), P);  // Usando a função pow p exponencial source math.h
                            break;
                    }
                }
            }
            float result = desempilha(P);
            destroi_pilha(P);
            return result;
        }
    
    float obtem_valor_variavel(char variavel, Pilha *pilhaVariaveis) 
    {
        
        for (int i = 0; i <= pilhaVariaveis->top; i++) 
        {
            if (pilhaVariaveis->items[i] == variavel) 
            {
               
                return pilhaVariaveis->items[i + 1];
            }
        }
    
       
        printf("Digite o valor para a variavel %c: ", variavel);
        float valor;
        scanf("%f", &valor);
    
        // vai armazenar a variável e seu valor na pilha
        empilha(variavel, pilhaVariaveis);
        empilha(valor, pilhaVariaveis);
    
        return valor;
    }
    void menu() 
    {
        int choice;
        char infix[256];
        char *postfix;
        Pilha *pilhaVariaveis = cria_pilha(256);
    
        do
        {
            printf("___________________________________\n");
            printf("             Menu\n");
            printf("1. Inserir Expressao Infixa\n");
            printf("2. Inserir Valor a Variavel\n");
            printf("3. Exibir Resultado da Expressao\n");
            printf("4. Sair\n");
            printf("Digite a opcao: ");
            printf("\n___________________________________\n");
            scanf("%d", &choice);
    
            switch (choice) 
            {
                case 1:
                    printf("Digite a expressao infix (com variaveis, operadores e parênteses): ");
                    scanf("%255s", infix);
    
                    // check de parentesis
                    int openParentheses = 0, closeParentheses = 0;
                    for (int i = 0; infix[i] != '\0'; i++) 
                    {
                        if (infix[i] == '(') {
                            openParentheses++;
                        } else if (infix[i] == ')') {
                            closeParentheses++;
                        }
                    }
    
                    if (openParentheses != closeParentheses) 
                    {
                        printf("Erro: Expressao nao esta parentesiada corretamente.\n");
                        break;  // flag de erro de parentesis
                    }
                    postfix = posfixa(infix);
                    printf("Expressao Infixa: %s\n", infix);
                    printf("Expressao Posfixa: %s\n", postfix);
                    break;
                case 2:
                    // Agregar valor a variaveis
                    if (postfix == NULL) {printf("Erro: Expressao ainda nao cadastrada.\n");
                    } else {
                        for (int i = 0; postfix[i]; i++) {
                            if (isalpha(postfix[i])) {
                                // confere se a variavel ja possui valor numerico
                                int variableValue = obtem_valor_variavel(postfix[i], pilhaVariaveis);
                                if (variableValue == -1) {
                                    // caso n possua, solicita ao usuario que preencha
                                    variableValue = obtem_valor_variavel(postfix[i], pilhaVariaveis);
                                }
                            }
                        }
                        printf("Valores das variaveis adicionados.\n");
                    }
                    break;
                case 3:
                   
                    if (postfix == NULL) {
                        printf("Erro: Expressao ainda nao cadastrada.\n");
                    } else {
                       
                        float result = avalia_posfixa(postfix, pilhaVariaveis);
                        printf("Resultado da expressao: %.2f\n", result);
                    }
                    break;
                case 4:
                   
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
            }
    
        } while (choice != 4);
        destroi_pilha(pilhaVariaveis);
    }