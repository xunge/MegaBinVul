#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <syslog.h>

enum {
    CPL_NONE,
    CPL_CLEAR,
    CPL_PRIVATE
};

extern int xferfd;
extern int state_needs_update;
extern int idletime;
extern char *cmd;
extern size_t cmdsize;
extern int logging;
extern int debug;
extern int loggedin;
extern int guest;
extern unsigned long long uploaded;
extern unsigned long long downloaded;
extern int enforce_tls_auth;
extern int data_protection_level;
extern int v6ready;
extern int epsv_all;
extern int broken_client_compat;
extern int autorename;
extern int modern_listings;
extern off_t restartat;
extern time_t noopidle;
extern char *wd;
extern void *tls_cnx;
extern void *shm_data_cur;
extern double idletime_noop;
extern unsigned long throttling_delay;
extern int disallow_passive;
extern void *force_passive_ip;
extern void *ctrlconn;

#define MAX_SITE_IDLE 3600
#define CRLF "\r\n"
#define FTPWHO_STATE_IDLE 0
#define MSG_TIMEOUT "Timeout"
#define MSG_TIMEOUT_PARSER "Timeout (parser)"
#define MSG_LINE_TOO_LONG "Line too long"
#define MSG_DEBUG_COMMAND "Command"
#define MSG_TLS_NEEDED "TLS needed"
#define MSG_WHOAREYOU "Who are you?"
#define MSG_GOODBYE "Goodbye"
#define MSG_PROT_BEFORE_PBSZ "PROT before PBSZ"
#define MSG_MISSING_ARG "Missing argument"
#define MSG_PROT_OK "PROT OK"
#define MSG_PROT_UNKNOWN_LEVEL "Unknown PROT level"
#define MSG_AUTH_UNIMPLEMENTED "AUTH unimplemented"
#define MSG_NOT_LOGGED_IN "Not logged in"
#define MSG_ABOR_SUCCESS "ABOR success"
#define MSG_SITE_HELP "SITE HELP"
#define MSG_BAD_CHMOD "Bad CHMOD"
#define MSG_ALIASES_ALIAS "Alias"
#define MSG_ALIASES_UNKNOWN "Unknown alias"
#define MSG_UNKNOWN_EXTENSION "Unknown extension"
#define MSG_UNKNOWN_COMMAND "Unknown command"
#define MSG_STAT_FAILURE "STAT failure"
#define MSG_VALUE_TOO_LARGE "Value too large"
#define MSG_IDLE_TIME "Idle time"
#define MSG_NO_FILE_NAME "No file name"
#define MSG_NO_DIRECTORY_NAME "No directory name"
#define MSG_NO_RESTART_POINT "No restart point"
#define MSG_PROT_PRIVATE_NEEDED "PROT private needed"
#define MSG_ONLY_IPV4 "Only IPv4"
#define MSG_IS_YOUR_CURRENT_LOCATION "is your current location"
#define MSG_GARBAGE_FOUND "Garbage found"
#define MSG_ACTIVE_DISABLED "Active disabled"

extern void setprocessname(const char *);
extern void ftpwho_lock(void);
extern void ftpwho_unlock(void);
extern void doreply(void);
extern int sfgets(void);
extern void die(int, int, const char *);
extern void addreply(int, const char *, ...);
extern void addreply_noformat(int, const char *);
extern void logfile(int, const char *, ...);
extern void antiidle(void);
extern void donoop(void);
extern void douser(const char *);
extern void dopass(const char *);
extern void dotype(const char *);
extern void domode(const char *);
extern void dostru(const char *);
extern void docwd(const char *);
extern void doport(const char *);
extern void doeprt(const char *);
extern void doesta(void);
extern void doestp(void);
extern void dopasv(int);
extern void doallo(off_t);
extern void dorest(const char *);
extern void dodele(const char *);
extern void dostor(const char *, int, int);
extern void dostou(void);
extern void domkd(const char *);
extern void dormd(const char *);
extern void donlist(const char *, int, int, int, int);
extern void domlst(const char *);
extern void domdtm(const char *);
extern void dosize(const char *);
extern void dornfr(const char *);
extern void dornto(const char *);
extern void dochmod(const char *, mode_t);
extern void doutime(const char *, const char *);
extern void print_aliases(void);
extern const char *lookup_alias(const char *);
extern void dofeat(void);
extern void doopts(const char *);
extern void usleep2(unsigned long);
extern char *revealextraspc(char *);
extern char *charset_client2fs(const char *);
extern char *charset_fs2client(const char *);
extern void *tls_init_new_session(void);
extern void dositetime(void);
extern void randomdelay(void);
extern void doretr(const char *);