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
				listEmployees[i].isEmpty = 1;
			}
			ret = OK;
	}
	return ret;
}

int printEmployees(Employee listEmployees[], int size)
{
	printf("********** SECCIÓN MOSTRAR EMPLEADOS **********\n");
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
	printf("********** FIN SECCIÓN MOSTRAR EMPLEADOS **********\n");
	return ret;
}
/*********************** ADD SECTION TOP ****************************************************************/

int getFreeIndex(Employee listEmployee[], int size)
{
	int index = -1, i;
	for(i =0; i < size ; i++){
		if(listEmployee[i].isEmpty == 1){
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
	getSalary(salary,"Ingrese el salario ($00,00):\n", MSG_NUMBER_ERROR, RETRIES);
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

Employee NewEmployee(int id,char name[],char lastName[],float salary,int sector){
	Employee employee;
	employee.id = id;
	strcpy(employee.name, name);
	strcpy(employee.lastName, lastName);
	employee.salary = salary;
	employee.sector = sector;
	employee.isEmpty = 0;
	return employee;
}

int addEmployee(Employee listEmployees[], char name[],char lastName[],float salary,int sector,int size, int id,int freeIndex)
{
	int ret = ERROR;
	Employee newEmployee;
	if(listEmployees != NULL && size > 0 && id > 0 && name != NULL && lastName!= NULL && salary >0 && sector >0 && freeIndex != ERROR)
	{   // creo el empleado, lo agrego a la lista y doy de baja el índice libre
		newEmployee = NewEmployee(id,name,lastName,salary,sector);
		listEmployees[freeIndex] = newEmployee;
		listEmployees[freeIndex].isEmpty = 0;
		ret = OK;
	}
	return ret;
}
void add(Employee listEmployees[], int size, int *id)
{
	char  name[LENGTH],
		  lastName[LENGTH];
	float salary;
	int   sector,
		  currentId = *id,
		  freeIndex = getFreeIndex(listEmployees,size);
	// verifico que haya espacio en la lista para poder agregar empleado
	printf("********** SECCION AGREGAR EMPLEADOS **********\n");
	if(freeIndex != ERROR){
		// obtengo los datos del nuevo empleado
		getNewEmployeeData(name,lastName,&salary,&sector);
		if(addEmployee(listEmployees,name,lastName,salary,sector,size,currentId,freeIndex) == OK)
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
/*********************** ADD SECTION BOTTOM ****************************************************************/
/*********************** MODIFY SECTION TOP ****************************************************************/
int isEmptyList(Employee listEmployee[], int size){
	int isEmpty;
	for(int i = 0; i<size; i++){
		if(listEmployee[i].isEmpty == 1){
			isEmpty = 1;
		}else{
			isEmpty = 0;
		}
	}
	return isEmpty;
}
int findEmployeeById(Employee listEmployees[], int size, int id){
	int index=-1,
		i;
	if (listEmployees != NULL && size > 0 && id > 0){
		for(i = 0; i < size ; i++){
			if(listEmployees[i].id == id)
			{
				index = i;
				break;
			}
		}
	}
	return index;

}

int getModifyOption(){
	int option;
	printf("********** MENU MODIFICAR **********\n");
	printf("1- Modificar Nombre\n");
	printf("2- Modificar Apellido\n");
	printf("3- Modificar Sueldo\n");
	printf("4- Modificar Sector\n");
	getOption(&option,MESSAGE_INSERT_OPTION,MESSAGE_ERROR_INSERT_OPTION,ADD,SHOW,RETRIES);
	return option;
}

int modify(Employee listEmployees[], int size){
	int id,
		index,
		sector;
	char name[LENGTH],
		 lastName[LENGTH];
//		 optionUser = 's';
	float salary;
	printf("********** SECCION MODIFICAR EMPLEADOS **********\n");
	printf("********** EMPLEADOS CARGADOS **********\n");
	printEmployees(listEmployees,size);
	if(isEmptyList(listEmployees,size) == 1){
		printf("La lista de empleados esta vacia.\n");
		printf("No se puede modificar elementos.\n");
	}else{
		// lógica principal del módulo
			getNumber(&id,MESSAGE_INSERT_ID,MESSAGE_ERROR_ID,RETRIES);
			index = findEmployeeById(listEmployees,size,id);
			if(index != ERROR){
				// si el empleado existe muestro los datos
				printf("Los datos actuales del empleado son:\n");
				printEmployees(listEmployees,size);
//				do{
					switch (getModifyOption()){

					case NAME:
						printf("**** Modificar nombre **** \n");
						getString(name,"Ingrese el nuevo nombre: \n",MSG_GETSTRING_ERROR,RETRIES);
						strcpy(listEmployees[index].name, name);
						printf("**** Nombre Modificado ****\n");

						break;
					case LAST_NAME:
						printf("**** Modificar apellido **** \n");
						getString(name,"Ingrese el nuevo apellido: \n",MSG_GETSTRING_ERROR,RETRIES);
						strcpy(listEmployees[index].lastName, lastName);
						printf("**** Apellido Modificado ****\n");
						break;
					case SECTOR:
						printf("**** Modificar sector **** \n");
						showSector();
						getOption(&sector, "Ingrese sector:\n", MESSAGE_ERROR_INSERT_OPTION,ADD,DELETE,RETRIES);
						listEmployees[index].sector = sector;
						printf("**** Sector Modificado ****\n");
						break;
					case SALARY:
						printf("**** Modificar salario ****\n");
						getSalary(&salary,"Ingrese el salario ($00,00):\n", MSG_NUMBER_ERROR, RETRIES);
						listEmployees[index].salary = salary;
						printf("** Salario Modificado **\n");
						break;
					}
					printEmployees(listEmployees,size);
//				}while(optionUser == 's');
			}

	}
	printf("********** FIN SECCION MODIFICAR EMPLEADOS **********\n");
	return 0;
}
























