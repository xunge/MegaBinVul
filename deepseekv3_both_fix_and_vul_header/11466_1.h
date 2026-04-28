typedef struct _XDisplay Display;
typedef struct {
    int type;
    unsigned long serial;
    int error_code;
    int request_code;
    int minor_code;
    unsigned long resourceid;
} XErrorEvent;

extern struct {
    int (*orighandler)(Display *, XErrorEvent *);
} x_error_handler;

#define X_FreeColors 0