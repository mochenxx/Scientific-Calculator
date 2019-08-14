/*
 *  File name: print.cpp
 *
 *  Author: Mo Chen
 *
 *  Description: cpp file for printing various menu and messages
 */

#include <time.h>
#include "print.h"
#include "timeInfo.h"
#include "softwareInfo.h"

/*
 * Disable warning of unsafe functions
 * _CRT_SECURE_NO_WARNINGS
 */
#pragma warning(disable : 4996)

void displaySoftwareInfo(void)
{
	/* Print header of menu */
	printHeader();

	/* Print software information */
	printf("\n\n Version: %u.%u\n", MAJOR_VERSION, MINOR_VERSION);
	printf("\n Author: %s\n", AUTHOR);
	printf("\n Support Email: %s\n", EMAIL);
	printf("\n Copyright(C): 2019\n");
	printf("\n All rights reseverd.\n\n");
}

void displayMainMenu(void)
{
	/* Print header of menu */
	printHeader();

	/* Print main menu of the calculator */
	printf("         %u : %s\n", 1, "Arithmetic Operations (+, -, *, /)");
	printf("         %u : %s\n", 2, "Trigonometric Functions");
	printf("         %u : %s\n", 3, "Logarithmic Functions");
	printf("         %u : %s\n", 4, "Power Functions");
	printf("         %u : %s\n", 5, "Factorial");
	printf("         %u : %s\n", 6, "Log File Management");
	printf("         %u : %s\n", 7, "Software Information");
	printf("         %u : %s\n", 8, "Exit...");
	printf("\n\n");
}

char getChoice(void)
{
	/* Get the input from the user */
	printf("===> Please enter your choice: ");

	/* Return user's choice for the operation */
	return _getche();
}

void printHeader(void)
{
	/* Print author and local time */
	system("cls");
	printf("\n\n");
	printf("Author: %s                    %s\n\n\n", AUTHOR, getLocalTime());
	printf("***************** SCIENTIFIC CALCULATOR ******************\n\n");
}

void displayArithMenu(void)
{
	/* Print header of menu */
	printHeader();

	/* Print options for arithmetic operations */
	printf("         %u : %s\n", 1, "Addition");
	printf("         %u : %s\n", 2, "Subtraction");
	printf("         %u : %s\n", 3, "Multipilication");
	printf("         %u : %s\n", 4, "Division");
	printf("\n\n");
}

void displayTrigMenu(void)
{
	/* Print header of menu */
	printHeader();

	/* Print options for trigonometric functions */
	printf("         %u : %s\n", 1, "Sin function");
	printf("         %u : %s\n", 2, "Cos function");
	printf("         %u : %s\n", 3, "Tan function");
	printf("\n\n");
}

void displayLogMenu(void)
{
	/* Print header of menu */
	printHeader();

	/* Print options for logarithmic functions */
	printf("         %u : %s\n", 1, "Natural log");
	printf("         %u : %s\n", 2, "Log with base 10");
	printf("         %u : %s\n", 3, "Log with base N");
	printf("\n\n");
}

void displayPowerMenu(void)
{
	/* Print header of menu */
	printHeader();

	/* Print options for power functions */
	printf("         %u : %s\n", 1, "Press 1 for Power");
	printf("         %u : %s\n", 2, "Press 2 for Square root");
	printf("\n\n");
}

void displayLogFileMenu(void)
{
	/* Print header of menu */
	printHeader();

	/* Print options for log file management */
	printf("         %u : %s\n", 1, "Read Log File");
	printf("         %u : %s\n", 2, "Get the Last Operation Result Value");
	printf("         %u : %s\n", 3, "Clear Log File");
	printf("\n\n");
}

void printPauseMsg(void)
{
	/* Print pause message */
	printf("\nPress any key to continue ...\n");
	(void)_getch();
}

void printInvalidError(int max)
{
	/* Print error message for invalid input */
	printf("\n\n[ERROR] Invalid input. "
		   "You should enter a number between 1 and %d.\n", max);
}

void printLastOpResult(double last_oper_val)
{
	/* Print last operation result value */
	printf("\n\n------------------- Message --------------------\n");
	printf("\n>> The last operation result value is: %lf\n\n", last_oper_val);
	printf("\n------------------------------------------------\n");
}
