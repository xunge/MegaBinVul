#include <stddef.h>
#include <stdarg.h>

typedef unsigned int acpi_status;
#define ACPI_FAILURE(status) (status != 0)
#define ACPI_MTX_NAMESPACE 0
#define ACPI_DB_INFO 0
#define ACPI_EXEC_APP

#define ACPI_FUNCTION_TRACE(x)
#define return_VOID return

struct acpi_namespace_node {
    // placeholder for acpi_namespace_node structure
};
extern struct acpi_namespace_node *acpi_gbl_root_node;

union acpi_operand_object {
    struct {
        void *mutex;
    } method;
    // other members would be here
};
extern union acpi_operand_object *acpi_gbl_module_code_list;

void acpi_ns_delete_namespace_subtree(struct acpi_namespace_node *node);
void acpi_ns_delete_node(struct acpi_namespace_node *node);
acpi_status acpi_ut_acquire_mutex(int mutex);
acpi_status acpi_ut_release_mutex(int mutex);
void acpi_ut_remove_reference(union acpi_operand_object *object);
void ACPI_DEBUG_PRINT(int level, const char *format, ...);

#define ACPI_DEBUG_PRINT(args) ACPI_DEBUG_PRINT args