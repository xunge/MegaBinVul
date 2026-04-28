#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#ifndef MAX_PATH
#define MAX_PATH 260
#endif