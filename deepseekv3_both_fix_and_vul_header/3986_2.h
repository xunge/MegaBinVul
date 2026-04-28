#include <stddef.h>
#include <stdint.h>

typedef uint64_t ut64;
typedef struct ELFOBJ ELFOBJ;
typedef struct Sdb Sdb;

typedef struct {
    uint32_t vn_version;
    uint32_t vn_cnt;
    uint32_t vn_file;
    uint32_t vn_aux;
    uint32_t vn_next;
} Verneed;

#define UT64_MAX UINT64_MAX
#define DT_VERNEED 0
#define DT_VERNEEDNUM 0
#define Elf_(x) x
#define RZ_LOG_WARN(...)

Sdb *sdb_new0();
void sdb_free(Sdb *sdb);
int sdb_num_set(Sdb *sdb, const char *key, ut64 num, int mode);
int sdb_ns_set(Sdb *sdb, const char *key, Sdb *ns);
char *rz_strf(char *buf, const char *fmt, ...);
int rz_bin_elf_get_dt_info(ELFOBJ *bin, int type, ut64 *value);
ut64 rz_bin_elf_v2p(ELFOBJ *bin, ut64 vaddr);
int get_verneed_entry(ELFOBJ *bin, ut64 offset, Verneed *entry);
Sdb *get_verneed_entry_sdb(ELFOBJ *bin, Verneed entry, ut64 offset);