#include <stddef.h>

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { NoEvents } EventType;

typedef struct _LogInfo {
    EventType event_mask;
} LogInfo;

typedef struct _LinkedList {
    /* Implementation dependent */
} LinkedList;

extern LinkedList *log_cache;
extern MagickBooleanType event_logging;

MagickBooleanType IsLinkedListEmpty(LinkedList *);
void ResetLinkedListIterator(LinkedList *);
void *GetNextValueInLinkedList(LinkedList *);