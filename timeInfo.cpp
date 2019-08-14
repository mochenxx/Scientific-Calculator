/*
 *  File name: timeInfo.cpp
 *
 *  Author: Mo Chen
 *
 *  Description: cpp file for getting time information
 */

#include <time.h>
#include "timeInfo.h"

 /*
  * Disable warning of unsafe functions
  * _CRT_SECURE_NO_WARNINGS
  */
#pragma warning(disable : 4996)

char* getLocalTime(void)
{
	time_t curtime;			// Current time
	struct tm* localTime;	// Local time struct

	/* Get current time to local time */
	curtime = time(NULL);

	/* Convert current time to local time */
	localTime = localtime(&curtime);

	/* Convert tm structure to string and return it */
	return asctime(localTime);
}

char* getTimeString(time_t time_val)
{
	struct tm *tm_time = localtime(&time_val);		// Local time struct

	/* Convert tm structure to string and return it */
	return asctime(tm_time);
}
