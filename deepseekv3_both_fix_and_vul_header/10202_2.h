struct key_match_data {
    unsigned int lookup_type;
    int (*cmp)(const void *key, const struct key_match_data *match_data);
};

static int asymmetric_key_cmp(const void *key, const struct key_match_data *match_data) {
    return 0;
}

#define KEYRING_SEARCH_LOOKUP_ITERATE 1