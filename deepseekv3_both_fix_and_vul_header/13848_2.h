#include <stddef.h>

#define ACPI_EXEC_APP
#define ACPI_DEBUG_OUTPUT
#define ACPI_DB_INFO 0
#define ACPI_MTX_NAMESPACE 0
#define ACPI_FUNCTION_TRACE(x)
#define return_VOID return

typedef int ACPI_STATUS;

struct ACPI_OPERAND_OBJECT {
    struct {
        void *Mutex;
    } Method;
};

typedef struct ACPI_OPERAND_OBJECT ACPI_OPERAND_OBJECT;

extern ACPI_OPERAND_OBJECT *AcpiGbl_ModuleCodeList;
extern void *AcpiGbl_RootNode;

void AcpiUtRemoveReference(ACPI_OPERAND_OBJECT *);
void AcpiNsDeleteNamespaceSubtree(void *);
ACPI_STATUS AcpiUtAcquireMutex(int);
void AcpiNsDeleteNode(void *);
ACPI_STATUS AcpiUtReleaseMutex(int);
void ACPI_DEBUG_PRINT(int level, const char *format);
#define ACPI_DEBUG_PRINT(args) ACPI_DEBUG_PRINT args
int ACPI_FAILURE(ACPI_STATUS status);