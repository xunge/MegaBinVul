#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef uint32_t ACPI_STATUS;
typedef uint8_t BOOLEAN;

#define TRUE 1
#define FALSE 0

#define AE_OK 0
#define AE_CTRL_PENDING 1
#define AE_CTRL_TERMINATE 2
#define ACPI_FAILURE(Status) ((Status) != AE_OK)
#define ACPI_SUCCESS(Status) ((Status) == AE_OK)

#define ACPI_DB_PARSE 0
#define ACPI_FUNCTION_TRACE_PTR(func, ptr)
#define ACPI_DEBUG_PRINT(...) printf(__VA_ARGS__)

typedef struct ACPI_WALK_STATE {
    void *Op;
    void *OpInfo;
    uint32_t Opcode;
    uint32_t ArgTypes;
    uint32_t ArgCount;
    ACPI_STATUS (*AscendingCallback)(struct ACPI_WALK_STATE*);
    struct {
        void *ParserState;
    };
} ACPI_WALK_STATE;

typedef struct ACPI_PARSE_OBJECT {
    struct {
        uint32_t AmlOpcode;
    } Common;
} ACPI_PARSE_OBJECT;

ACPI_STATUS AcpiPsGetOpcodeInfo(uint32_t opcode);
ACPI_STATUS AcpiPsNextParseState(ACPI_WALK_STATE *WalkState, ACPI_PARSE_OBJECT *Op, ACPI_STATUS Status);
ACPI_STATUS AcpiPsCompleteOp(ACPI_WALK_STATE *WalkState, ACPI_PARSE_OBJECT **Op, ACPI_STATUS Status);
ACPI_STATUS AcpiPsCompleteThisOp(ACPI_WALK_STATE *WalkState, ACPI_PARSE_OBJECT *Op);
void AcpiPsPopScope(void *ParserState, ACPI_PARSE_OBJECT **Op, uint32_t *ArgTypes, uint32_t *ArgCount);

#define return_ACPI_STATUS(s) return (s)