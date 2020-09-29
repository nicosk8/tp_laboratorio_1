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
void printEmployee(Employee employee);
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
/*Brief
 * Param
 * Param
 * Return
 * */
Employee NewEmployee(int id,char name[],char lastName[],float salary,int sector);
/*Brief
 * Param
 * Param
 * Return
 * */
int addEmployee(Employee listEmployees[], char name[],char lastName[],float salary,int sector,int size, int id,int freeIndex);
/*Brief
 * Param
 * Param
 * Return
 * */
void add(Employee listEmployees[], int size, int *id);
/*Brief
 * Param
 * Param
 * Return
 * */
int isEmptyList(Employee listEmployee[], int size);
/*Brief
 * Param
 * Param
 * Return
 * */
int modify(Employee listEmployees[], int size);
/*Brief
 * Param
 * Param
 * Return
 * */
int findEmployeeById(Employee listEmployees[], int size, int id);
/*Brief
 * Param
 * Param
 * Return
 * */
int getModifyOption();
/*Brief
 * Param
 * Param
 * Return
 * */
Employee getEmployeeById(Employee listEmployee[], int size,int id);
int deleteEmployee(Employee listEmployees[], int size,int id);
void delete(Employee listEmployees[], int size);
#endif /* EMPLOYEES_H_ */
