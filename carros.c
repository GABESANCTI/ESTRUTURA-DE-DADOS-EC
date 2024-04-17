/******************************************************************************
Aluno: Erick Gabriel Santiago de Araujo
Matricula: 2021178440241
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carros.h"
//menu 
//inserecarro: cria um novo carro 
void inserecarro(Car **cars, int numCars) {
    *cars = (Car *)malloc(numCars * sizeof(Car));
    if (*cars == NULL) {
        printf("ERRO DE ALOCAÇÃO DA MEMORIA!\n");
        return;
    }
    int vehicleCode = 100; // codigo inicial
    printf("\nPREENCHA OS DADOS SOLICITADOS:\n");
    for (int i = 0; i < numCars; i++) {
        printf("\nCarro %d:\n", i + 1);
        // iteração do contador
        (*cars)[i].vehicleCode = vehicleCode++;
        // marca do carro
        printf("Insira a marca do carro (Até 15 caracteres): ");
        scanf("%s", (*cars)[i].brand);
        if (strlen((*cars)[i].brand) > 15) {
            printf("Texto muito longo! Por favor, tente novamente.\n");
            i--;
            continue;
        }
        // Nome do veiculo
        printf("Insira o modelo, ou nome,  do carro (Até 15 caracteres): ");
        scanf("%s", (*cars)[i].name);
        if (strlen((*cars)[i].name) > 15) {
            printf("Texto muito longo! Por favor, tente novamente.\n");
            i--;
            continue;
        }
        // Placa  LP
        printf("Insira a placa do carro (Até 8 caracteres): ");
        scanf("%s", (*cars)[i].licensePlate);
        if (strlen((*cars)[i].licensePlate) > 8) {
            printf("Texto muito longo! Por favor, tente novamente.\n");
            i--;
            continue;
        }
        // Preço do veiculo 
        printf("Insira o preço do veiculo em BRL: ");
        scanf("%f", &((*cars)[i].price));
    }
}
//buscacod: realiza a busca do carro pelo codigo 
void buscacod(Car *cars, int numCars, int vehicleCode) {
    int found = 0; // verifica se o carro foi encontrado
    // Busca binaria
    int low = 0, high = numCars - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (cars[mid].vehicleCode == vehicleCode) {
            found = 1;
            break;
        } else if (cars[mid].vehicleCode < vehicleCode) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // Display do resultado 
    if (found) {
        printf("\nCARRO ENCONTRADO!\n");
        printf("Matricula: %d\n", cars[mid].vehicleCode);
        printf("Marca: %s\n", cars[mid].brand);
        printf("Modelo: %s\n", cars[mid].name);
        printf("Placa: %s\n", cars[mid].licensePlate);
        printf("Preço: %.2f\n", cars[mid].price);
    } else {
        printf("\nINFORMAÇÃO NÃO LOCALIZADA!!\n"); //caso erro found==false
    }
}
//buscaplaca 
void buscaplaca(Car *cars, int numCars, const char licensePlate[]) {
    int found = 0;
    char *name = NULL;
    float price;
    // Busca linear **base strcmp no codeacademy  arrays n strings && farmacia data struct em sala
    for (int i = 0; i < numCars; i++) {
        if (strcmp(cars[i].licensePlate, licensePlate) == 0) {
            found = 1;
            name = cars[i].name;
            price = cars[i].price;
            break;
        }
    }
    // Display da busca linear
    if (found) {
        printf("CARRO ENCONTRADO!\n");
        printf("MODELO: %s\n", name);
        printf("PREÇO: %.2f\n", price);
    } else {
        printf("\n\nINFORMAÇÃO NÃO LOCALIZADA!\n\n"); // DNF
    }
}
//ordenar por marca
void ordenamarca(Car *cars, int numCars) {
    // Insertion sort 
    for (int i = 1; i < numCars; i++) {
        Car key = cars[i];
        int j = i - 1;
        //move os elementos que são maiores que key pra posição atual+1
        while (j >= 0 && strcmp(cars[j].brand, key.brand) > 0) {
            cars[j + 1] = cars[j];
            j = j - 1;
        }
        cars[j + 1] = key;
    }
    // Display ordenção por marca
    printf("ORDENAÇÃO POR MARCA(ORDEM ALFABETICA):\n");
    for (int i = 0; i < numCars; i++) {
        printf("\n\nMARCA: %s \nMATRICULA DO VEICULO: %d\n\n", cars[i].brand, cars[i].vehicleCode);
    }
}
//swap auxiliar
void swap(Car *a, Car *b) {
    Car temp = *a;
    *a = *b;
    *b = temp;
}
//partição aux do quickSort
int partition(Car *cars, int low, int high) {
    float pivot = cars[high].price;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (cars[j].price >= pivot) {
            i++;
            swap(&cars[i], &cars[j]);
        }
    }
    swap(&cars[i + 1], &cars[high]);
    return (i + 1);
}
//ordenação quick sort
void quickSort(Car *cars, int low, int high) {
    if (low < high) {
        int pi = partition(cars, low, high);
        quickSort(cars, low, pi - 1);
        quickSort(cars, pi + 1, high);
    }
}
//preço decrescente
void precdec(Car *cars, int numCars) {
    quickSort(cars, 0, numCars - 1);
    // Display dos carros em ordem decrescente
    printf("\nPREÇOS ORDENADOS EM ORDEM DECRESCENTE\n");
    for (int i = 0; i < numCars; i++) {
        printf("\n\nPREÇO: %.2f \nMARCA: %s\nCÓDIGO: %d\n\n", cars[i].price, cars[i].brand, cars[i].vehicleCode);
    }
}
