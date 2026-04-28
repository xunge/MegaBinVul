#include <stdint.h>
#include <stddef.h>

typedef uint32_t TEE_Result;
typedef void* TEE_ObjectHandle;

typedef struct {
    uint32_t attributeID;
    union {
        struct {
            void* buffer;
            size_t length;
        } memref;
        struct {
            uint32_t a;
            uint32_t b;
        } value;
    } content;
} TEE_Attribute;

typedef struct {
    uint32_t objectType;
    uint32_t objectSize;
    uint32_t maxObjectSize;
    uint32_t objectUsage;
    uint32_t handleFlags;
} TEE_ObjectInfo;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 1
#define TEE_HANDLE_FLAG_PERSISTENT (1 << 0)
#define TEE_HANDLE_FLAG_INITIALIZED (1 << 1)

struct utee_attribute {
    uint32_t attr_id;
    uint32_t a;
    uint32_t b;
    void* data;
    size_t data_len;
};

extern void __utee_check_attr_in_annotation(const TEE_Attribute *attrs, uint32_t attrCount);
extern void __utee_from_attr(struct utee_attribute *ua, const TEE_Attribute *attrs, uint32_t attrCount);
extern TEE_Result utee_cryp_obj_get_info(unsigned long object, TEE_ObjectInfo *info);
extern TEE_Result utee_cryp_obj_populate(unsigned long object, struct utee_attribute *ua, uint32_t attrCount);
extern void TEE_Panic(TEE_Result res);