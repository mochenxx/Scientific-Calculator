/*
 *  File name: timeInfo.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for time information
 */

#ifndef _TIMEINFO_H_
#define _TIMEINFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

/*
 * This function returns the local time string
 *
 * @returns - local time string
 */
char* getLocalTime(void);

/*
 * This function converts the time_t variable into a string
 *
 * @param[in] time_val - time value in time_t type
 *
 * @returns - time value stored in a string
 */
char* getTimeString(time_t time_val);
#endif // !_TIMEINFO_H_
