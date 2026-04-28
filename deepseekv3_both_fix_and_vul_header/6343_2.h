#include <stddef.h>
#include <sys/types.h>

#define MagickExport

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

typedef enum {
    ModulePolicyDomain
} PolicyDomain;

typedef enum {
    AllPolicyRights
} PolicyRights;

typedef struct {
    const char *module;
    MagickBooleanType (*register_module)(void);
    MagickBooleanType registered;
} ModuleInfo;

ModuleInfo MagickModules[] = {
    {NULL, NULL, MagickFalse}
};

MagickBooleanType IsRightsAuthorized(PolicyDomain domain, PolicyRights rights, const char *module);