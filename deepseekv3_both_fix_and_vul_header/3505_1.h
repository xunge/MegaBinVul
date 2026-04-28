#include <stddef.h>
#include <string.h>

struct task_struct {
    // 最小化的结构体定义，仅支持赋值操作
    char _dummy[1]; 
};

void flush_fp_to_thread(struct task_struct *);
void flush_altivec_to_thread(struct task_struct *);
void flush_vsx_to_thread(struct task_struct *);
void flush_spe_to_thread(struct task_struct *);
void clear_task_ebb(struct task_struct *);