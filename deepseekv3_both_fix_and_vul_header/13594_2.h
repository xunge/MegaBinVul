#include <stdlib.h>

typedef struct xlsxio_read_sheetlist_struct* xlsxioreadersheetlist;

struct xlsxio_reader_struct {
    void* zip;
};

typedef struct xlsxio_reader_struct* xlsxioreader;
typedef void* XML_Parser;

#define DLL_EXPORT_XLSXIO
#define XML_Char char

extern const char* xlsx_content_type;
extern const char* xlsm_content_type;
extern const char* xltx_content_type;
extern const char* xltm_content_type;

typedef struct {
    XML_Parser xmlparser;
    void (*callback)(void*);
    void* callbackdata;
} sheet_callback_data;

struct xlsxio_read_sheetlist_struct {
    xlsxioreader handle;
    sheet_callback_data sheetcallbackdata;
    char* nextsheetname;
    void* zipfile;
    XML_Parser xmlparser;
};

void iterate_files_by_contenttype(void* zip, const char* content_type, 
    void (*callback)(void*, const char*, void*), char** result, void* userdata);
void* XML_Char_openzip(void* zip, const char* filename, int flags);
XML_Parser expat_process_zip_file_suspendable(void* zipfile, 
    void (*start_element)(void*, const char*, const char**), 
    void (*end_element)(void*, const char*), 
    void (*character_data)(void*, const char*, int), 
    void* userdata);
void xlsxioread_find_main_sheet_file_callback(void* handle, const char* filename, void* callbackdata);
void xlsxioread_list_sheets_resumable_callback(void* data);
void main_sheet_list_expat_callback_element_start(void* userData, const char* name, const char** atts);