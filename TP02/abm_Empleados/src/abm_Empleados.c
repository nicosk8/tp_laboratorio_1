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
	int optionUser,
		id = 1;
	Employee listEmployees[QTY_EMPLOYEES];

	initEmployees(listEmployees,QTY_EMPLOYEES);

	while(printOptionMenu(&optionUser) != ERROR){
	switch (optionUser)
		{
			case ADD:
				add(listEmployees,QTY_EMPLOYEES,&id);
				break;
			case MODIFY:
				modify(listEmployees,QTY_EMPLOYEES);
				break;
			case DELETE:
				delete(listEmployees,QTY_EMPLOYEES);
				break;
			case SHOW:
				printEmployees(listEmployees,QTY_EMPLOYEES);
				break;
			case EXIT: printf("Usted sali�");
					   break;
			default: printf("Usted ingres� una opci�n inv�lida, reintente.\n");
		}
	}
	return 0;
}
