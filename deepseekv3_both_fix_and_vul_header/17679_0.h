#include <stdlib.h>

typedef unsigned int UINT;

typedef struct _CLIPRDR_FORMAT
{
	char* formatName;
} CLIPRDR_FORMAT;

typedef struct _CLIPRDR_FORMAT_LIST
{
	UINT numFormats;
	CLIPRDR_FORMAT* formats;
} CLIPRDR_FORMAT_LIST;