#include <assert.h>
#include <errno.h>
#include <stddef.h>

#define MagickPrivate static
typedef unsigned int MagickBooleanType;
typedef void *ModuleHandle;
typedef void *lt_dlhandle;
typedef unsigned long size_t;

#define MagickTrue 1
#define MagickFalse 0
#define MagickPathExtent 4096
#define MagickImageCoderSignature 0xabacadabUL
#define MagickImageCoderModule 0xabacadabUL
#define EPERM 1

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _ModuleInfo {
    ModuleHandle handle;
    size_t (*register_module)(void);
    void (*unregister_module)(void);
} ModuleInfo;
typedef struct _CoderInfo {
    char *name;
} CoderInfo;
typedef int PolicyRights;

enum {
    ModulePolicyDomain,
    PolicyError,
    ModuleError,
    ImageCoderSignatureMismatch,
    UnableToLoadModule,
    UnableToRegisterImageFormat,
    NotAuthorized
};

enum {
    ModuleEvent,
    ReadPolicyRights = 1,
    WritePolicyRights = 2,
    AllPolicyRights = (ReadPolicyRights|WritePolicyRights)
};

extern ModuleInfo *GetModuleInfo(const char *, ExceptionInfo *);
extern const CoderInfo *GetCoderInfo(const char *, ExceptionInfo *);
extern MagickBooleanType IsRightsAuthorized(int, PolicyRights, const char *);
extern void *GetValueFromSplayTree(void *, const char *);
extern void TagToCoderModuleName(const char *, char *);
extern void TagToModuleName(const char *, const char *, char *);
extern void *lt_dlopen(const char *);
extern char *lt_dlerror(void);
extern void *lt_dlsym(lt_dlhandle, const char *);
extern ModuleInfo *AcquireModuleInfo(const char *, const char *);
extern ModuleInfo *RegisterModule(ModuleInfo *, ExceptionInfo *);
extern void *module_list;
extern char *GetMagickModule(void);
extern void LogMagickEvent(int, const char *, const char *, ...);
extern void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
extern MagickBooleanType GetMagickModulePath(const char *, unsigned long, char *, ExceptionInfo *);
extern void CopyMagickString(char *, const char *, size_t);