#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "defines.h"
#include "Employees.h"


/***************** VALIDADORES ***********************************************/
int isNumeric(char *string) {
	int i = 0;
	if (string != NULL) {
		while (string[i] != '\0') {
			if (string[i] < '0' || string[i] > '9')
			{
				return ERROR;
				break;
			}
			i++;
		}
	}
	return OK;
}


int isAlphabetic(char string[]){
	int i = 0;
	while (string[i] != '\0') {
	if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
	{
		return OFF;
	}
	i++;
	}
	return ON;
}

int isFloat(char *string) {
	int ret= OFF,
		i = 0,
	    contadorPuntos = 0;
	if (string != NULL && strlen(string) > 0) {
		while (string[i] != '\0')
		{
			if (string[i] < '0' || string[i] > '9')
			{
				if(string[i]=='.' && contadorPuntos==0){
					contadorPuntos++;
			}else
			{
				ret = ON;
				break;
			}

			}
			i++;
		}
			}
	return ret;
}
/*************** FIN SECCION VALIDARORES *************************************************/
int getInt(int *pResult) {
	int ret = -1;
	char buffer[SIZE_BUFFER];
	fflush(stdin);
	fgets(buffer, sizeof(buffer), stdin);
//	buffer[strlen(buffer) - 1] = '\0';
	if (isNumeric(buffer)) {
		*pResult = atoi(buffer);
		ret = 0;
	}
	return ret;
}


int getOption(int *pResult, char *message, char *errorMessage, int min, int max, int retries)
{
	int ret=-1;
	int num;
	do{
		printf("%s",message);
		if (getInt(&num) == 0)
		{
			if (num >= min && num <= max)
			{
				*pResult = num;
				ret = 0;
				break;
			}else
			{
				printf("%s",errorMessage);
				retries--;
			}
		}
	}while(retries > 0);
	return ret;
}


int getNumber(int *pResult, char *message, char *errorMessage, int retries) {
	int ret;
	int num;
	do
	{
		printf(message);
		if (getInt(&num) == 0)
		{
			*pResult = num;
			ret= OK;
			break;
		}else
		{
			printf(errorMessage);
			ret= ERROR;
			retries--;
		}

	}
	while (retries > 0);
	return ret;
}

int getFloat(float *pResult) {
	int ret = ERROR;
	char buffer[SIZE_BUFFER];
	fflush(stdin);
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';
	if (isFloat(buffer)) {
		*pResult = atof(buffer);
		ret = OK;
	}
	return ret;
}

int getString(char* pResult, char* message,char* errorMessage,int retries){
	int retorno = ERROR;
	char buffer[SIZE_BUFFER];
	if(pResult != NULL && message != NULL && errorMessage != NULL && retries >= 0){
	do {
		printf("%s", message);
		fflush(stdin);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer) - 1] = '\0';
		if (isAlphabetic(buffer)) {
			strcpy(pResult, buffer);
			retorno = OK;
			break;
		}else
		{
			printf("%s", errorMessage);
			retries--;
		}
		} while (retries >= 0);
	}
	return retorno;
}


