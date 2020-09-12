#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "defines.h"
#include "calculadora_funciones.h"



int isNumeric(char *string) {
	int ret = 1;
	int i = 0;
	if (string != NULL) {
		while (string[i] != '\0') {
			if (string[i] < '0' || string[i] > '9')
			{
				ret = -1;
				break;
			}
			i++;
		}
	}
	return ret;
}

int getInt(int *pResult) {
	int ret = -1;
	char buffer[ARRAY_LENGTH];
	fflush(stdin);
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';
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
			ret=0;
			break;
		}else
		{
			printf(errorMessage);
			ret=-1;
			retries--;
		}

	}
	while (retries > 0);
	return ret;
}
