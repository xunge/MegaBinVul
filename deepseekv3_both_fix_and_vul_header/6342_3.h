#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <sys/types.h>

#define MagickPathExtent 4096
#define MagickFalse 0
#define MagickTrue 1
#define MagickExport
#define PolicyError 1

typedef int MagickBooleanType;
typedef unsigned int PolicyRights;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _CoderInfo {
    const char *name;
} CoderInfo;

typedef struct {
    const char *module;
    MagickBooleanType registered;
    void (*register_module)(void);
} ModuleInfo;

ModuleInfo MagickModules[] = {
    {NULL, MagickFalse, NULL}
};

extern PolicyRights AllPolicyRights;
extern PolicyRights ReadPolicyRights;
extern const char *ModulePolicyDomain;

extern void CopyMagickString(char *destination, const char *source, size_t length);
extern const CoderInfo *GetCoderInfo(const char *module, ExceptionInfo *exception);
extern MagickBooleanType IsRightsAuthorized(const char *domain, PolicyRights rights, const char *name);
extern void *ThrowMagickException(ExceptionInfo *exception, const char *module, int error, const char *reason, const char *description, ...);
extern const char *GetMagickModule(void);
extern int LocaleCompare(const char *p, const char *q);