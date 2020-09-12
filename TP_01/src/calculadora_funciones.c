#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "utn.h"

int printOptionMenu(int *pOption) {

	int ret;
	printf("Opciones disponibles: \n");
	printf("1. Ingresar el primer operando(A=x)\n");
	printf("2. Ingresar el segundo operando(B=y)\n");
	printf("3. Calcular todas las operaciones\n");
	printf("\t a-)Calcular la suma(A+B)\n");
	printf("\t b-)Calcular la resta(A-B)\n");
	printf("\t c-)Calcular la division(A/B)\n");
	printf("\t d-)Calcular la multiplicacion(A*B)\n");
	printf("\t e-)Calcular el factorial(A!)(B!)\n");
	printf("4. Informar resultados\n");
	printf("\t a-)El resultado de la suma A+B\n");
	printf("\t b-)El resultado de la resta A-B\n");
	printf("\t c-)El resultado de la division A/B\n");
	printf("\t d-)El resultado de la multiplicacion A*B\n");
	printf("\t e-)El resultado de el factorial de A! y B!\n");
	printf("5. Salir\n");
	printf("--------------------\n");
	ret = getOption(pOption, MESSAGE_INSERT_OPTION,
			MESSAGE_ERROR_INSERT_OPTION, INSERT_FIRST_NUMBER, EXIT, RETRIES);
	return ret;
}

int do_Operations(int fisrtNumberInserted,
				  int secondNumberInserted,
				  int firstNumber,
				  int secondNumber,
				  int *pResultSum,
				  int *pResultSub,
				  int *pResultMulti,
				  float *pResultDiv,
				  long int *pFactorialA,
				  long int *pFactorialB)
{

	int resultDivisionOk   = OFF,
		resultFactorialAok = OFF,
		resultFactorialBok = OFF,
		ret= RESULT_NO_OK;

	if (fisrtNumberInserted == ON && secondNumberInserted == ON)
	{
		// suma
		*pResultSum   = firstNumber + secondNumber;
		//resta
		*pResultSub   = firstNumber + secondNumber;
		//multipliación
		*pResultMulti = firstNumber * secondNumber;
		// división
		if (do_division(pResultDiv, firstNumber, secondNumber) == RESULT_OK)
		{
			resultDivisionOk = ON;
		}
		// factorial A
		if (do_factorial(pFactorialA,firstNumber) == RESULT_OK)
		{
			resultFactorialAok = ON;
		}
		// factorial B
		if (do_factorial(pFactorialB,secondNumber) == RESULT_OK)
		{
			resultFactorialBok = ON;
		}


		if (resultDivisionOk   &&
			resultFactorialAok &&
			resultFactorialBok)
		{
			ret = RESULT_OK;
//		}
	}
 	return ret;
}

int do_division(float *pResult, int dividend, int divider)
{
	if (divider == ZERO)
	{
		return RESULT_NO_OK;
	}else
	{
		*pResult = (float) dividend / divider;
		return RESULT_OK;
	}
}

int isNegative(int number)
{
	int ret;
	if (number < 0)
	{
		ret = ON;
	}
	return ret;
}

int factorial(int number) {
	int ret;
	if (number == 0) {
		ret = ON;
	} else {
		ret = (number * factorial(number - 1));
	}
	return ret;
}

int do_factorial(long int *pResult, int number) {

	if (isNegative(number)) {
		return RESULT_NO_OK;
	} else {
		*pResult = factorial(number);
		return RESULT_OK;
	}
}

void printStatusOperations(int statusOperations){
	if(statusOperations == RESULT_OK){
		printf("%s", MESSAGE_DO_OPERATIONS);
	}else{
		printf("%s", MESSAGE_ERROR_DO_OPERATIONS_STATUS);
	}
}

void printResults(int operationsStatus,
				  int fisrtNumberInserted,
		  	  	  int secondNumberInserted,
				  int firstNumber,
				  int secondNumber,
				  int ResultSum,
				  int ResultSub,
				  int ResultMulti,
				  float ResultDiv,
				  long int FactorialA,
				  long int FactorialB)
{

	if (fisrtNumberInserted == ON && secondNumberInserted == ON &&
		operationsStatus == RESULT_OK)

	{
		printf("%s %d \n", MESSAGE_INSERT_FIRST_NUMBER, firstNumber);
		printf("%s %d \n", MESSAGE_INSERT_SECOND_NUMBER, secondNumber);
		printf("%s %d \n", MESSAGE_RESULT_SUM, ResultSum);
		printf("%s %d \n", MESSAGE_RESULT_SUBTRACTION, ResultSub);
		printf("%s %d \n", MESSAGE_RESULT_MULTIPLICATION, ResultMulti);
		if(secondNumber == ZERO)
		{
			printf("%s \n", MESSAGE_ERROR_DIVISION);
		}else
		{
			printf("%s %f \n", MESSAGE_RESULT_DIVISION, ResultDiv);
		}
		if (isNegative(firstNumber))
		{
			printf("%s \n", MESSAGE_ERROR_FACTORIAL);
		}else
		{
			printf("%s %ld \n", MESSAGE_RESULT_FACTORIAL_A, FactorialA);
		}
		if (isNegative(secondNumber))
				{
					printf("%s \n", MESSAGE_ERROR_FACTORIAL);
				}else
				{
					printf("%s %ld \n", MESSAGE_RESULT_FACTORIAL_B, FactorialB);
				}
	}else
	{
		printf("%s", MESSAGE_ERROR_SHOW_RESULTS);
	}
}
