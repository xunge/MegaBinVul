#include <string.h>
#include <stdio.h>

#define __init
#define LOCKDOWN_ACPI_TABLES 0

static char efivar_ssdt[256];

int security_locked_down(int);
void pr_warn(const char*, ...);