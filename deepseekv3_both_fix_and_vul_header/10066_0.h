#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct FilterEncodingNode {
    void *pOther;
    struct FilterEncodingNode *psLeftNode;
    struct FilterEncodingNode *psRightNode;
    char *pszValue;
} FilterEncodingNode;

typedef struct FEPropertyIsLike {
    char *pszWildCard;
    char *pszSingleChar;
    char *pszEscapeChar;
    int bCaseInsensitive;
} FEPropertyIsLike;

char *msStrdup(const char *str);