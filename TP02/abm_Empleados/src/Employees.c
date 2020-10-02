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

void printEmployee(Employee employee){
	printf("ID: %d - Nombre: %s - Apellido: %s - Sueldo: %f - Sector: %d\n",employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
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
				printEmployee(listEmployees[i]);
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
//		  optionUser;
	float salary;
	int   sector,
		  currentId = *id,
		  freeIndex = getFreeIndex(listEmployees,size);
	// verifico que haya espacio en la lista para poder agregar empleado
	printf("********** SECCION AGREGAR EMPLEADOS **********\n");

	if(freeIndex != ERROR && freeIndex < size)
	{
//	do{
			// obtengo los datos del nuevo empleado
			getNewEmployeeData(name,lastName,&salary,&sector);
			if(addEmployee(listEmployees,name,lastName,salary,sector,size,currentId,freeIndex) == OK)
			{	//aumento el id
				currentId++;
				*id = currentId;
				printf("%s",MESSAGE_CORRECT_IN);
			}else
			{ // no hay espacio
				printf("%s",MESSAGE_FULL_LIST);
			}
			printEmployees(listEmployees,size);
//			getCaracter(&optionUser, "Desea agregar otro empleado? Ingrese s o n: ", "ERROR: ingrese s o n\n ", 'n', 's', RETRIES);

//	}while(freeIndex < size && optionUser == 's');
	}else
	{ // no hay espacio
		printf("%s",MESSAGE_FULL_LIST);
	}
	printf("********** FIN SECCION AGREGAR EMPLEADOS **********\n");
}
/*********************** ADD SECTION BOTTOM ****************************************************************/
/*********************** MODIFY SECTION TOP ****************************************************************/
int isEmptyList(Employee listEmployee[], int size){
	int isEmpty=1;
	for(int i = 0; i<size; i++){
		if(listEmployee[i].isEmpty != 1){
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
	printf("3- Modificar Sector\n");
	printf("4- Modificar Sueldo\n");
	getOption(&option,MESSAGE_INSERT_OPTION,MESSAGE_ERROR_INSERT_OPTION,ADD,SHOW,RETRIES);
	return option;
}

int modify(Employee listEmployees[], int size){
	int  id,
		 index,
		 sector;
	char name[LENGTH],
		 lastName[LENGTH],
		 optionField='s',
		 optionUser='s';
	float salary;
	printf("********** SECCION MODIFICAR EMPLEADOS **********\n");
	printf("********** EMPLEADOS CARGADOS **********\n");
	printEmployees(listEmployees,size);
	if(isEmptyList(listEmployees,size) == 1){
		printf("La lista de empleados esta vacia.\n");
		printf("No se puede modificar elementos.\n");
	}else
	{
		// lógica principal del módulo
		do{
			getNumber(&id,MESSAGE_INSERT_ID,MESSAGE_ERROR_ID,RETRIES);
			index = findEmployeeById(listEmployees,size,id);
			if(index != ERROR){
				// si el empleado existe muestro los datos
				printf("Los datos actuales del empleado son:\n");
				printEmployees(listEmployees,size);
				do{
					switch (getModifyOption()){

					case NAME:
						printf("**** Modificar nombre **** \n");
						getString(name,"Ingrese el nuevo nombre: \n",MSG_GETSTRING_ERROR,RETRIES);
						strcpy(listEmployees[index].name, name);
						printf("**** Nombre Modificado ****\n");

						break;
					case LAST_NAME:
						printf("**** Modificar apellido **** \n");
						getString(lastName,"Ingrese el nuevo apellido: \n",MSG_GETSTRING_ERROR,RETRIES);
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
					getCaracter(&optionField, "Desea modificar otro campo? Ingrese s o n: ", "ERROR: ingrese s o n\n ", 'n', 's', RETRIES);
				}while(optionField == 's');
				getCaracter(&optionUser, "Desea modificar otro empleado? Ingrese s o n: ", "ERROR: ingrese s o n\n ", 'n', 's', RETRIES);
			}
		}while(optionUser == 's');
	}
	printf("********** FIN SECCION MODIFICAR EMPLEADOS **********\n");
	return 0;
}

Employee getEmployeeById(Employee listEmployee[], int size,int id){
	Employee employee;
	for(int i = 0; i<size; i++){
		if(listEmployee[i].id == id && listEmployee[i].isEmpty == 0){
			employee = listEmployee[i];
			break;
		}
	}
	return employee;
}

int deleteEmployee(Employee listEmployees[], int size,int id){
	int ret = ERROR;
	int indexToDelete;
	if(listEmployees != NULL && size > 0 && id >0 ){
		indexToDelete = findEmployeeById(listEmployees, size, id);
		if(indexToDelete != ERROR){
			listEmployees[indexToDelete].isEmpty = 1;
			ret = OK;
		}
	}
	return ret;
}

void delete(Employee listEmployees[], int size){
	    int  id,
			 index;
//			 sector;
		char //name[LENGTH],
//			 lastName[LENGTH],
			  optionUser='s';
//		float salary;
		Employee employeeToDelete;

		if(isEmptyList(listEmployees,size) == 1){
			printf("La lista de empleados esta vacia.\n");
			printf("No se puede modificar elementos.\n");
		}else
		{
			// lógica principal del módulo
			do{
				getNumber(&id,MESSAGE_INSERT_ID,MESSAGE_ERROR_ID,RETRIES);
				index = findEmployeeById(listEmployees,size,id);
				if(index != ERROR){
					// si el empleado existe muestro los datos
					employeeToDelete = getEmployeeById(listEmployees,size,id);
					printf("Empleado a eliminar:\n");
					printEmployee(employeeToDelete);
					getCaracter(&optionUser, "Está seguro que desea eliminar al empleado? Ingrese s o n: ", "ERROR: ingrese s o n\n ", 'n', 's', RETRIES);
					if (optionUser == 's'){
						deleteEmployee(listEmployees,size,id);
						printf("*** Se ha eliminado el empleado exitosamente!***");
						getCaracter(&optionUser, "Desea eliminar otro id? Ingrese s o n: ", "ERROR: ingrese s o n\n ", 'n', 's', RETRIES);
					}else
					{
						printf("***Operación cancelada***\n");
						getCaracter(&optionUser, "Desea eliminar otro id? Ingrese s o n: ", "ERROR: ingrese s o n\n ", 'n', 's', RETRIES);
					}
				}else
				{
					printf("El id que desea encontrar no existe.\n");
					getCaracter(&optionUser, "Desea eliminar otro empleado? Ingrese s o n: ", "ERROR: ingrese s o n\n ", 'n', 's', RETRIES);
				}
			}while(optionUser == 's');

		}
		printf("********** FIN SECCION MODIFICAR EMPLEADOS **********\n");
}

int sortEmployee(Employee listEmployees[], int size,int order){
	int flagSwap;
	int i;
	int counter;
	int retorno = -1;
	Employee buffer;
	if (listEmployees != NULL && size >= 0){
		do{
			flagSwap = 0;
			for(i=0 ; i< size - 1; i++){
				counter++;
				if(listEmployees[i].isEmpty == 0 && strncmp(listEmployees[i].lastName, listEmployees[i + 1].lastName,LENGTH) > 0 && order)
				{	//ordeno ascendente z - a
					flagSwap = 1;
					buffer = listEmployees[i];
					listEmployees[i] = listEmployees[i + 1];
					listEmployees[i + 1] = buffer;
				}else if(listEmployees[i].isEmpty == 0 && strncmp(listEmployees[i].lastName, listEmployees[i + 1].lastName,LENGTH) < 0 && !order)
				{	//ordeno descendente z - a
					flagSwap = 1;
					buffer = listEmployees[i];
					listEmployees[i] = listEmployees[i + 1];
					listEmployees[i + 1] = buffer;
				 }else if(listEmployees[i].isEmpty == 0 && strncmp(listEmployees[i].lastName, listEmployees[i + 1].lastName,LENGTH) == 0)
				 {
					 //Si los apellidos son iguales, ordeno por sector
					 if(listEmployees[i].sector > listEmployees[i+1].sector && order && listEmployees[i].isEmpty == 0)
					 {
						 //de mayor a menor y criteria =0 descendente
						 //descendente z - a
						 //los apellidos son igules, verificar el sector(ascendente)
						 //si esta 3 -1; necesito que sea 1 - 3
						 flagSwap = 1;
						 buffer = listEmployees[i];
						 listEmployees[i] = listEmployees[i + 1];
						 listEmployees[i + 1] = buffer;
					 }else if(listEmployees[i].sector < listEmployees[i+1].sector && !order  && listEmployees[i].isEmpty == 0){
						//de mayor a menor y criteria =0 descendente
						//descendente z - a
						//los apellidos son igules, verificar el sector
						//si esta 1 - 3; necesito que sea 3 - 1
						flagSwap = 1;
						buffer = listEmployees[i];
						listEmployees[i] = listEmployees[i + 1];
						listEmployees[i + 1] = buffer;
						}
				 }
			}
			size--;
		}while(flagSwap);
		retorno = counter;
	}
	return retorno;
}

float getTotalSalary(Employee listEmployees[], int size)
{
	int i;
	float totalSalary = 0;
	if(!isEmptyList(listEmployees,size))
	{
		for(i=0;i<size;i++)
		{
			if(listEmployees[i].isEmpty == ZERO)
			{
				totalSalary = totalSalary + listEmployees[i].salary;
			}
		}
	}
	return totalSalary;
}

int getCountEmployees(Employee listEmployees[], int size)
{
	int	i,
	    count = 0;
	if(!isEmptyList(listEmployees,size))
		{
			for(i=0;i<size;i++)
			{
				if(listEmployees[i].isEmpty == ZERO)
				{
					count++;
				}
			}
		}
		return count;
}

float getAverageSalary(int countEmployees, float totalSalary){
	return totalSalary/countEmployees;
}

float getEmployeeWithMaxSalary(Employee listEmployees[], int size, float averageSalary)
{
	int i,
		employees = 0;
	if(!isEmptyList(listEmployees,size))
	{
		for (i=0; i<size ;i++)
		{
			if(listEmployees[i].isEmpty == ZERO && listEmployees[i].salary > averageSalary)
			{
				employees++;
			}
		}
	}else
	{
		employees = -1;
	}
	return employees;
}















