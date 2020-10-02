#ifndef REPORTS_H_
#define REPORTS_H_

#include "Defines.h"
#include "Employees.h"

int showReportsMenu();
void showEmployeesOrderedByLastNameAndSector(Employee listEmployees[], int size);
void showReports(Employee listEmployees[], int size);
void showAverageSalary(Employee listEmployees[], int size);
#endif /* REPORTS_H_ */
