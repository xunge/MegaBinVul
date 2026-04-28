typedef struct _zend_mb_regex_globals {
    void *ht_rc;
} zend_mb_regex_globals;

#define TSRMLS_DC
#define zend_hash_destroy(ht)