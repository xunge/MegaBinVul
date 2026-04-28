#include <stdio.h>
#include <stddef.h>

#define NUL '\0'
#define UNUSED
#define MB_PTR_ADV(p) ((p) += 1)

typedef struct {
    char *os_errbuf;
    size_t os_errbuflen;
} optset_T;

typedef unsigned char char_u;

extern char_u *p_langmap;
extern int (*mb_ptr2char)(char_u *);
extern char_u langmap_mapchar[256];
extern void *langmap_mapga;
extern void ga_clear(void *);
extern void langmap_init(void);
extern void langmap_set_entry(int from, int to);
extern char *transchar(int c);
extern char *_(const char *str);

#define e_langmap_matching_character_missing_for_str "e_langmap_matching_character_missing_for_str"
#define e_langmap_extra_characters_after_semicolon_str "e_langmap_extra_characters_after_semicolon_str"