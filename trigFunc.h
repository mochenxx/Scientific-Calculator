/*
 *  File name: trigFunc.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for trigonormetic functions
 */

#ifndef _TRIGFUNCTION_H_
#define _TRIGFUNCTION_H_

 /*
  * This function returns sine of a degree
  *
  * @returns - sine of a degree from keyboard
  */
double sinFunction(void);

/*
 * This function returns cosine of a degree
 *
 * @returns - cosine of a degree from keyboard
 */
double cosFunction(void);

/*
 * This function returns tangent of a degree
 *
 * @returns - tangent of a degree from keyboard
 */
double tanFunction(void);

/*
 * This function choose and achieve one of trigonometric functions
 *
 * It includes three switch sections:
 *	 '1' - Sine function
 *   '2' - Cosine function
 *   '3' - Tangent function
 *
 * @param[in] choice - Input choice of operation
 * @param[in] last_oper_val - the last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - result of trigonometric function
 */
double chooseTrig(char choice, double last_oper_val,
	unsigned char use_last_operation_value);
#endif // !_TRIGFUNCTION_H_