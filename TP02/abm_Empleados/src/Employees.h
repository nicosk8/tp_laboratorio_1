/*
 * Employee.h
 *
 *  Created on: Sep 18, 2020
 *      Author: nicole
 */

#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_
#include "Defines.h"

typedef struct{
	int id;
	char name[LENGTH];
	char lastName[LENGTH];
	float salary;
	int sector;
	int isEmpty;

}Employee;

/*Brief
 * Param
 * Param
 * Return
 * */
int initEmployees(Employee listEmployees[], int size);
/*Brief
 * Param
 * Param
 * Return
 * */
int printEmployees(Employee listEmployees[], int size);
/*Brief
 * Param
 * Param
 * Return
 * */
int printOptionMenu(int *pOption);
/*Brief
 * Param
 * Param
 * Return
 * */

//void add(Employee listEmployees[], int size, int *id);
/*Brief
 * Param
 * Param
 * Return
 * */
//int getFreeIndex(Employee listEmployee[], int size);
/*Brief
 * Param
 * Param
 * Return
 * */
void getNewEmployeeData(char name[],char lastName[],float *salary,int *sector);
/*Brief
 * Param
 * Param
 * Return
 * */
void showSector();
/*Brief
 * Param
 * Param
 * Return
 * */
int getSalary(float *pResult, char *message, char *errorMessage,int retries);

#endif /* EMPLOYEES_H_ */
