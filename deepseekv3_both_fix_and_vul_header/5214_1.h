#include <string.h>

struct HashMap {
    struct HashMap *next;
    struct HashMap *prev;
    char *key;
    void *value;
    void (*destroy)(void *);
    void *(*dup)(const void *);
};

struct URL {
    struct HashMap args;
};

struct HttpConnection {
    struct HashMap header;
};

void initHashMap(struct HashMap *map, void (*destroy)(void *), void *(*dup)(const void *));
void *getFromHashMap(const struct HashMap *map, const char *key);
void *getRefFromHashMap(const struct HashMap *map, const char *key);
void urlDestroyHashMapEntry(void *entry);
void urlParseHeaderLine(struct HashMap *map, const char *line, int len);
void urlParseQueryString(struct HashMap *map, const char *buf, int len);
int urlMemcmp(const char *s1, int len1, const char *s2);
const char *urlMemstr(const char *haystack, int len, const char *needle);
void urlParsePart(struct URL *url, const char *part, int len);
void destroyHashMap(struct HashMap *map);
void info(const char *fmt, ...);
void warn(const char *fmt, ...);