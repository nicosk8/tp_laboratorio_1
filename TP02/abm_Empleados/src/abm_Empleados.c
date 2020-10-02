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
#include "utn.h"
#include "Reports.h"

int main(void) {
	setbuf(stdout, NULL);
	fflush(stdin);
	int optionUser,
		id = 1;
	Employee listEmployees[QTY_EMPLOYEES];
	initEmployees(listEmployees,QTY_EMPLOYEES);

	do
	{
		printOptionMenu(&optionUser);
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
						showReports(listEmployees,QTY_EMPLOYEES);
						break;
					case EXIT:
						printf("************ FIN EMPRESA ************\n");
						exit(0);
						break;
				}
	}while(optionUser != ERROR && optionUser != EXIT);
	return OK;
}
