typedef struct tvbuff_t tvbuff_t;
typedef struct vt_vector vt_vector;
typedef struct vtype_data vtype_data;

typedef unsigned int guint;

int vvalue_tvb_vector_internal(tvbuff_t *tvb, int offset, vt_vector *val, vtype_data *type, guint num);
guint tvb_get_letohl(tvbuff_t *tvb, int offset);