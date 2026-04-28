#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } boolean;

extern int numdefaults;
extern int myargc;
extern char** myargv;
extern char* defaultfile;
extern char* basedefault;

typedef struct default_t {
    char* name;
    int* location;
    int defaultvalue;
    boolean scantranslate;
    int untranslated;
} default_t;

extern default_t defaults[100];  // 假设有100个默认值
extern int scantokey[256];  // 假设扫描码转换表有256个条目

int M_CheckParm(char* check);