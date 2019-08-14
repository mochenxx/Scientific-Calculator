/*
 *  File name: factorial.cpp
 *
 *  Author: Mo Chen
 *
 *  Description: cpp file for factorial operations
 */

#include "factorial.h"
#include "print.h"
#include "timeInfo.h"
#include "LogFile.h"

 /*
  * Disable warning of unsafe functions
  * _CRT_SECURE_NO_WARNINGS
  */
#pragma warning(disable : 4996)

double factorial(double last_op_val,
							 unsigned char use_last_operation_value)
{
	double num;
	double fact = 1;

	system("cls");

	/* Check if last operation value exists */
	checkLastOpResult(last_op_val, use_last_operation_value);

	/* Get a number from keyboard */
	printf("\n\n===> ");
	printf("Enter an integer you want to find its factorial (0-65): ");
	scanf_s("%lf", &num);

	/* Check if input number is non-negative and less than 65 */
	if ( num >= 0 && num <= 65 )
	{
		/* Calculate the factorial value */
		for (int i = 1; i <= num; ++i) {
			fact = fact * i;
		}

		/* Print the result of factorial */
		printf("\n\nFactorial of %.lf = %.lf\n\n", num, fact);

		/* Write factorial value with operation type to log file */
		writeToLogFile(fact, OPERATION_FACTORIAL);
	}
	else
	{
		/* Print ERROR Message */
		printf("\n[ERROR] Input number is out of range!\n");
	}

	/* Print pause message */
	printPauseMsg();

	/* Return factorial value */
	return fact;
}