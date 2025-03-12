/******************************************************************************
Aluno: Erick Gabriel Santiago de Araujo
Matricula: 2021178440241
*******************************************************************************/
//struct base 
typedef struct
{
  int vehicleCode;
  char brand[15];
  char name[20];
  char licensePlate[8];
  float price;
} Car;
//inserecarro
void inserecarro (Car ** cars, int numCars);
//buscacod
void buscacod (Car * cars, int numCars, int vehicleCode);
//buscaplaca
void buscaplaca (Car * cars, int numCars, const char licensePlate[]);
//ordenamarca
void ordenamarca (Car * cars, int numCars);
//precdec
void precdec (Car * cars, int numCars);
