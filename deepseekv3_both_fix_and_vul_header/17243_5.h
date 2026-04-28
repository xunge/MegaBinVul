#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GUIDSTR_LEN 33
#define IMAGE_DEBUG_TYPE_CODEVIEW 2
#define SIZEOF_FILE_NAME 255

typedef unsigned char ut8;

typedef struct PE_r_bin_pe_obj_t PE_r_bin_pe_obj_t;
typedef struct PE_image_debug_directory_entry {
    int Type;
} PE_image_debug_directory_entry;

typedef struct {
    unsigned int data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
} GUID;

typedef struct SCV_RSDS_HEADER {
    GUID guid;
    unsigned int age;
    char* file_name;
    void (*free)(struct SCV_RSDS_HEADER*);
} SCV_RSDS_HEADER;

typedef struct SCV_NB10_HEADER {
    unsigned int timestamp;
    unsigned int age;
    char* file_name;
    void (*free)(struct SCV_NB10_HEADER*);
} SCV_NB10_HEADER;

typedef struct {
    char guidstr[GUIDSTR_LEN];
    char file_name[SIZEOF_FILE_NAME];
} SDebugInfo;

#define PE_(x) PE_##x