#include <stdint.h>
#include <stddef.h>

typedef uintptr_t value;
typedef uint32_t mlsize_t;
typedef uint32_t asize_t;
typedef uint32_t header_t;
typedef unsigned char tag_t;

struct custom_operations {
    void (*finalize)(void*);
    mlsize_t (*deserialize)(void*);
};

struct ref_table {
    value** ptr;
    value** limit;
};

enum operation {
    OFreshOID,
    OShift,
    OReadItems
};

struct intern_item {
    value* dest;
    enum operation op;
    mlsize_t arg;
};

extern struct intern_item* intern_stack;
extern value* intern_dest;
extern value** intern_obj_table;
extern mlsize_t obj_counter;
extern uint32_t intern_color;
extern unsigned char* intern_src;
extern struct ref_table caml_finalize_table;

#define PREFIX_SMALL_INT 0x80
#define PREFIX_SMALL_BLOCK 0x40
#define PREFIX_SMALL_STRING 0x20

#define CODE_INT8 0x00
#define CODE_INT16 0x01
#define CODE_INT32 0x02
#define CODE_INT64 0x03
#define CODE_SHARED8 0x04
#define CODE_SHARED16 0x05
#define CODE_SHARED32 0x06
#define CODE_BLOCK32 0x07
#define CODE_BLOCK64 0x08
#define CODE_STRING8 0x09
#define CODE_STRING32 0x0A
#define CODE_DOUBLE_LITTLE 0x0B
#define CODE_DOUBLE_BIG 0x0C
#define CODE_DOUBLE_ARRAY8_LITTLE 0x0D
#define CODE_DOUBLE_ARRAY8_BIG 0x0E
#define CODE_DOUBLE_ARRAY32_LITTLE 0x0F
#define CODE_DOUBLE_ARRAY32_BIG 0x10
#define CODE_CODEPOINTER 0x11
#define CODE_INFIXPOINTER 0x12
#define CODE_CUSTOM 0x13

#define Object_tag 0
#define String_tag 1
#define Double_tag 2
#define Double_array_tag 3
#define Custom_tag 4

#define ARCH_SIXTYFOUR 0

#define Val_hp(p) ((value)(p))
#define Val_int(i) ((value)((i) << 1))
#define Val_long(l) ((value)((l) << 1))
#define Int_val(v) ((int)((v) >> 1))
#define Field(v,i) (((value*)(v))[i])
#define String_val(v) ((char*)(v))
#define Byte(v,i) (((unsigned char*)(v))[i])
#define Tag_hd(h) ((h) & 0xFF)
#define Wosize_hd(h) (((h) >> 10) & 0x3FFFFF)
#define Make_header(s,t,c) (((s) << 10) | (t) | ((c) << 24))
#define Bsize_wsize(s) ((s) * sizeof(value))
#define Double_wosize (sizeof(double)/sizeof(value))
#define Is_young(v) (0)

static void ReadItems(value*, mlsize_t);
static void caml_set_oo_id(value);
static uint8_t read8u(void);
static value Atom(tag_t);
static void Assert(int);
static void PushItem(void);
static void readblock(void*, mlsize_t);
static int8_t read8s(void);
static int16_t read16s(void);
static int32_t read32s(void);
static int64_t read64s(void);
static uint16_t read16u(void);
static uint32_t read32u(void);
static void intern_free_stack(void);
static void intern_cleanup(void);
static void intern_bad_code_pointer(unsigned char*);
static char* intern_resolve_code_pointer(unsigned char*, asize_t);
static struct custom_operations* caml_find_custom_operations(char*);
static value* caml_named_value(char*);
static void caml_failwith(const char*);
static void caml_realloc_ref_table(struct ref_table*);
static void CAMLassert(int);
static void readfloat(double*, uint8_t);
static void readfloats(double*, mlsize_t, uint8_t);

#define Custom_ops_val(v) (*((struct custom_operations**)(v)))