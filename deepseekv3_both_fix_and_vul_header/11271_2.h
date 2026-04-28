#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NBDClient NBDClient;
typedef void OBJECT;

struct QTAILQ_ENTRY {
    struct NBDClient *tqe_next;
    struct NBDClient **tqe_prev;
};

struct NBDClient {
    int refcount;
    bool closing;
    void *sioc;
    void *ioc;
    void *tlscreds;
    char *tlsaclname;
    struct {
        struct {
            NBDClient *tqh_first;
            NBDClient **tqh_last;
        } clients;
    } *exp;
    struct QTAILQ_ENTRY next;
};

#define OBJECT(ptr) ((OBJECT*)(ptr))
#define g_free free

void nbd_unset_handlers(NBDClient *client);
void object_unref(OBJECT *obj);
void nbd_export_put(void *exp);

#define QTAILQ_REMOVE(head, entry, field) do { \
    if ((entry)->field.tqe_next != NULL) \
        (entry)->field.tqe_next->field.tqe_prev = (entry)->field.tqe_prev; \
    else \
        (head)->tqh_last = (entry)->field.tqe_prev; \
    *(entry)->field.tqe_prev = (entry)->field.tqe_next; \
} while (0)