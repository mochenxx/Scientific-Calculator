/*
 *  File name: factorial.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for factorial operation
 */

#ifndef _FACTORIAL_H_
#define _FACTORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

 /*
 * This function returns factorial of a number
 *
 * @param[in] last_op_val - the last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *	    	 use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - factorial of the input number from keyboard
 */
double factorial(double last_op_val,
	unsigned char use_last_operation_value);
#endif // _FACTORIAL_H_