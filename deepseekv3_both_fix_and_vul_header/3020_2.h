#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define IAS_MAX_CLASSNAME 60
#define IAS_MAX_ATTRIBNAME 60
#define IAS_MAGIC 0x1234

struct sk_buff {
    uint8_t *data;
};

struct iriap_cb {
    int magic;
};

struct ias_object {
    char *name;
    int id;
};

struct ias_attrib {
    void *value;
};

struct ias_value {
    int type;
};

extern struct ias_value irias_missing;

#define IRDA_DEBUG(level, fmt, ...) printf(fmt, ##__VA_ARGS__)
#define IRDA_ASSERT(cond, action) if (!(cond)) { action; }

enum {
    IAS_CLASS_UNKNOWN,
    IAS_ATTRIB_UNKNOWN,
    IAS_SUCCESS = 0x1234
};

extern struct ias_object *irias_find_object(const char *name);
extern struct ias_attrib *irias_find_attrib(struct ias_object *obj, const char *attr);
extern void iriap_getvaluebyclass_response(struct iriap_cb *self, int id, int status, void *value);

typedef uint8_t __u8;