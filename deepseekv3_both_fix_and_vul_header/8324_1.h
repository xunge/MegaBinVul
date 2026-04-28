#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>

struct gengetopt_args_info {
    int version_given;
    int help_given;
    int hidden_nfkc_given;
    int nfkc_given;
    int stringprep_given;
    int punycode_encode_given;
    int punycode_decode_given;
    int idna_to_ascii_given;
    int idna_to_unicode_given;
    int quiet_given;
    int debug_given;
    int allow_unassigned_given;
    int usestd3asciirules_given;
    int profile_given;
    char *profile_arg;
    int inputs_num;
    char **inputs;
    int tld_flag;
    int no_tld_flag;
};

struct Tld_table;

#define BUFSIZ 8192
#define PACKAGE ""
#define LOCALEDIR ""
#define PACKAGE_NAME ""
#define VERSION ""
#define GREETING ""
#define _(x) x
#define N_(x) x
#define STRINGPREP_OK 0
#define PUNYCODE_SUCCESS 0
#define IDNA_SUCCESS 0
#define IDNA_ALLOW_UNASSIGNED 1
#define IDNA_USE_STD3_ASCII_RULES 2
#define TLD_SUCCESS 0
#define TLD_INVALID 1

extern void set_program_name(char *name);
extern void bindtextdomain(const char *domainname, const char *dirname);
extern void textdomain(const char *domainname);
extern int cmdline_parser(int argc, char **argv, struct gengetopt_args_info *args_info);
extern void version_etc(FILE *stream, const char *command_name, const char *package, const char *version, const char *author, char *copyright);
extern void usage(int status);
extern void error(int status, int errnum, const char *format, ...);
extern const char *stringprep_locale_charset(void);
extern char *stringprep_locale_to_utf8(const char *str);
extern uint32_t *stringprep_utf8_to_ucs4(const char *str, ssize_t len, size_t *items_written);
extern int stringprep_profile(const char *in, char **out, const char *profile, int flags);
extern const char *stringprep_strerror(int error_code);
extern char *stringprep_utf8_to_locale(const char *str);
extern char *stringprep_ucs4_to_utf8(const uint32_t *str, ssize_t len, size_t *items_read, size_t *items_written);
extern int punycode_encode(size_t input_length, const uint32_t input[], const unsigned char case_flags[], size_t *output_length, char output[]);
extern const char *punycode_strerror(int error_code);
extern int punycode_decode(size_t input_length, const char input[], size_t *output_length, uint32_t output[], unsigned char case_flags[]);
extern int idna_to_ascii_4z(const uint32_t *input, char **output, int flags);
extern const char *idna_strerror(int error_code);
extern int idna_to_unicode_8z4z(const char *input, uint32_t **output, int flags);
extern int tld_check_4z(const uint32_t *domain, size_t *errpos, const struct Tld_table *tld);
extern const char *tld_strerror(int error_code);
extern char *stringprep_utf8_nfkc_normalize(const char *str, ssize_t len);