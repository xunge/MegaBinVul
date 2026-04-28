#include <stdio.h>
#include <string.h>

typedef int Jsi_RC;
#define JSI_OK 0

typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;

typedef struct Jsi_Interp {
    int isSafe;
    Jsi_Value *stdinStr;
} Jsi_Interp;

static int Jsi_LogError(const char *msg);
static char* jsi_RlGetLine(Jsi_Interp *interp, const char *prompt);
static int Jsi_ValueIsNull(Jsi_Interp *interp, Jsi_Value *value);
static char* Jsi_ValueString(Jsi_Interp *interp, Jsi_Value *value, int *lenPtr);
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *array, int index);
static void Jsi_ValueMakeString(Jsi_Interp *interp, Jsi_Value **ret, const char *str);
static void Jsi_ValueMakeStringDup(Jsi_Interp *interp, Jsi_Value **ret, const char *str);
static void Jsi_ValueMakeUndef(Jsi_Interp *interp, Jsi_Value **ret);
static char* Jsi_Strchr(const char *str, int ch);
static size_t Jsi_Strlen(const char *str);
static char* Jsi_Strncpy(char *dest, const char *src, size_t n);