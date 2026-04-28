#include <stdint.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ANON_ID_LEN 16
#define ANON_CLIENT_LEN 16

struct list {
    struct le *head;
    struct le *tail;
};

struct le {
    struct le *next;
    struct le *prev;
    void *data;
};

struct audio_level {
    const char *userid;
    const char *clientid;
    int aulevel;
    int aulevel_smooth;
    bool is_self;
};

struct json_object;
struct mbuf {
    size_t pos;
    size_t end;
    char *buf;
};

#define LIST_FOREACH(list, le) for ((le) = (list)->head; (le); (le) = (le)->next)

size_t list_count(const struct list *list);
int jzon_add_str(struct json_object *obj, const char *key, const char *fmt, ...);
int jzon_add_int(struct json_object *obj, const char *key, int32_t value);
struct json_object *jzon_alloc_object(void);
struct json_object *jzon_alloc_array(void);
void json_object_array_add(struct json_object *array, struct json_object *obj);
void json_object_object_add(struct json_object *obj, const char *key, struct json_object *val);
void jzon_encode(char **str, struct json_object *obj);
void anon_id(char *dest, const char *src);
void anon_client(char *dest, const char *src);
struct mbuf *mbuf_alloc(size_t size);
int mbuf_printf(struct mbuf *mb, const char *fmt, ...);
void mbuf_strdup(struct mbuf *mb, char **str, size_t len);
void mem_deref(void *ptr);