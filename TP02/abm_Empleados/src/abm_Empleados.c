/*
 ============================================================================
 Name        : abm_Empleados.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Defines.h"
#include "Employees.h"

int main(void) {
	setbuf(stdout, NULL);
	fflush(stdin);
	int optionUser;
	char name[LENGTH],
		 lastName[LENGTH];
	float salary;
	int sector;
//		id = 1;
	Employee listEmployees[QTY_EMPLOYEES];

	initEmployees(listEmployees,QTY_EMPLOYEES);
//	printEmployees(listEmployees,QTY_EMPLOYEES);
	printOptionMenu(&optionUser);

	switch (optionUser)
		{
			case ADD:
				getNewEmployeeData(name,lastName,&salary,&sector);
				printf("Entré al ADD");
				break;
			case MODIFY: break;
			case DELETE: break;
			case SHOW: break;
			case EXIT: break;
		}

	return 0;
}
