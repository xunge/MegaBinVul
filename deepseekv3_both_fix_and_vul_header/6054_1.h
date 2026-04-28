#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char ut8;
typedef unsigned short ut16;
typedef unsigned int ut32;
typedef unsigned long long ut64;

typedef struct RBinObject RBinObject;
typedef struct RBinSection RBinSection;
typedef struct RListIter RListIter;

struct RBinSection {
    ut64 vaddr;
};

struct RListIter {
    void *data;
    RListIter *next;
    RListIter *prev;
};

struct RBinObject {
    RListIter *sections;
};

typedef struct {
    const char *name;
    int op;
} swf_op_t;

typedef struct {
    const char *name;
} swf_tag_t;

#define TAG_SETBACKGROUNDCOLOR 9
#define SWFACTION_PUSH 0x96
#define SWFACTION_GOTOFRAME 0x81
#define SWFACTION_GETURL 0x83
#define SWFACTION_JUMP 0x99
#define SWFACTION_BRANCHIFTRUE 0x9D
#define SWFACTION_GETURL2 0x9A
#define SWFACTION_GOTOFRAME2 0x9F
#define SWFACTION_SETTARGET 0x8B
#define SWFACTION_CONSTANTPOOL 0x88
#define SWFACTION_WITH 0x94
#define SWFACTION_DEFINEFUNCTION 0x9B
#define SWFACTION_STOREREGISTER 0x87

swf_tag_t r_asm_swf_gettag(int tagCode);
swf_op_t r_asm_swf_getop(ut8 op);
ut64 r_mem_get_num(const ut8 *buf, int len);
void eprintf(const char *format, ...);

#define r_list_foreach(list, it, pos) \
    for (it = list; it && (pos = it->data, 1); it = it->next)