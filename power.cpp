/*
 *  File name: power.h
 *
 *  Author: Mo Chen
 *
 *  Description: cpp file for power functions
 */

#include "power.h"
#include "print.h"
#include "timeInfo.h"
#include "LogFile.h"

double power(double last_oper_val, unsigned char use_last_operation_value)
{
	double num, pwr, result = NULL;

	/* Check if using last operation value */
	if (use_last_operation_value)
	{
		/* Assign last operation value to num */
		num = last_oper_val;
		printf("\n===> The number you want to find power of is: %lf\n", num);
	}
	else
	{
		/* Get a number from keyboard */
		printf("\n\n===> Enter a number you want to find power of: ");
		scanf_s("%lf", &num);
	}

	/* Get the value of power from input*/
	printf("\n===> Enter value of power: ");
	scanf_s("%lf", &pwr);

	/* Store and print the calculated power value */
	result = pow(num, pwr);
	printf("\n\n");
	printf("Result for %lf to the Power of %lf = %lf \n\n", num, pwr, result);

	/* Return the power value of input number */
	return result;
}


double square(double last_oper_val, unsigned char use_last_operation_value)
{
	double num, result;

	/* Check if using last operation value */
	if (use_last_operation_value)
	{
		/* Assign last operation value to num */
		num = last_oper_val;
		printf("===> The number you want to find square of is: %lf", num);
	}
	else
	{
		/* Get a number from keyboard */
		printf("\n\n===> Enter a number you want to find square of: ");
		scanf_s("%lf", &num);
	}

	/* Check if number is negative */
	if (num < 0)
	{
		printf("\n\n[ERROR] Square root cannot take negative value!\n");
		(void)_getch();
	}
	else {
		/* Store and print the calculated square root value */
		result = sqrt(num);
		printf("\n\nResult for Square of %lf = %lf\n\n", num, result);

		/* Return the square root of input number */
		return result;
	}
}

double choosePower(char choice, double last_op_val,
	    		   unsigned char use_last_operation_value)
{
	double result = NULL;

	switch (choice)
	{
		// Power function
		case '1':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_op_val, use_last_operation_value);

			/* Get result of power operation */
			result = power(last_op_val, use_last_operation_value);

			/* Write result with operation type to log file */
			writeToLogFile(result, OPERATION_POWER);

			/* Print pause message */
			printPauseMsg();
			break;
		}

		// Square root function
		case '2':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_op_val, use_last_operation_value);

			/* Get result of square root operation */
			result = square(last_op_val, use_last_operation_value);

			/* Write result of square root with operation type to log file */
			writeToLogFile(result, OPERATION_POWER);

			/* Print pause message */
			printPauseMsg();
			break;
		}

		default:
		{
			/* Print error message for invalid input */
			printInvalidError(2);

			/* Print pause message */
			printPauseMsg();

			break;
		}
	}		// End of switch

	return result;
}