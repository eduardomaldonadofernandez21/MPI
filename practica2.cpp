#include "mpi.h"
#include <cmath>
#include <stdio.h>

/*
*
double tinicial = MPI_Wtime();
....
double tfinal = MPI_Wtime();
double tiempo = tfinal – tinicial;

• Modifica el programa anterior para que cada proceso realice una tarea
que consuma tiempo como, por ejemplo, multiplicar dos números en
coma flotante varios millones de veces
• Añade al mensaje que muestra cada proceso el tiempo que ha tardado en
ejecutar la operación
• Realiza varias pruebas cambiando el número total de procesos y
determina si, a partir de los datos obtenidos, puedes verificar el número
de procesos que es capaz de ejecutar el procesador de forma simultánea
*/

float randMatfloat() {
	return (float)rand() / (float)10;
}

void main(int argc, char* argv[])
{
	int rank, size, length;
	char name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv);
	MPI_Get_processor_name(name, &length);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	float f1 = 5023403.532;
	float f2 = 2323325.24;
	float res = 0;
	double tinicial = MPI_Wtime();
	for (int i = 0; i < 25000000; i++) {
		res *= f1 * f2 * f1 * f2 * f1 * f2;
	}
	double tfinal = MPI_Wtime();
	printf("Resultado: %f\n", res);
	printf("[Proceso %d]: El tiempo de ejecucion que ha tardado en calcular 25M de multiplicaciones es %f" , rank, tfinal - tinicial);
	MPI_Finalize();
	return;
}