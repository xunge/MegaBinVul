#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

extern int exit_immediately_on_error;
extern int last_command_exit_value;

void error_prolog(int);
void exit_shell(int);

#if !defined(PREFER_STDARG)
#define va_dcl
#define SH_VA_START(ap, fmt) (void)(0)
#endif