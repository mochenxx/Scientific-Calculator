/*
 *  File name: main.cpp
 *
 *  Author: Mo Chen
 *
 *  Copyright: 2019 Don't steel my file
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <cctype>
#include <stdbool.h>

#include "macros.h"
#include "print.h"
#include "arithmetic.h"
#include "trigFunc.h"
#include "logFunc.h"
#include "power.h"
#include "factorial.h"
#include "LogFile.h"
#include "timeInfo.h"
#include "softwareInfo.h"

 /*
  * Disable warning of unsafe functions
  * _CRT_SECURE_NO_WARNINGS
  */
#pragma warning(disable : 4996)

int main()
{
	char main_menu_choice = 0;		// choice for main menu of caluculator
	char log_file_choice = 0;		// choice for log file management
	double last_oper_val = 0;		// last operation result value
	unsigned char use_last_operation_value = 0;	// flag for whether use last 
												// operation result value
	do
	{
		/* Display main menu */
		displayMainMenu();

		/* Get choice from the user */
		main_menu_choice = getChoice();

		switch (main_menu_choice)
		{
			/* Arithmetic Operations */
			case '1':
			{
				/* Display menu of arithmetic operations */
				displayArithMenu();

				/* Get choice from user and execute it */
				chooseArith(getChoice(), last_oper_val,
					        use_last_operation_value);

				/* Set flag to 0 */
				use_last_operation_value = 0;
				
				break;
			}	// End of case 1 arithmetic operation

			/* Trigonometic Functions */
			case '2':
			{
				/* Display menu of trigonometic functions */
				displayTrigMenu();

				/* Get choice from user and execute it */
				chooseTrig(getChoice(), last_oper_val,
						   use_last_operation_value);

				/* Set flag to 0 */
				use_last_operation_value = 0;

				break;
			}	// End of case 2 trignomatic functions

			/* Logarithmic Functions */
			case '3':
			{
				/* Display menu of logarithmic functions */
				displayLogMenu();

				/* Get choice from user and execute it */
				chooseLog(getChoice(), last_oper_val,
						  use_last_operation_value);

				/* Set flag to 0 */
				use_last_operation_value = 0;
				
				break;
			}	// End of case 3 logrithmic functions

			/* Power Functions */
			case '4':
			{
				/* Display menu of power function */
				displayPowerMenu();

				/* Get choice from user and execute it */
				choosePower(getChoice(), last_oper_val,
							use_last_operation_value);

				/* Set flag to 0 */
				use_last_operation_value = 0;

				break;
			}	// End of case 4 power functions

			/* Factorial function */
			case '5':
			{
				/* Calculate factorial value */
				factorial(last_oper_val, use_last_operation_value);

				/* Set flag to 0 */
				use_last_operation_value = 0;
				
				break;
			}	// End of case 5 factorial function

			/* Log file function */
			case '6':
			{
				/* Display menu of trigonometic functions */
				displayLogFileMenu();

				log_file_choice = getChoice();

				/* Get choice from user and execute it */
				last_oper_val = chooseLogFile(log_file_choice, 
											  use_last_operation_value);

				/* Check if user press 2 to get last operation value */
				if (log_file_choice == '2')
				{
					/* Set flag to 1 */
					use_last_operation_value = 1;
				}
				
				break;
			}	// End of case 5 factorial function

			/* Software Information */
			case '7':
			{
				/* Display software information */
				displaySoftwareInfo();

				/* Print pause message */
				printPauseMsg();

				break;
			}

			/* Exit when choice is 8 */
			case '8':
			{
				break;
			}

			default:
			{
				/* Print error message for invalid input */
				printInvalidError(8);

				/* Print pause message */
				printPauseMsg();

				break;
			}
		}	// End of outer switch
	} while (main_menu_choice != '8');	// Exit when choice is 8

	return 0;
}