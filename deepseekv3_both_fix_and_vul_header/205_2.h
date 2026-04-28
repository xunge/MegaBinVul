typedef struct _GObjectClass GObjectClass;
typedef struct _GVfsBackendClass GVfsBackendClass;
typedef struct _GVfsBackendAdminClass GVfsBackendAdminClass;

struct _GObjectClass {
    void (*finalize)(void);
};

struct _GVfsBackendClass {
    void (*mount)(void);
    void (*open_for_read)(void);
    void (*query_info)(void);
    void (*query_info_on_read)(void);
    void (*query_info_on_write)(void);
    void (*read)(void);
    void (*create)(void);
    void (*append_to)(void);
    void (*replace)(void);
    void (*write)(void);
    void (*close_read)(void);
    void (*close_write)(void);
    void (*seek_on_read)(void);
    void (*seek_on_write)(void);
    void (*enumerate)(void);
    void (*truncate)(void);
    void (*make_directory)(void);
    void (*make_symlink)(void);
    void (*query_fs_info)(void);
    void (*create_dir_monitor)(void);
    void (*create_file_monitor)(void);
    void (*set_display_name)(void);
    void (*set_attribute)(void);
    void (*delete)(void);
    void (*move)(void);
    void (*query_settable_attributes)(void);
    void (*query_writable_namespaces)(void);
};

struct _GVfsBackendAdminClass {
    GObjectClass parent_class;
};

#define G_OBJECT_CLASS(klass) ((GObjectClass*)klass)
#define G_VFS_BACKEND_CLASS(klass) ((GVfsBackendClass*)klass)

static void do_finalize(void) {}
static void do_mount(void) {}
static void do_open_for_read(void) {}
static void do_query_info(void) {}
static void do_query_info_on_read(void) {}
static void do_query_info_on_write(void) {}
static void do_read(void) {}
static void do_create(void) {}
static void do_append_to(void) {}
static void do_replace(void) {}
static void do_write(void) {}
static void do_close_read(void) {}
static void do_close_write(void) {}
static void do_seek_on_read(void) {}
static void do_seek_on_write(void) {}
static void do_enumerate(void) {}
static void do_truncate(void) {}
static void do_make_directory(void) {}
static void do_make_symlink(void) {}
static void do_query_fs_info(void) {}
static void do_create_dir_monitor(void) {}
static void do_create_file_monitor(void) {}
static void do_set_display_name(void) {}
static void do_set_attribute(void) {}
static void do_delete(void) {}
static void do_move(void) {}
static void do_query_settable_attributes(void) {}
static void do_query_writable_namespaces(void) {}