/*
 * Defines.h
 *
 *  Created on: Sep 18, 2020
 *      Author: nicol
 */

#ifndef DEFINES_H_
#define DEFINES_H_
// arrays
#define QTY_EMPLOYEES 3
#define SIZE_BUFFER  5000
#define LENGTH        51
// control
#define OK     0
#define ERROR -1
#define ZERO   0
// switches
#define EMPTY  1
#define ON     1
#define OFF    0
// messagges
#define MESSAGE_INSERT_OPTION "Ingrese una opcion: \n"
#define MESSAGE_ERROR_INSERT_OPTION "Ingreso incorrectamente la opcion. Ingrese nuevamente: \n"
#define MESSAGE_CORRECT_IN "Usuario ingresado exitosamente!"
#define MESSAGE_FULL_LIST "No hay espacio para agregar nuevos empleados. Puede eliminar o borrar empleado\n"
#define MSG_GETSTRING_ERROR "Error, debe ingresar sólo letras.\n"
#define MSG_NUMBER_ERROR "Error, debe ingresar sólo números.\n"

// menu
#define ADD 1
#define MODIFY 2
#define DELETE 3
#define SHOW 4
#define EXIT 5

// others
#define  RETRIES      			3
#endif /* DEFINES_H_ */
