#ifndef CALCULADORA_FUNCIONES_H_
#define CALCULADORA_FUNCIONES_H_
/*
 * brief - Show a menu and ask for and option
 * param - pOption: option requested
 * return -  returns the inserted option
 * */
int printOptionMenu(int *pOption);
/*
 * brief - Execute calculator's operations
 * param - fisrtNumberInserted: first number inserted flagg
 * param - secondNumberInserted: second number inserted flagg
 * param - firstNumber: first number
 * param - secondNumber:second number
 * param - pResultSum: summary result
 * param - pResultSub: subtraction result
 * param - pResultMulti: multiplication result
 * param - pFactorialA: factorial A result
 * param - pFactorialB: factorial B result
 * return -  returns 1 if it could get a number  else  -1 if it couldn't
 * */
int do_Operations(int fisrtNumberInserted,
		  	  	  int secondNumberInserted,
				  int firstNumber,
				  int secondNumber,
				  int *pResultSum,
				  int *pResultSub,
				  int *pResultMulti,
				  float *pResultDiv,
				  long int *pFactorialA,
				  long int *pFactorialB);
/*
 * brief - Divide two numbers excepts if divider is zero
 * param - pResult: division result
 * param - dividend : dividend
 * param - divider : divider
 * return -  returns RESULT_OK (or 0) if it could do all operations else RESULT_NO_OK (or -1) if it couldn't
 * */
int do_division(float *pResult, int dividend, int divider);
/*
 * brief - Verify is a number is positive to can calculate factorial of a number
 * param - pResult: result of the factorial
 * param - number: number inserted
 * return -  returns the factorial calculated
 * */
int factorial(int number);
/*
 * brief - Calculates factorial of a number
 * param - number: number inserted
 * return -  returns the factorial calculated
 * */
int do_factorial(long int *pResult, int number);
/*
 * brief - Verify is a number is negative
 * param - number: number inserted
 * return -  returns ON (or 1) if it's negative
 * */
int isNegative(int number);
/*
 * brief - print a message for successfully excecution or error
 * param - statusOperations: returned code by do_Operations function
 * return -  void
 * */
void printStatusOperations(int statusOperations);
/*
 * brief - print results calculated by do_Operations function
 * param - fisrtNumberInserted: first number inserted flagg
 * param - secondNumberInserted: second number inserted flagg
 * param - firstNumber: first number
 * param - secondNumber:second number
 * param - pResultSum: summary result
 * param - pResultSub: subtraction result
 * param - pResultMulti: multiplication result
 * param - pFactorialA: factorial A result
 * param - pFactorialB: factorial B result
 * return -  void
 * */
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
				  long int FactorialB);

#endif /* CALCULADORA_FUNCIONES_H_ */
