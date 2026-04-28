#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define TNEF_SIGNATURE 0x223E9F78
#define SAVEBODY 0x01

typedef uint32_t uint32;
typedef uint16_t uint16;

typedef struct Attr {
    int name;
    int lvl_type;
    size_t len;
    void *buf;
} Attr;

typedef struct File {
    // File structure members
} File;

typedef struct MAPI_Attr {
    int type;
    int name;
    int num_values;
    // Other MAPI_Attr members
} MAPI_Attr;

typedef struct MessageBody {
    char **text_body;
    char **html_bodies;
    char **rtf_bodies;
} MessageBody;

extern int g_flags;

uint32_t geti32(FILE*);
uint16_t geti16(FILE*);
void debug_print(const char*, ...);
int data_left(FILE*);
Attr* read_object(FILE*);
void file_write(File*, char*);
void file_free(File*);
void* CHECKED_XCALLOC(size_t, size_t);
char** get_text_data(Attr*);
MAPI_Attr** mapi_attr_read(size_t, void*);
char** get_html_data(MAPI_Attr*);
char** get_rtf_data(MAPI_Attr*);
void mapi_attr_free_list(MAPI_Attr**);
void XFREE(void*);
void attr_free(Attr*);
void file_add_attr(File*, Attr*);
File** get_body_files(char*, char, MessageBody*);
void free_bodies(char**, int);

enum {
    attATTACHRENDDATA,
    attBODY,
    attMAPIPROPS,
    MAPI_BODY_HTML,
    MAPI_RTF_COMPRESSED,
    szMAPI_BINARY
};

enum {
    LVL_MESSAGE,
    LVL_ATTACHMENT
};

#define CHECKED_XCALLOC(type, count) (type*)calloc(count, sizeof(type))