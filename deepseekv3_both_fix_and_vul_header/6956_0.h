#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct blogpost {
    // 定义blogpost结构体成员
    // 根据实际需要添加成员变量
};

int file_exists(const char *path);
struct blogpost make_blogpost(const char *post_path);
void send_header(const char *name, const char *value);
void terminate_headers(void);
void template_header(void);
void template_post_single_entry(struct blogpost post);
void template_error_404(void);
void template_footer(void);