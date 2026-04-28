#include <stdint.h>
#include <string.h>

#define NUL '\0'
#define FALSE 0
#define TRUE 1
#define MAX_FUZZY_MATCHES 256
#define FUZZY_MATCH_RECURSION_LIMIT 10

typedef uint8_t char_u;
typedef uint32_t int_u;

static int vim_tolower(int c);
static int fuzzy_match_compute_score(char_u *strBegin, int strLen, int_u *matches, int nextMatch);
static int has_mbyte;
static int (*mb_ptr2len)(char_u *);
static void MB_PTR_ADV(char_u *);
#define PTR2CHAR(p) (*(p))
#define ARRAY_LENGTH(arr) (sizeof(arr)/sizeof((arr)[0]))