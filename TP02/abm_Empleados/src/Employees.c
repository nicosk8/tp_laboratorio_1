/*
 * ArrayEmployees.c
 *
 *  Created on: Sep 18, 2020
 *      Author: nicole
 */
#include "Employees.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Defines.h"
#include "utn.h"

int printOptionMenu(int *pOption) {

	int ret= ERROR;
	printf("********** MENU PRINCIPAL **********\n");
	printf("1- Altas de nuevos empleados\n");
	printf("2- Modificar empleados\n");
	printf("3- Eliminar empleados\n");
	printf("4- Informes\n");
	printf("5- Salir\n");
	printf("************************************\n");
	ret = getOption(pOption, MESSAGE_INSERT_OPTION,
			MESSAGE_ERROR_INSERT_OPTION, 1, 5, RETRIES);
	return ret;
}

int initEmployees(Employee listEmployees[], int size)
{
	int i;
	int ret= ERROR;
	if(listEmployees != NULL && size > ZERO)
	{
			for(i = ZERO; i < size; i++)
			{
				listEmployees[i].isEmpty = 0;
			}
			ret = OK;
	}
	return ret;
}

int printEmployees(Employee listEmployees[], int size)
{

	int i;
	int ret = ERROR;
	if (listEmployees != NULL && size > ZERO)
	{
		for(i = ZERO; i < size; i++)
		{
			if(!listEmployees[i].isEmpty)
			{
				printf("isEmpty: %d \tId: %d \tNombre: %s \tApellido: %s \tSueldo: %.2f \tSector: %d\n",listEmployees[i].isEmpty,listEmployees[i].id, listEmployees[i].name, listEmployees[i].lastName, listEmployees[i].salary, listEmployees[i].sector);
				ret = OK;
			}
		}
	}
	return ret;
}
/*
void add(Employee listEmployees[], int size, int *id)
{
	char name[LENGTH],
		 lastName[LENGTH];
	float salary;
	int sector;
//		currentId = *id;
	// verifico que haya espacio en la lista para poder agregar empleado
	printf("********** SECCION AGREGAR EMPLEADOS **********\n");
	if(getFreeIndex(listEmployees,size) != ERROR){
		// obtengo los datos del nuevo empleado
		getNewEmployeeData(name,lastName,&salary,&sector);
		if(addEmployee(listEmployees,name,lastName,salary,sector,size,currentId) == OK)
		{	//aumento el id
			currentId++;
			*id = currentId;
			printf("%s",MESSAGE_CORRECT_IN);
		}

	}else
	{ // no hay espacio
		printf("%s",MESSAGE_FULL_LIST);
	}
	printf("********** FIN SECCION AGREGAR EMPLEADOS **********\n");
}

int getFreeIndex(Employee listEmployee[], int size)
{

	int index = -1, i;
	for(i =0; i < size ; i++){
		if(!listEmployee[i].isEmpty){
			index = i;
			break;
		}
	}
	return index;
}

void getNewEmployeeData(char name[],char lastName[],float *salary,int *sector)
{
	printf("********** CARGAR DATOS PARA NUEVO EMPLEADO **********\n");
	getString(name,"Ingrese el nombre:\n",MSG_GETSTRING_ERROR,RETRIES);
	getString(lastName,"Ingrese el apellido:\n",MSG_GETSTRING_ERROR,RETRIES);
	getSalary(salary,"Ingrese el salario:\n", MSG_NUMBER_ERROR, RETRIES);
	showSector();
	getOption(sector, "Ingrese sector:\n", MESSAGE_ERROR_INSERT_OPTION,ADD,DELETE,RETRIES);
	printf("********** FIN CARGAR DATOS PARA NUEVO EMPLEADO **********\n");
}

int getSalary(float *pResult, char *message, char *errorMessage,int retries)
{
	float num;
	if (pResult != NULL && message != NULL && errorMessage != NULL && retries >= 0)
	{
		do{
			printf(message);
			if (getFloat(&num) == OK)
			{
				*pResult = num;
				return OK;
				break;
				}else
				{
					printf(errorMessage);
					retries--;
				}

	}while (retries >= 0);
	}
	return ERROR;
}

void showSector()
{
	printf("1- Sector RRHH.\n");
	printf("2- Sector Sistemas.\n");
	printf("3- Sector Administración.\n");}



*/



