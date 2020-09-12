/*
 ============================================================================
 Name        : calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "calculadora_funciones.h"
#include "utn.h"
int main(void) {
	setbuf(stdout, NULL);
	int 	 status,
	    	 optionUser,
	    	 firstNumber,
	    	 secondNumber,
			 fisrtNumberInserted  = OFF,
	         secondNumberInserted = OFF,
		     sum,
		     substraction,
			 multiplication,
			 operationsResult;
	float    division;
	long int factorialFirstNumber,
	 	 	 factorialSecondNumber;
	status = printOptionMenu(&optionUser);
	while(status == RESULT_OK)
	{
		switch(optionUser)
		{
			case INSERT_FIRST_NUMBER:
				        getNumber(&firstNumber,
				        		  MESSAGE_INSERT_NUMBER,
								  MESSAGE_ERROR_INSERT_NUMBER,
								  RETRIES);
				        fisrtNumberInserted = ON;
				        printOptionMenu(&optionUser);
				        break;
			case INSERT_SECOND_NUMBER:
						getNumber(&secondNumber,
								  MESSAGE_INSERT_NUMBER,
						          MESSAGE_ERROR_INSERT_NUMBER,
						          RETRIES);
						secondNumberInserted = ON;
						printOptionMenu(&optionUser);
						break;

			case DO_OPERATIONS:
						operationsResult = do_Operations(fisrtNumberInserted,
						 	 	 	 	 	 	 	 	 secondNumberInserted,
														 firstNumber,
														 secondNumber,
														 &sum,
														 &substraction,
														 &multiplication,
														 &division,
														 &factorialFirstNumber,
														 &factorialSecondNumber);
						printf("resultado de las operaciones : %d",operationsResult);
						printStatusOperations(operationsResult);
						break;
			case SHOW_RESULTS:
						printResults(operationsResult,
									fisrtNumberInserted,
									secondNumberInserted,
									firstNumber,
									secondNumber,
									sum,
									substraction,
									multiplication,
									division,
									factorialFirstNumber,
									factorialSecondNumber);
						printOptionMenu(&optionUser);
						break;
			case EXIT:
						printf("----------FIN CALCULADORA----------\n");
						exit(0);
						break;
		}
	}
	return 0;
}
