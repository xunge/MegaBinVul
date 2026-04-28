#include <stdint.h>
#include <string.h>
#include <time.h>

typedef uint32_t mz_uint;
typedef uint32_t mz_uint32;
typedef uint8_t mz_uint8;
typedef int mz_bool;

#define MZ_FALSE 0
#define MZ_TRUE 1
#define MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE 512
#define MZ_ZIP_MAX_ARCHIVE_FILE_COMMENT_SIZE 512
#define MZ_ZIP_CDH_VERSION_MADE_BY_OFS 4
#define MZ_ZIP_CDH_VERSION_NEEDED_OFS 6
#define MZ_ZIP_CDH_BIT_FLAG_OFS 8
#define MZ_ZIP_CDH_METHOD_OFS 10
#define MZ_ZIP_CDH_FILE_TIME_OFS 12
#define MZ_ZIP_CDH_FILE_DATE_OFS 14
#define MZ_ZIP_CDH_CRC32_OFS 16
#define MZ_ZIP_CDH_COMPRESSED_SIZE_OFS 20
#define MZ_ZIP_CDH_DECOMPRESSED_SIZE_OFS 24
#define MZ_ZIP_CDH_INTERNAL_ATTR_OFS 36
#define MZ_ZIP_CDH_EXTERNAL_ATTR_OFS 38
#define MZ_ZIP_CDH_LOCAL_HEADER_OFS 42
#define MZ_ZIP_CDH_FILENAME_LEN_OFS 28
#define MZ_ZIP_CDH_COMMENT_LEN_OFS 30
#define MZ_ZIP_CDH_EXTRA_LEN_OFS 32
#define MZ_ZIP_CENTRAL_DIR_HEADER_SIZE 46
#define MZ_MIN(a, b) ((a) < (b) ? (a) : (b))

#define MZ_READ_LE16(p) ( (mz_uint)((p)[0]) | ((mz_uint)((p)[1]) << 8) )
#define MZ_READ_LE32(p) ( (mz_uint)((p)[0]) | ((mz_uint)((p)[1]) << 8) | \
                       ((mz_uint)((p)[2]) << 16) | ((mz_uint)((p)[3]) << 24) )

#define MZ_ZIP_ARRAY_ELEMENT(pArray, type, index) ((type *)(pArray))[index]

struct mz_zip_archive_state {
    mz_uint32 *m_central_dir_offsets;
};

struct mz_zip_archive {
    struct mz_zip_archive_state *m_pState;
};

struct mz_zip_archive_file_stat {
    mz_uint m_file_index;
    mz_uint m_central_dir_ofs;
    mz_uint m_version_made_by;
    mz_uint m_version_needed;
    mz_uint m_bit_flag;
    mz_uint m_method;
    time_t m_time;
    mz_uint m_crc32;
    mz_uint m_comp_size;
    mz_uint m_uncomp_size;
    mz_uint m_internal_attr;
    mz_uint m_external_attr;
    mz_uint m_local_header_ofs;
    char m_filename[MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE];
    mz_uint m_comment_size;
    char m_comment[MZ_ZIP_MAX_ARCHIVE_FILE_COMMENT_SIZE];
};

const mz_uint8 *mz_zip_reader_get_cdh(mz_zip_archive *pZip, mz_uint file_index);
time_t mz_zip_dos_to_time_t(mz_uint dos_time, mz_uint dos_date);