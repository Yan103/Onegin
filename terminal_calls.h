/*!
    \file
    File with the terminal calls text
*/

#ifndef TERMINAL_CALLS_H
#define TERMINAL_CALLS_H

#include <stdio.h>

/// Name of default test file
const char*  FILE_INPUT_NAME = "text.txt";
const char* FILE_OUTPUT_NAME = "sorted_text.txt";

/// Cute cat picture
const char* CAT  = " /\\..../\\\n"
                   "(.'*..*'.)   \033[35mMEOW :3\033[0m\n"
                   " .==**==. \n"
                   "(.\\.||./.)~~^^\n";

/// Help test
const char* HELP_TEXT  = "-c secret command for DED\n"
                         "-h calls the help commands\n"
                         "-f {file name} starts the sort mode (by reading data from a file). "
                         "If If you did not transfer the file, then the standard one (text.txt) is used\n"
                         "if you do not specify parameters, then -f will be used by default\n";

#endif // TERMINAL_CALLS_H