#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MS_FALSE 0
#define MS_TRUE 1
#define MS_MISCERR 1
#define MS_EXPRESSION 1

typedef struct {
    int type;
    char *string;
} expressionObj;

typedef struct {
    char *filteritem;
    expressionObj filter;
} layerObj;

extern size_t strlcat(char *dst, const char *src, size_t size);
void msSetError(int code, const char *message, const char *function);
char **msStringSplit(const char *string, char delimiter, int *numtokens);
void msFreeCharArray(char **array, int numelements);
char *msStrdup(const char *string);
void createPostgresTimeCompareSimple(const char *timefield, const char *timestring, char *buffer, size_t buffer_size);
void createPostgresTimeCompareRange(const char *timefield, const char *starttime, const char *endtime, char *buffer, size_t buffer_size);
void loadExpressionString(expressionObj *expr, const char *string);
void freeExpression(expressionObj *expr);