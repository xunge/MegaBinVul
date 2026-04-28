#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <sys/types.h>

#define MagickExport
#define PolicyError 1

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _CoderInfo {
    const char *name;
} CoderInfo;

typedef enum {
    ReadPolicyRights = 1,
    WritePolicyRights = 2,
    AllPolicyRights = ReadPolicyRights | WritePolicyRights
} PolicyRights;

typedef enum {
    ModulePolicyDomain
} PolicyDomain;

#define MagickPathExtent 4096

typedef struct {
    const char *module;
    MagickBooleanType (*register_module)(void);
    MagickBooleanType registered;
} ModuleInfo;

extern ModuleInfo MagickModules[1];
extern const char *GetMagickModule(void);
extern const CoderInfo *GetCoderInfo(const char *, ExceptionInfo *);
extern MagickBooleanType IsRightsAuthorized(PolicyDomain, PolicyRights, const char *);
extern void *CopyMagickString(char *, const char *, size_t);
extern void *ThrowMagickException(ExceptionInfo *, const char *, size_t, const char *, const char *, ...);
extern int LocaleCompare(const char *, const char *);