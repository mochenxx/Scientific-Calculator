/*
 *  File name: print.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for printing various menu and messages
 */

#ifndef _PRINT_H_
#define _PRINT_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

 /*
  * This function returns the choice from a user
  *
  * @returns - the choice string from the keyboard
  */
char getChoice(void);

/*
 * This function displays the header for menu
 */
void printHeader(void);

/*
 * This function displays the menu of the calculator
 */
void displayMainMenu(void);

/*
 * This function displays options for arithemtic operations
 *
 * It includes four switch sections:
 * 		'1' - Addtion
 * 		'2' - Subtraction
 * 		'3' - Multiplication
 * 		'4' - Division
 */
void displayArithMenu(void);

/*
 * This function displays options for trigonometric functions
 * and returns the choice provided by the user input
 *
 * It includes three switch sections:
 *		'1' - Sin() Function
 *	    '2' - Cos() Function
 *      '3' - Tan() Function
 */
void displayTrigMenu(void);

/*
 * This function displays options for logarithmic operations
 *
 * It includes three switch sections:
 *		'1' - Natural log
 * 		'2' - Log with base 10
 * 		'3' - Log with base N
 */
void displayLogMenu(void);

/*
 * This function displays options for power operations
 *
 * It includes two switch sections:
 * 		'1' - Power function
 * 		'2' - Square root
 */
void displayPowerMenu(void);

/*
 * This function displays options for log file operations
 *
 * It includes three switch sections:
 * 		'1' - Read and Disaplay Log File
 * 		'2' - Get the last operation result value
 *		'3' - Clear Log File
 */
void displayLogFileMenu(void);

/*
 * This function displays software information
 */
void displaySoftwareInfo(void);

/*
 * This function prints pause message between each operation
 */
void printPauseMsg(void);

/*
 * This function prints error message for invalid input
 * when choosing the operation
 *
 * @param[in] max - maximum number of options for certain operation
 */
void printInvalidError(int max);

/*
 * This function print the last operation result value.
 *
 * @param[in] last_oper_val - last operation result value
 *
 * @returns - nothing
 */
void printLastOpResult(double last_oper_val);
#endif // !_PRINT_H_