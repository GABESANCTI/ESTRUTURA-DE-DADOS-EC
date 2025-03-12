
#include <stdio.h>
#include <stdlib.h>
#include "carros.h"
void
menu ()
{
  printf ("\n\n=== SISTEMA CONCESSIONÁRIA VRUMVRUM LTDA=====\n");
  printf ("1. Cadastro novo carro\n");
  printf ("2. Buscar por codigo de matricula\n");
  printf ("3. Procurar pela placa\n");
  printf ("4. Relatório de marca(Ordem Alfabetica)\n");
  printf ("5. Relatório por preço (Ordem decrescente)\n");
  printf ("6. Sair\n");
  printf ("=============================================\n");
  printf ("Digite a opção desejada: ");
}
int
main ()
{
  int choice;
  int numCars = 0;
  Car *inventory;
  do
	{
	  menu ();
	  scanf ("%d", &choice);
	  switch (choice)
		{
		case 1:
		  printf ("\nDigite a quantidade que deseja cadastrar:\n ");
		  scanf ("%d", &numCars);
		  inserecarro (&inventory, numCars);
		  break;
		case 2:
		  if (numCars == 0)
			{
			  printf ("Inventario vazio.\n");
			  break;
			}
		  int vehicleCode;
		  printf ("Digite o código de matricula do veiculo: ");
		  scanf ("%d", &vehicleCode);
		  buscacod (inventory, numCars, vehicleCode);
		  break;
		case 3:
		  if (numCars == 0)
			{
			  printf ("Inventario vazio.\n");
			  break;
			}
		  char licensePlate[9];
		  printf ("Digite a placa do carro: ");
		  scanf ("%s", licensePlate);
		  buscaplaca (inventory, numCars, licensePlate);
		  break;
		case 4:
		  if (numCars == 0)
			{
			  printf ("Inventario vazio.\n");
			  break;
			}
		  ordenamarca (inventory, numCars);
		  break;
		case 5:
		  if (numCars == 0)
			{
			  printf ("Inventario vazio.\n");
			  break;
			}
		  precdec (inventory, numCars);
		  break;
		case 6:
		  printf ("Fechando o programa...\n");
		  //dando free na memoria alocada 
		   if (inventory != NULL)
			{
			  free (inventory);
			}
		  break;
		default:
		  printf ("Opção invalida. Tente novamente.\n");
		  break;
		}
	}
  while (choice != 6);

  return 0;
}
