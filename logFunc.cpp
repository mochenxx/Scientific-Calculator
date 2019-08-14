/*
 *  File name: logFunc.cpp
 *
 *  Author: Mo Chen
 *
 *  Description: cpp file for logarithmic functions
 */

#include "logFunc.h"
#include "print.h"
#include "timeInfo.h"
#include "LogFile.h"

double naturalLog(double last_oper_val, unsigned char use_last_operation_value)
{
	double num, result;

	/* Check if user wants to use last operation value */
	if (use_last_operation_value) 
	{
		/* Assign last operation value to num1 */
		num = last_oper_val;
		printf("\n\n===> The number to find its natural log value is: %lf", 
				num);
	}
	else
	{
		/* Get a number from keyboard */
		printf("\n\n===> Enter a number to find its natural log value: ");
		scanf_s("%lf", &num);
	}

	/* Store and print the log value */
	result = log(num);
	printf("\n\nNatural log value of number %lf = %lf\n\n", num, result);

	/* Return the natural log of entered number */
	return result;
}

double logBase10(double last_oper_val, unsigned char use_last_operation_value)
{
	double num, result;

	/* Check if user wants to use last operation value */
	if (use_last_operation_value)
	{
		/* Assign last operation value to num1 */
		num = last_oper_val;
		printf("===> The number to find its log value(with base 10) is: %lf",
				num);
	}
	else
	{
		/* Get a number from keyboard */
		printf("\n\n");
		printf("===> Enter a number to find it's log value(with base 10): ");
		scanf_s("%lf", &num);
	}
	
	/* Store the log value */
	result = log10(num);

	/* Print the calculated result */
	printf("\n\n");
	printf("Log value of number(with base 10) %lf = %lf\n\n", num, result);

	/* Return the log with base 10 of the input number */
	return result;
}

double logBaseN(double last_oper_val, unsigned char use_last_operation_value)
{
	double num, base, result;

	/* Check if user wants to use last operation value */
	if (use_last_operation_value)
	{
		/* Assign last operation value to num1 */
		num = last_oper_val;
		printf("===> The number to find its log value(with base N) is: %lf",
			num);
	}
	else
	{
		/* Get a number from keyboard */
		printf("\n\n===> Enter a number to find its log value(with base N): ");
		scanf_s("%lf", &num);
	}

	/* Get the base number */
	printf("\n\n===> Enter the base number: ");
	scanf_s("%lf", &base);

	/* Store the log value */
	result = (log(num)) / (log(base));

	/* Print the calculated result */
	printf("\n\n");
	printf("Log value of number %lf(with base %.4lf) = %lf", base, num, result);
	printf("\n\n");

	/* Return the log value with base N of the input number */
	return result;
}

double chooseLog(char choice, double last_oper_val,
				 unsigned char use_last_operation_value)
{
	double result = NULL;

	switch (choice)
	{
		// Natural log
		case '1':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_oper_val, use_last_operation_value);

			/* Get result of natraul log operation */
			result = naturalLog(last_oper_val, use_last_operation_value);

			/* Write result with operation type to log file */
			writeToLogFile(result, OPERATION_LOG);

			/* Print pause message */
			printPauseMsg();
			break;
		}

		// Log with base 10
		case '2':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_oper_val, use_last_operation_value);

			/* Get result of log with base 10 operation */
			result = logBase10(last_oper_val, use_last_operation_value);

			/* Write result with operation type to log file */
			writeToLogFile(result, OPERATION_LOG);

			/* Print pause message */
			printPauseMsg();
			break;
		}

		// Log with base N
		case '3':
		{
			/* Check if last operation value exists */
			checkLastOpResult(last_oper_val, use_last_operation_value);

			/* Get result of log with base N operation */
			result = logBaseN(last_oper_val, use_last_operation_value);
		
			/* Write result with operation type to log file */
			writeToLogFile(result, OPERATION_LOG);

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
	}		// End of switch

	return result;
}