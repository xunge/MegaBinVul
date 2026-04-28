#include <stdint.h>
#include <stdlib.h>

struct super_block;
struct ustr {
    uint8_t *u_name;
    int u_len;
};

#define GFP_NOFS 0
#define UDF_FLAG_UTF8 0
#define UDF_FLAG_NLS_MAP 0

#define UDF_QUERY_FLAG(sb, flag) (0)
#define UDF_SB(sb) ((struct udf_sb_info *)NULL)
#define udf_debug(fmt, ...)

struct udf_sb_info {
    void *s_nls_map;
};

#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)

int udf_build_ustr_exact(struct ustr *unifilename, uint8_t *sname, int slen);
int udf_CS0toUTF8(struct ustr *filename, struct ustr *unifilename);
int udf_CS0toNLS(void *s_nls_map, struct ustr *filename, struct ustr *unifilename);

// 两个不同参数版本的函数声明
int udf_translate_to_linux_v1(uint8_t *dname, int dlen, uint8_t *u_name, int u_len, uint8_t *unif_name, int unif_len);
int udf_translate_to_linux_v2(uint8_t *dname, uint8_t *u_name, int u_len, uint8_t *unif_name, int unif_len);

// 使用宏来匹配不同调用方式
#define udf_translate_to_linux(dname, arg2, arg3, arg4, arg5, ...) \
    _Generic((arg2), \
        int: udf_translate_to_linux_v1, \
        uint8_t*: udf_translate_to_linux_v2 \
    )(dname, arg2, arg3, arg4, arg5, ##__VA_ARGS__)