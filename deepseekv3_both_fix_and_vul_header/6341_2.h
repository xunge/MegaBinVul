#include <stddef.h>
#include <sys/types.h>

#define MagickExport

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

typedef enum {
    ReadPolicyRights,
    WritePolicyRights,
    AllPolicyRights
} PolicyRights;

typedef enum {
    ModulePolicyDomain
} PolicyDomain;

typedef struct {
    const char *module;
    void (*register_module)(void);
    MagickBooleanType registered;
} MagickModule;

MagickModule MagickModules[] = {
    {"module1", NULL, MagickFalse},
    {"module2", NULL, MagickFalse}
};

MagickBooleanType IsRightsAuthorized(PolicyDomain domain, PolicyRights rights, const char *module);