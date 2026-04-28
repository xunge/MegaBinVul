#include <stdbool.h>

struct f2fs_sb_info;

void __issue_discard_cmd(struct f2fs_sb_info *sbi, bool sync);
void __drop_discard_cmd(struct f2fs_sb_info *sbi);
void __wait_discard_cmd(struct f2fs_sb_info *sbi, bool sync);