/*
 *  File name: arithmetic.h
 *
 *  Author: Mo Chen
 *
 *  Description: header file for arithmetic operations
 */

#ifndef _ARITHMETIC_H_
#define _ARITHMETIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

/*
 * This function returns the sum of two numbers
 *
 * @param[in] last_oper_val - last operation result value 
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - the sum of two numbers
 */
double addition(double last_oper_val, unsigned char use_last_operation_value);

/*
 * This function returns the difference of two numbers
 *
 * @param[in] last_oper_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - the differences of two numbers
 */
double subtraction(double last_oper_val,
				   unsigned char use_last_operation_value);

/*
 * This function returns the multiplication of two numbers
 *
 * @param[in] last_oper_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - the multiplication of two numbers
 */
double multiplication(double last_oper_val, 
					  unsigned char use_last_operation_value);

/*
 * This function returns the division of two numbers
 * 
 * @param[in] last_oper_val - last operation result value 
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - the multiplication of two numbers
 */
double division(double last_oper_val, unsigned char use_last_operation_value);

/*
 * This function choose and achieve one of arithmetic operations
 *
 * It includes four switch sections:
 *	  '1' - Addition
 *    '2' - Subtraction
 *    '3' - Multiplication
 *    '4' - Division
 *
 * @param[in] choice - Input choice of operation
 * @param[in] last_op_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - the result of selected operation
 */
double chooseArith(char choice, double last_op_val,
	               unsigned char use_last_operation_value);
#endif // !_ARITHMETIC_H_