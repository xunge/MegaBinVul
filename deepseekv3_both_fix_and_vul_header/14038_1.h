#include <stdint.h>
#include <stddef.h>

typedef uint32_t UINT32;
typedef uint8_t UINT8;

typedef int ACPI_STATUS;
#define AE_OK 0
#define AE_BAD_DATA 1
#define ACPI_FAILURE(status) (status != AE_OK)

#define ACPI_OBJ_NUM_OPERANDS 8
#define ACPI_DB_DISPATCH 0

#define ACPI_FUNCTION_TRACE_PTR(func, ptr)
#define return_ACPI_STATUS(status) return (status)
#define ACPI_DEBUG_PRINT(level)
#define ACPI_EXCEPTION(info)

typedef struct ACPI_COMMON_OBJECT {
    struct ACPI_PARSE_OBJECT *Next;
} ACPI_COMMON_OBJECT;

typedef struct ACPI_PARSE_OBJECT {
    ACPI_COMMON_OBJECT Common;
} ACPI_PARSE_OBJECT;

typedef struct ACPI_WALK_STATE {
    UINT32 NumOperands;
    void *Operands[ACPI_OBJ_NUM_OPERANDS];
    UINT8 OperandIndex;
} ACPI_WALK_STATE;

ACPI_STATUS AcpiDsCreateOperand(ACPI_WALK_STATE *WalkState, ACPI_PARSE_OBJECT *Arg, UINT32 Index);
void AcpiDsObjStackPopAndDelete(UINT32 Count, ACPI_WALK_STATE *WalkState);