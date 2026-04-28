#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

extern "C" {
void* bstrrstr(const char* s1, int len1, const char* s2, int len2);
void* bstrrcasestr(const char* s1, int len1, const char* s2, int len2);
}

#define assertx(expr) ((void)0)