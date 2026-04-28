#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long ACPI_STATUS;
#define AE_OK 0
#define AE_BAD_PARAMETER 1
#define AE_NO_MEMORY 2
#define AE_TYPE 3
#define AE_NULL_OBJECT 4
#define AE_CTRL_RETURN_VALUE 5
#define ACPI_FAILURE(status) (status != AE_OK)

#define ACPI_NS_NO_UPSEARCH 0
#define ACPI_METHOD_NUM_ARGS 7
#define ACPI_WARN_ALWAYS 0
#define ACPI_DB_NAMES 0
#define ACPI_DB_EXEC 0
#define ACPI_IGNORE_RETURN_VALUE (1 << 0)
#define TRUE true
#define FALSE false

#define ACPI_FUNCTION_TRACE(f)
#define return_ACPI_STATUS(s) return (s)
#define ACPI_DEBUG_PRINT(args)
#define ACPI_WARN_PREDEFINED(args)
#define ACPI_ERROR(args)
#define ACPI_FREE(ptr) free(ptr)
#define ACPI_CAST_PTR(type, ptr) ((type *)(ptr))
#define ACPI_CAST_INDIRECT_PTR(type, ptr) ((type **)(ptr))

typedef struct ACPI_NAMESPACE_NODE ACPI_NAMESPACE_NODE;
typedef struct ACPI_OPERAND_OBJECT ACPI_OPERAND_OBJECT;

struct ACPI_NAMESPACE_NODE {
    unsigned char Type;
    unsigned short Flags;
    union {
        char Ascii[4];
    } Name;
    void *Object;
};

struct ACPI_OPERAND_OBJECT {
    unsigned char Type;
    struct {
        void *AmlStart;
        unsigned long AmlLength;
    } Method;
};

typedef struct ACPI_EVALUATE_INFO {
    ACPI_NAMESPACE_NODE *Node;
    ACPI_NAMESPACE_NODE *PrefixNode;
    char *RelativePathname;
    ACPI_OPERAND_OBJECT *ReturnObject;
    unsigned short NodeFlags;
    ACPI_OPERAND_OBJECT *ObjDesc;
    void *Predefined;
    char *FullPathname;
    void **Parameters;
    unsigned int ParamCount;
    unsigned int Flags;
} ACPI_EVALUATE_INFO;

#define ACPI_TYPE_DEVICE 1
#define ACPI_TYPE_EVENT 2
#define ACPI_TYPE_MUTEX 3
#define ACPI_TYPE_REGION 4
#define ACPI_TYPE_THERMAL 5
#define ACPI_TYPE_LOCAL_SCOPE 6
#define ACPI_TYPE_METHOD 7
#define ACPI_TYPE_LOCAL_METHOD_ALIAS 8

ACPI_STATUS AcpiNsGetNode(ACPI_NAMESPACE_NODE *prefix_node, char *pathname, 
                         unsigned int flags, ACPI_NAMESPACE_NODE **return_node);
unsigned char AcpiNsGetType(ACPI_NAMESPACE_NODE *node);
ACPI_OPERAND_OBJECT *AcpiNsGetAttachedObject(ACPI_NAMESPACE_NODE *node);
void *AcpiUtMatchPredefinedMethod(char *name);
char *AcpiNsGetNormalizedPathname(ACPI_NAMESPACE_NODE *node, bool no_trailing);
void AcpiNsCheckAcpiCompliance(char *pathname, ACPI_NAMESPACE_NODE *node, 
                              void *predefined);
void AcpiNsCheckArgumentCount(char *pathname, ACPI_NAMESPACE_NODE *node, 
                            unsigned int arg_count, void *predefined);
void AcpiNsCheckArgumentTypes(ACPI_EVALUATE_INFO *info);
void AcpiExEnterInterpreter(void);
void AcpiExExitInterpreter(void);
ACPI_STATUS AcpiPsExecuteMethod(ACPI_EVALUATE_INFO *info);
ACPI_STATUS AcpiExResolveNodeToValue(ACPI_NAMESPACE_NODE **node, void *walk_state);
void AcpiUtRemoveReference(ACPI_OPERAND_OBJECT *object);
void AcpiNsCheckReturnValue(ACPI_NAMESPACE_NODE *node, ACPI_EVALUATE_INFO *info, 
                          unsigned int param_count, ACPI_STATUS status, 
                          ACPI_OPERAND_OBJECT **return_object);
char *AcpiUtGetTypeName(unsigned char type);
char *AcpiUtGetObjectTypeName(ACPI_OPERAND_OBJECT *object);