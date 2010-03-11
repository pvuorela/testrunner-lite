/* * This file is part of testrunner-lite *
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * Contact: 
 *
 * This software, including documentation, is protected by copyright
 * controlled by Nokia Corporation. All rights are reserved. Copying,
 * including reproducing, storing, adapting or translating, any or all of
 * this material requires the prior written consent of Nokia Corporation.
 * This material also contains confidential information which may not be
 * disclosed to others without the prior written consent of Nokia.
 *
 */

/* ------------------------------------------------------------------------- */
/* INCLUDE FILES */
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdarg.h>

#include "log.h"

/* ------------------------------------------------------------------------- */
/* EXTERNAL DATA STRUCTURES */
/* None */

/* ------------------------------------------------------------------------- */
/* EXTERNAL GLOBAL VARIABLES */
/* None */

/* ------------------------------------------------------------------------- */
/* EXTERNAL FUNCTION PROTOTYPES */
/* None */

/* ------------------------------------------------------------------------- */
/* GLOBAL VARIABLES */
/* None */

/* ------------------------------------------------------------------------- */
/* CONSTANTS */
/* None */


/* ------------------------------------------------------------------------- */
/* MACROS */
/* None */

/* ------------------------------------------------------------------------- */
/* LOCAL GLOBAL VARIABLES */
/* None */

/* ------------------------------------------------------------------------- */
/* LOCAL CONSTANTS AND MACROS */

/* Match these to log.h log_message_types */
const char *stream_names[] = {"ERROR", "INFO", "DEBUG", "UNKNOWN" };

/* ------------------------------------------------------------------------- */
/* MODULE DATA STRUCTURES */
static int verbosity_level = 0;

/* None */

/* ------------------------------------------------------------------------- */
/* LOCAL FUNCTION PROTOTYPES */
/* ------------------------------------------------------------------------- */
/* None */

/* ------------------------------------------------------------------------- */
/* FORWARD DECLARATIONS */
/* None */

/* ------------------------------------------------------------------------- */
/* ==================== LOCAL FUNCTIONS ==================================== */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* None */

/* ------------------------------------------------------------------------- */
/* ======================== FUNCTIONS ====================================== */
/* ------------------------------------------------------------------------- */ 

/** Prints a log message to stdout in format "[LOG_TYPE] HH:MM:SS message"
 *  Usage is the same as in regular printf(), except the first parameter
 *  Example: log_msg (LOG_ERR, "Error message %s\n", "Failure");
 * @param type Log type defined in log_message_types enum
 * @param format Message format
 */
void log_msg (int type, char *format, ...) {
	
	/* Check if message should be printed */
	if (type > verbosity_level) {
		/* Do nothing */
		return;
	} 

	/* In testrunner.py all debug is going to stdout, also errors */

	/* Log name */
	const char *stream_name;
	if (type >= 0 && type < LOG_TYPES_COUNT) {
		stream_name = stream_names[type];
	} else {
		/* Should not happen */
		stream_name = stream_names[LOG_TYPES_COUNT];
	}

	/* Current timestamp */
	char timestamp[10];
	struct tm *tm;
	time_t current_time;
	time (&current_time);
	tm = localtime (&current_time);
	strftime (timestamp, sizeof (timestamp), "%H:%M:%S", tm);
	
	fprintf (stdout, "[%s] %s ", stream_name, timestamp);

	/* Print given arguments */
	va_list args;
	va_start (args, format);
	vfprintf (stdout, format, args);
	va_end (args);

	fprintf (stdout, "\n");

}

/* ------------------------------------------------------------------------- */
/** Sets the verbosity level
 * @param level Verbosity level
 */
void log_set_verbosity_level (int level) {
	if (level >= 0 && level < LOG_TYPES_COUNT) {
		verbosity_level = level;
	} else {
		log_msg (LOG_ERROR, 
			"Incorrect verbosity level %d, values [0..%d]\n", 
			level, LOG_TYPES_COUNT - 1);
	}
}


/* ================= OTHER EXPORTED FUNCTIONS ============================== */
/* None */

/* ------------------------------------------------------------------------- */
/* End of file */
