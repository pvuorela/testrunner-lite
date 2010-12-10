/*
 * This file is part of testrunner-lite
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: Sampo Saaristo <sampo.saaristo@sofica.fi>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef TESTRUNNERLITE_H
#define TESTRUNNERLITE_H

/* ------------------------------------------------------------------------- */
/* INCLUDES */
/* None */

/* ------------------------------------------------------------------------- */
/* CONSTANTS */
/* None */

/* ------------------------------------------------------------------------- */
/* MACROS */
#define LOCAL static
#define PROGNAME "testrunner-lite"
/* ------------------------------------------------------------------------- */
/* DATA TYPES */
/* ------------------------------------------------------------------------- */
/** Result output type */
typedef enum {
	OUTPUT_TYPE_XML = 1,
	OUTPUT_TYPE_TXT 
} result_output;

/** testrunner-lite exit codes */
typedef enum {
	TESTRUNNER_LITE_OK = 0,
	TESTRUNNER_LITE_INVALID_ARGUMENTS,
	TESTRUNNER_LITE_SSH_FAIL,
	TESTRUNNER_LITE_XML_PARSE_FAIL,
	TESTRUNNER_LITE_XML_VALIDATION_FAIL,
	TESTRUNNER_LITE_OUTPUT_FOLDER_CREATE_FAIL,
	TESTRUNNER_LITE_XML_READER_FAIL,
	TESTRUNNER_LITE_RESULT_LOGGING_FAIL
} testrunner_lite_return_code;

/** Used for storing and passing user (command line) options.*/
typedef struct {
	char *input_filename;  /**< the input xml file */
	char *output_filename; /**< the result file */
	char *output_folder;   /**< folder for storing results */
	char *environment;     /**< execution environment */
	char *remote_logger;     /**< Remote logger URL */
	long  remote_logger_port; /** Remote logger port number */
	int   syslog_output;   /**< flag for syslog */
	int   disable_schema;  /**< flag for disabling DTD validation */
	int   semantic_schema; /**< flag for enabling sricter DTD */
	int   print_step_output; /**< enable logging of step std streams */
	result_output   output_type;   /**< result output type selector */
	int   run_automatic;   /**< flag for automatic tests */  
	int   run_manual;      /**< flag for manual tests */
	int   skip_hwinfo;     /**< flag for skipping hwinfo step */
	int   log_level;       /**< logging level */
	char *target_address;   /**< SUT address. */
} testrunner_lite_options;    
/* ------------------------------------------------------------------------- */
/* FORWARD DECLARATIONS */
/* None */

/* ------------------------------------------------------------------------- */
/* STRUCTURES */
/* None */

/* ------------------------------------------------------------------------- */
/* FUNCTION PROTOTYPES */
/* None */

/* ------------------------------------------------------------------------- */
#endif                          /* TESTRUNNERLITE_H */
/* End of file */
