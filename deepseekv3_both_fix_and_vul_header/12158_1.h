typedef struct _Draw {
    void *info;
} Draw;

extern const void *rm_draw_data_type;

#define VALUE void*
#define rb_eNoMemError NULL
#define TypedData_Get_Struct(a,b,c,d) (d = malloc(sizeof(b)))
#define rb_raise(a,b) 
#define rb_block_given_p() 0
#define rb_yield(a)
#define AcquireDrawInfo() malloc(1)
#define GetDrawInfo(a,b)