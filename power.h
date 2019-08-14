/*
 *  File name: power.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for power functions
 */

#ifndef _POWER_H_
#define _POWER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

/*
 * This function returns power value of a number
 *
 * @param[in] last_op_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - power value of the input number from keyboard
 */
double power(double last_oper_val, unsigned char use_last_operation_value);

/*
 * This function returns square root of a number
 *
 * @param[in] last_op_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - square root of the input number from keyboard
 */
double square(double last_oper_val, unsigned char use_last_operation_value);

/*
 * This function choose and achieve one of power functions
 *
 * It includes two switch sections:
 *	  '1' - Power function
 *    '2' - Square root
 *
 * @param[in] choice - Input choice of operation
 * @param[in] last_op_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - result of power function
 */
double choosePower(char choice, double last_op_val,
	unsigned char use_last_operation_value);
#endif // !_POWER_H_