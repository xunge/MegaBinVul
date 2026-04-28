#include <string>
#include <vector>
#include <cstdint>

typedef int heif_item_id;

enum heif_error {
    heif_error_Invalid_input
};

enum heif_suberror {
    heif_suberror_No_item_data
};

class Error {
public:
    static Error Ok;
    Error(heif_error, heif_suberror, const char*);
};

class HeifContext {
private:
    class HeifFile* m_heif_file;
public:
    Error get_id_of_non_virtual_child_image(heif_item_id id, heif_item_id& out) const;
};

class HeifFile {
public:
    std::string get_item_type(heif_item_id id);
    class IrefBox* get_iref_box();
};

class IrefBox {
public:
    std::vector<heif_item_id> get_references(heif_item_id id, uint32_t fourcc);
};

uint32_t fourcc(const char* str);