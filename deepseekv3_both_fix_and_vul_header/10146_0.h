#include <stddef.h>
#include <stdint.h>

#define PKT_LEN_SIZE 4
#define GIT_EBUFS -1
#define GIT_ERROR -2
#define GIT_SIDE_BAND_DATA 1
#define GIT_SIDE_BAND_PROGRESS 2
#define GIT_SIDE_BAND_ERROR 3

typedef struct git_pkt git_pkt;

int parse_len(const char *line);
int git__prefixcmp(const char *str, const char *prefix);
void giterr_clear();
int pack_pkt(git_pkt **head);
int flush_pkt(git_pkt **head);
int data_pkt(git_pkt **head, const char *line, int32_t len);
int sideband_progress_pkt(git_pkt **head, const char *line, int32_t len);
int sideband_error_pkt(git_pkt **head, const char *line, int32_t len);
int ack_pkt(git_pkt **head, const char *line, int32_t len);
int nak_pkt(git_pkt **head);
int err_pkt(git_pkt **head, const char *line, int32_t len);
int comment_pkt(git_pkt **head, const char *line, int32_t len);
int ok_pkt(git_pkt **head, const char *line, int32_t len);
int ng_pkt(git_pkt **head, const char *line, int32_t len);
int unpack_pkt(git_pkt **head, const char *line, int32_t len);
int ref_pkt(git_pkt **head, const char *line, int32_t len);