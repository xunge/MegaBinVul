struct dl_handle {
    void *ptr;
    int open;
};

typedef unsigned long VALUE;

extern const void *fiddle_handle_data_type;
extern VALUE rb_eFiddleError;

#define TypedData_Get_Struct(obj, type, data_type, sval) \
    ((sval) = (type*)rb_check_typeddata((obj), (data_type)))

VALUE rb_check_typeddata(VALUE obj, const void *data_type);
VALUE fiddle_handle_sym(void *ptr, const char *sym);
VALUE rb_raise(VALUE exc, const char *fmt);
char *StringValueCStr(VALUE str);