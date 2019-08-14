/*
 *  File name: LogFile.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for keeping logs of operations
 */

#ifndef _LOGFILE_H_
#define _LOGFILE_H_

#include <time.h>
#define FILENAME "LogFile.dat"

/* Enumerate Avaiable Operation Types for Calculator */
typedef enum {
	OPERATION_NONE = 0,
	OPERATION_ARITHMETIC,
	OPERATION_TRIG,
	OPERATION_LOG,
	OPERATION_POWER,
	OPERATION_FACTORIAL,
	OPERATION_LOG_FILE,
	OPERATION_SOFTWARE_INFO,
	OPERATION_EXIT,
	OPERATION_MAX
} operation;

/* Define operation strings and set indexes with corresponding types */
static const char* operation_strings[] = {
	"OPERATION_NONE",
	"OPERATION_ARITHMETIC",
	"OPERATION_TRIG",
	"OPERATION_LOG",
	"OPERATION_POWER",
	"OPERATION_FACTORIAL",
	"OPERATION_LOG_FILE",
	"OPERATION_SOFTWARE_INFO",
	"OPERATION_EXIT",
	"OPERATION_MAX"
};

/* Define Log File Record struct */
typedef struct {
	time_t time;			// Related time
	double result;			// Record result value
	operation operation;	// Operation type
} logFileRecord;

/*
 * This function writes operatin result and type to log file
 * in order to keep logs of operations.
 *
 * @param[in] result - result of operation from a user
 * @param[in] operation - operation type of corresponding result
 *
 * @returns - nothing
 */
void writeToLogFile(double result, operation operation);

/*
 * This function reads the content of the log file
 * and display them in screen
 *
 * @returns - nothing
 */
void readLogFile(void);

/*
 * This function clear the whole content of log file
 *
 * @returns - nothing
 */
void clearLogFile(void);

/*
 * This function choose and achieve one of log file options
 *
 * It includes three switch sections:
 *    '1' - Read and Disaplay Log File
 *    '2' - Get the last operation result value
 *    '3' - Clear Log File
 *
 * @param[in] choice - Input choice of option
 * @param[in] last_op_val - the last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - the result of selected option
 */
double chooseLogFile(char choice, unsigned char use_last_operation_value);

/*
 * This function gets the last operation result value
 *
 * @returns - the last operation result value
 */
double getLastOpResult(void);

/*
 * This function checks if user has got the last operation result value
 * from the log file and wants to continue using it
 *
 * @param[in] last_oper_val - the last operation result value
 * @param[in] use_last_operation_value - flag used to determine whether to
 *			  use last operation value or not (1 - use / 0 - not use)
 *
 * @returns - nothing
 */
void checkLastOpResult(double last_oper_val,
	                   unsigned char use_last_operation_value);
#endif // !_LOGFILE_H_