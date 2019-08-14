/*
 *  File name: LogFile.cpp
 *
 *  Author: Mo Chen
 *
 *  Description: cpp file for keeping logs of various operations
 */

#include "LogFile.h"
#include "print.h"
#include "timeInfo.h"  

/*
 * Disable warning of unsafe functions
 * _CRT_SECURE_NO_WARNINGS
 */
#pragma warning(disable : 4996)

void writeToLogFile(double result, operation operation)
{
	FILE* fp;
	logFileRecord new_record = { 0 };
	size_t ret_val;		// Return value from fwrite()

	/* Store records information to struct new_record */
	new_record.operation = operation;	// record operation type
	new_record.time = time(NULL);		// record time info
	new_record.result = result;			// record result

	fp = fopen(FILENAME, "ab");			// append binary file mode
	
	/* Check if file cannot be opened */
	if (NULL == fp) {
		/* Print error message and then exit */
		printf("\n\n[ERROR] Could not open file!\n");
		exit(1);
	}

	/* Write record information to log file */
	ret_val = fwrite(&new_record, sizeof(new_record), 1, fp);

	/* Check if return value is zero */
	if (0 == ret_val) {
		/* Print error message and then exit */
		printf("\n\n[ERROR] Could not write to file!\n");
		exit(1);
	}

	fclose(fp);
}

void readLogFile(void)
{
	logFileRecord new_record = { 0 };
	FILE *fp = fopen(FILENAME, "rb");		// Open file with read binary mode

	/* Check if file can be opended */
    if(fp == NULL) {
		// Display error message
        perror("\n\n[ERROR]Unable to open file!");

		// Program exits when encountering an error
		exit(1);
    }

	/* Read log file records and display them */
	printf("\n\nRecords from Log File: \n\n");
	while (fread(&new_record, sizeof(new_record), 1, fp)) {

		printf("\nTime: %sOperation: %s\nResult: %lf\n",
			getTimeString(new_record.time), 
			operation_strings[new_record.operation], new_record.result);
	}
 
    fclose(fp);
}

double getLastOpResult(void)
{
	logFileRecord last_record = { 0 };
	signed long long int offset;
	double last_oper_val = 0;
	FILE* fp;

	fp = fopen(FILENAME, "rb");		// Open file in read mode
	
	/* Check if file can be opended */
	if (NULL == fp) {
		// Display error message
		perror("\n\n[ERROR] Could not open log file!");

		// Program exits when encountering an error
		exit(1);
	}

	/* Print header information */
	printf("\n\n");
	printf("------------ Last Operation Record in Log File ---------------\n");
	offset = sizeof(last_record);

	/* Moving file pointer to end */
	fseek(fp, -(offset), SEEK_END);

	/* Print last operation record from log file */
	while (fread(&last_record, sizeof(last_record), 1, fp)) {
		last_oper_val = last_record.result;
		printf("\nTime: %sOperation: %s\nResult: %lf\n\n", 
				getTimeString(last_record.time), 
				operation_strings[last_record.operation], 
				last_record.result);
	}

	fclose(fp);

	/* Return last operation result value */
	return last_oper_val;
}

void clearLogFile(void)
{
	fclose(fopen(FILENAME, "wb"));

	/* Print success message for clearing log file */
	printf("\n\nYou've successfully clear the log file!\n\n");
}

double chooseLogFile(char choice, unsigned char use_last_operation_value)
{
	double last_oper_val = 0;
	switch (choice)
	{
		// Read and Disaplay Log File
		case '1':
		{
			/* Read and Disaplay Log File */
			readLogFile();

			/* Set flag to 0 for not using last operation value */
			use_last_operation_value = 0;

			/* Print pause message */
			printPauseMsg();

			break;
		}

		// Get the last operation result value
		case '2':
		{
			/* Store result of subtraction */
			last_oper_val = getLastOpResult();

			/* Set flag to 1 for using last operation value */
			use_last_operation_value = 1;

			/* Print pause message */
			printPauseMsg();

			break;
		}

		// Clear Log File
		case '3':
		{
			/* Clear Log File */
			clearLogFile();

			/* Set flag to 0 for not using last operation value */
			use_last_operation_value = 0;

			/* Print pause message */
			printPauseMsg();

			break;
		}

		default:
		{
			/* Print error message for invalid input */
			printInvalidError(3);

			/* Set flag to 0 for not using last operation value */
			use_last_operation_value = 0;

			/* Print pause message */
			printPauseMsg();

			break;
		}
	}	// End of inner switch

	return last_oper_val;
}

void checkLastOpResult(double last_oper_val,
					   unsigned char use_last_operation_value)
{
	/* Check if user wants to use last operation result value */
	if ( 1 == use_last_operation_value)
	{
		/* Print the last operation result vaule */
		printLastOpResult(last_oper_val);
	}
}