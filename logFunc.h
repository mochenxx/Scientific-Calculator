/*
 *  File name: logFunc.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for logarithmic functions
 */

#ifndef _LOGFUNCTION_H_
#define _LOGFUNCTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
 * This function returns natural log of a number (where base is e)
 *
 * @param[in] last_op_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - natural log of the input number from keyboard
 */
double naturalLog(double last_oper_val, unsigned char use_last_operation_value);

/*
 * This function returns log value of a number (where base is 10)
 *
 * @param[in] last_op_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - log value with base 10 of the input number from keyboard
 */
double logBase10(double last_oper_val, unsigned char use_last_operation_value);

/*
 * This function returns log value of a number (where base is N)
 *
 * @param[in] last_op_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - log value with base N of the input number from keyboard
 */
double logBaseN(double last_oper_val, unsigned char use_last_operation_value);

/*
 * This function choose and achieve one of logarithmic functions
 *
 * It includes three switch sections:
 *     '1' - Natural log
 *     '2' - Log with base 10
 *	   '3' - Log with base N
 *
 * @param[in] choice - Input choice of operation
 * @param[in] last_op_val - last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - result of selected operation
 */
double chooseLog(char choice, double last_oper_val,
	unsigned char use_last_operation_value);
#endif // !_LOGFUNCTION_H_