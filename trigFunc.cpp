/*
 *  File name: trigFunc.cpp
 *
 *  Author: Mo Chen
 *
 *  Description: cpp file for trigonormetic functions
 */

#include "trigFunc.h"
#include "macros.h"
#include "print.h"
#include "timeInfo.h"
#include "LogFile.h"

double sinFunction(void)
{
	double angle_degree, result;

	/* Get a degree from keyboard */
	printf("\n\n===> Enter an angle in degree(¡ã): ");
	scanf_s("%lf", &angle_degree);

	/* Calculate and print the result */
	result = (sin(degToRad(angle_degree)));
	printf("\n\nValue of sin(%lf¡ã) = %lf\n\n", angle_degree, result);

	/* Return the sine of the degree */
	return result;
}

double cosFunction(void)
{
	double angle_degree, result;

	/* Get a degree from keyboard */
	printf("\n\n===> Enter an angle in degree(¡ã): ");
	scanf_s("%lf", &angle_degree);

	/* Calculate and print the result */
	result = (cos(degToRad(angle_degree)));
	printf("\n\nValue of cos(%lf¡ã) = %lf\n\n", angle_degree, result);

	/* Return the cosine of the degree */
	return result;
}

double tanFunction(void)
{
	double angle_degree, result;

	/* Get a degree from keyboard */
	printf("\n\n===> Enter an angle in degree(¡ã): ");
	scanf_s("%lf", &angle_degree);

	/* Calculate and print the result */
	result = (tan(degToRad(angle_degree)));
	printf("\n\nValue of tan(%lf¡ã) = %lf\n\n", angle_degree, result);

	/* Return the tangent of the degree */
	return result;
}

double chooseTrig(char choice, double last_oper_val,
				  unsigned char use_last_operation_value)
{
	double result = NULL;

	switch (choice)
	{
		// Sine function
		case '1':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_oper_val, use_last_operation_value);

			/* Get result of Sine function */
			result = sinFunction();

			/* Write result value with operation type to log file */
			writeToLogFile(result, OPERATION_TRIG);

			/* Print pause message */
			printPauseMsg();
			break;
		}

		// Cosine function
		case '2':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_oper_val, use_last_operation_value);

			/* Get result of Cosine function */
			result = cosFunction();

			/* Write result value with operation type to log file */
			writeToLogFile(result, OPERATION_TRIG);

			/* Print pause message */
			printPauseMsg();
			break;
		}

		// Tangent function
		case '3':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_oper_val, use_last_operation_value);

			/* Get result of Tangent function */
			result = tanFunction();

			/* Write result value with operation type to log file */
			writeToLogFile(result, OPERATION_TRIG);

			/* Print pause message */
			printPauseMsg();
			break;
		}

		default:
		{
			/* Print error message for invalid input */
			printInvalidError(3);

			/* Print pause message */
			printPauseMsg();

			break;
		}
	}	// End of inner switch
	
	return result;
}