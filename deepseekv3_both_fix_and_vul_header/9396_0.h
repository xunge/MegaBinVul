#include <stdbool.h>
#include <stdlib.h>

struct options {
    bool cookies;
    int verbose;
    int ntry;
    int reclevel;
    bool add_hostdir;
    bool netrc;
    bool ftp_glob;
    bool htmlify;
    bool http_keep_alive;
    bool use_proxy;
    char *no_proxy;
    int prefer_family;
    bool allow_cache;
    int read_timeout;
    bool use_robots;
    bool remove_listing;
    int dot_bytes;
    int dot_spacing;
    int dots_in_line;
    bool dns_cache;
    bool ftp_pasv;
    bool check_cert;
    int restrict_files_os;
    bool restrict_files_ctrl;
    bool restrict_files_nonascii;
    int restrict_files_case;
    int regex_type;
    int max_redirect;
    int waitretry;
    bool enable_iri;
    char *locale;
    char *encoding_remote;
    bool useservertimestamps;
    bool show_all_dns_entries;
    long warc_maxsize;
    bool warc_compression_enabled;
    bool warc_digests_enabled;
    bool warc_cdx_enabled;
    char *warc_cdx_dedup_filename;
    char *warc_tempdir;
    bool warc_keep_log;
    long start_pos;
    bool show_progress;
    bool noscroll;
    bool retr_symlinks;
};

extern struct options opt;

enum {
    prefer_none,
    prefer_ipv4,
    prefer_ipv6
};

enum {
    restrict_windows,
    restrict_unix,
    restrict_no_case_restriction
};

enum {
    regex_type_posix,
    regex_type_pcre
};

void xzero(struct options *ptr);
char *sepstring(char *str);

#define xzero(opt) xzero(&opt)