#include <stdint.h>

typedef int gboolean;
typedef uint32_t guint32;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct column_info column_info;

struct packet_info {
    column_info *cinfo;
};

#define TRUE 1
#define FALSE 0
#define COL_INFO 0

tvbuff_t* tvb_child_uncompress(tvbuff_t* parent, tvbuff_t* tvb, int offset, guint32 length);
void col_append_str(column_info *cinfo, int column, const char *str);