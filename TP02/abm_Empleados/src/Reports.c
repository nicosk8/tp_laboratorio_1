#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"
#include "Employees.h"
#include "utn.h"

// SECCIÓN DE INFORMES
int showReportsMenu()
{
	int option;
	printf("********** MENU REPORTES **********\n");
	printf("1- Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
	printf("2- Total y promedio de los salarios y cuantos empleados superan el salario promedio.\n");
	getOption(&option,MESSAGE_INSERT_OPTION,MESSAGE_ERROR_INSERT_OPTION, SHOW_ORDERED, SHOW_AVERAGE,RETRIES);
	return option;
}


void showEmployeesOrderedByLastNameAndSector(Employee listEmployees[], int size)
{
	int order;
	printf("********** Listado ordenado por apellido**********\n");
	getOption(&order,"Ingrese opción de ordenamiento: 0-Descendente 1-Ascendente",MESSAGE_ERROR_INSERT_OPTION, ORDER_DOWN, ORDER_UP, RETRIES);
	if(order){
		printf("Listado ordenado por apellido ascendente\n");
	}else
	{
		printf("Listado ordenado por apellido descendente\n");
	}
	sortEmployee(listEmployees,size,order);
	printEmployees(listEmployees,size);
}

void showAverageSalary(Employee listEmployees[], int size)
{
	float totalSalary,
		  averageSalary;
	int	  countEmployees,
		  employeesWithMaxSalary;
	// obtengo salario total y cantidad de empleados
	// calculo promedio y cuento la cantidad de empleados que superan el salario promedio
	totalSalary = getTotalSalary(listEmployees,size);
	countEmployees = getCountEmployees(listEmployees,size);
	averageSalary = getAverageSalary(countEmployees,totalSalary);
	employeesWithMaxSalary = getEmployeeWithMaxSalary(listEmployees,size,averageSalary);
	//muestro listado
	printf("********** Listado total salarios, promedio salarios y cantidad de empleados superior al salario**********\n");
	printf("Total salarios: %f\n",totalSalary);
	printf("Promedio salarios: %f \n", averageSalary);
	printf("Cantidad de empleados que superan el salario promedio: %d\n", employeesWithMaxSalary);



}

void showReports(Employee listEmployees[], int size)
{
	char userResponse = 's';
	printf("********** SECCION INFORMES **********\n");
	if(!isEmptyList(listEmployees,size))
	{ // consulto al usuario que tipo de reporte desea ver
		do{
			switch(showReportsMenu())
			{
			case SHOW_ORDERED:
				showEmployeesOrderedByLastNameAndSector(listEmployees,size);
				break;
			case SHOW_AVERAGE:
				showAverageSalary(listEmployees,size);
				break;
			}
		}while(userResponse == 's');
	}

}









