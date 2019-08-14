/*
 *  File name: arithmetic.cpp
 *
 *  Author: Mo Chen
 *
 *  Description: cpp file for arithmetic operations
 */

#include <string.h>
#include "arithmetic.h"
#include "print.h"
#include "timeInfo.h"
#include "LogFile.h"

double addition(double last_oper_val, unsigned char use_last_operation_value)
{
	double num1, num2, sum;

	/* Check if use last operation value */
	if (use_last_operation_value) 
	{
		/* Assign last operation value to num1 */
		num1 = last_oper_val;
		printf("\n\n===> The first number you want to add: %lf\n", num1);
	} 
	else 
	{
		/* Get the first number from keyboard */
		printf("\n\n===> Enter the first number you want to add: ");
		scanf_s("%lf", &num1);
	}

	/* Get the second number from keyboard */
	printf("\n===> Enter the second number: ");
	scanf_s("%lf", &num2);

	/* Store and print the sum of two numbers */
	sum = (num1)+(num2);
	printf("\n\n");
	printf("Result of %lf + %lf = %lf\n\n", num1, num2, sum);

	/* Return the sum of two numbers */
	return sum;
}

double subtraction(double last_oper_val, unsigned char use_last_operation_value)
{
	double num1, num2, diff;

	/* Check if use last operation value */
	if (use_last_operation_value)
	{
		/* Assign last operation value to num1 */
		num1 = last_oper_val;
		printf("\n===> The first number you want to subtract: %lf\n", num1);
	}
	else 
	{
		/* Get the first number from keyboard */
		printf("\n\n===> Enter the first number you want to subtract: ");
		scanf_s("%lf", &num1);
	}
	
	/* Get the second number from keyboard */
	printf("\n===> Enter the other number: ");
	scanf_s("%lf", &num2);

	/* Store and print the difference of two numbers */
	diff = num1 - num2;
	printf("\n\nResult of %lf - %lf = %lf\n\n", num1, num2, diff);

	/* Return the difference of two numbers */
	return diff;
}

double multiplication(double last_oper_val,
	unsigned char use_last_operation_value)
{
	double num1, num2, multi;

	/* Check if use last operation value */
	if (use_last_operation_value)
	{
		/* Assign last operation value to num1 */
		num1 = last_oper_val;
		printf("\n===> The first number you want to multiply: %lf\n", num1);
	}
	else 
	{
		/* Get the first number from keyboard */
		printf("\n\n===> Enter the first number you want to multiply: ");
		scanf_s("%lf", &num1);
	}
	
	/* Get the second number from keyboard */
	printf("\n\n===> Enter the other number: ");
	scanf_s("%lf", &num2);

	/*Calculate and print the multiplication of two numbers */
	multi = (num1) * (num2);
	printf("\n\nResult of %lf * %lf = %lf\n\n", num1, num2, multi);

	/* Return the multiplication of two numbers */
	return multi;
}

double division(double last_oper_val, unsigned char use_last_operation_value)
{
	double num1, num2, div = NULL;

	/* Check if use last operation value */
	if (use_last_operation_value)
	{
		/* Assign last operation value to num1 */
		num1 = last_oper_val;
		printf("\n===> The first number you want to divide: %lf\n", num1);
	}
	else
	{
		/* Get the dividend from keyboard */
		printf("\n\n===> Enter the dividend: ");
		scanf_s("%lf", &num1);
	}

	/* Get the divisor from keyboard */
	printf("\n===> Enter the divisor: ");
	scanf_s("%lf", &num2);

	/* Check if the divisor is zero */
	if (num2 == 0)
	{
		/* Print ERROR Message */
		printf("\n[ERROR] Division by zero! Aborting ...\n");
		(void)_getch();
	}
	else
	{
		/* Calculate and print the division of two numbers */
		div = num1 / num2;
		printf("\n\nResult of %lf / %lf = %lf\n\n", num1, num2, div);

		/* Write result with operation type to log file */
		writeToLogFile(div, OPERATION_ARITHMETIC);

		/* Return the division of two numbers */
		return div;
	}
}

double chooseArith(char choice, double last_op_val,
				   unsigned char use_last_operation_value)
{
	double result = NULL;

	switch (choice)
	{
		// Addition operation
		case '1':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_op_val, use_last_operation_value);

			/* Store result of addition */
			result = addition(last_op_val, use_last_operation_value);

			/* Write result with operation type to log file */
			writeToLogFile(result, OPERATION_ARITHMETIC);

			/* Print pause message */
			printPauseMsg();

			break;
		}

		// Subtraction operation
		case '2':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_op_val, use_last_operation_value);

			/* Store result of subtraction */
			result = subtraction(last_op_val, use_last_operation_value);

			/* Write result with operation type to log file */
			writeToLogFile(result, OPERATION_ARITHMETIC);

			/* Print pause message */
			printPauseMsg();

			break;
		}

		// Multiplication operation
		case '3':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_op_val, use_last_operation_value);

			/* Store result of multiplication */
			result = multiplication(last_op_val, use_last_operation_value);

			/* Write result with operation type to log file */
			writeToLogFile(result, OPERATION_ARITHMETIC);

			/* Print pause message */
			printPauseMsg();

			break;
		}

		// Division operation
		case '4':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_op_val, use_last_operation_value);

			/* Store result of division */
			result = division(last_op_val, use_last_operation_value);

			/* Print pause message */
			printPauseMsg();

			break;
		}

		default:
		{
			/* Print error message for invalid input */
			printInvalidError(4);

			/* Print pause message */
			printPauseMsg();

			break;
		}
	}	// End of inner switch

	return result;
}