#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define USBHID_ITEMTYPE_MAIN 0
#define USBHID_ITEMTYPE_GLOBAL 1
#define USBHID_ITEMTYPE_LOCAL 2

#define USBHID_MAINITEM_TAG_INPUT 8
#define USBHID_MAINITEM_TAG_OUTPUT 9
#define USBHID_MAINITEM_TAG_FEATURE 11
#define USBHID_MAINITEM_TAG_COLLECTION 10

#define USBHID_GLOBALITEM_TAG_USAGE_PAGE 0
#define USBHID_GLOBALITEM_TAG_LOG_MIN 1
#define USBHID_GLOBALITEM_TAG_LOG_MAX 2
#define USBHID_GLOBALITEM_TAG_REPORT_SIZE 7
#define USBHID_GLOBALITEM_TAG_REPORT_ID 8
#define USBHID_GLOBALITEM_TAG_REPORT_COUNT 9
#define USBHID_GLOBALITEM_TAG_PUSH 10
#define USBHID_GLOBALITEM_TAG_POP 11

#define USBHID_LOCALITEM_TAG_USAGE 0
#define USBHID_LOCALITEM_TAG_USAGE_MIN 1
#define USBHID_LOCALITEM_TAG_USAGE_MAX 2

#define HID_USAGE_PAGE (1 << 0)
#define HID_LOGICAL_MIN (1 << 1)
#define HID_LOGICAL_MAX (1 << 2)
#define HID_REPORT_SIZE (1 << 3)
#define HID_REPORT_ID (1 << 4)
#define HID_REPORT_COUNT (1 << 5)
#define HID_USAGE_MIN (1 << 6)
#define HID_REQUIRED_MASK (HID_USAGE_PAGE | HID_LOGICAL_MIN | HID_LOGICAL_MAX | HID_REPORT_SIZE | HID_REPORT_COUNT)
#define HID_GLOBAL_MASK (HID_USAGE_PAGE | HID_LOGICAL_MIN | HID_LOGICAL_MAX | HID_REPORT_SIZE | HID_REPORT_ID | HID_REPORT_COUNT)

#define MAX_REPORT_DESCRIPTOR_COUNT 1024
#define TRUE 1
#define FALSE 0

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef int32_t gint32;
typedef bool gboolean;

typedef struct {
    guint32 usage_page;
    gint32 logical_min;
    gint32 logical_max;
    guint32 report_size;
    guint32 report_count;
    guint32 report_id;
    guint32 properties;
    void* usages;
} hid_field_t;

typedef struct {
    guint8* desc_body;
    guint32 desc_length;
    gboolean uses_report_id;
    void* fields_in;
    void* fields_out;
} report_descriptor_t;

typedef struct wmem_allocator_t wmem_allocator_t;

wmem_allocator_t* wmem_file_scope(void);
void* wmem_array_new(wmem_allocator_t* allocator, size_t elem_size);
void wmem_array_append(void* array, const void* data, size_t elem_size);
size_t wmem_array_get_count(const void* array);
void* wmem_array_index(const void* array, size_t index);
void wmem_array_grow(void* array, size_t count);
void wmem_free(wmem_allocator_t* allocator, void* ptr);

guint32 hid_unpack_value(guint8* data, int offset, int size);
gboolean hid_unpack_signed(guint8* data, int offset, int size, gint32* value);

static inline void append_hid_field(void* array, const hid_field_t* field) {
    wmem_array_append(array, field, sizeof(hid_field_t));
}

static inline void append_guint32(void* array, guint32 value) {
    wmem_array_append(array, &value, sizeof(guint32));
}