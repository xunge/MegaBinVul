#include <ctype.h>

#define FALSE 0
#define TRUE 1

typedef int OFF;
typedef struct MD_CTX MD_CTX;
typedef char CHAR;

#define ISALPHA_(c) isalpha((unsigned char)(c))
#define ISALNUM_(c) isalnum((unsigned char)(c))