typedef struct {
    void *current_tasks;
} asyncio_state;

typedef long Py_hash_t;
typedef struct _object PyObject;
#define Py_None ((PyObject *)0)
#define NULL 0