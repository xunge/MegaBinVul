#include <vector>
#include <memory>
#include <map>
#include <string>
#include <sstream>
#include <cstdint>

typedef uint32_t heif_item_id;

enum heif_error {
    heif_error_Ok,
    heif_error_Invalid_input,
    heif_error_Memory_allocation_error
};

enum heif_suberror {
    heif_suberror_Nonexisting_item_referenced,
    heif_suberror_Unspecified,
    heif_suberror_Auxiliary_image_type_unspecified,
    heif_suberror_No_hvcC_box,
    heif_suberror_Security_limit_exceeded
};

class Error {
public:
    Error(heif_error, heif_suberror, const std::string&);
    Error(heif_error, heif_suberror, const char*);
    Error();
    operator bool() const;
    static Error Ok;
};

class Box {
public:
    virtual uint32_t get_short_type() const = 0;
    virtual ~Box() = default;
};

class Box_ipco {
public:
    struct Property {
        std::shared_ptr<Box> property;
    };
    bool get_property_for_item_ID(heif_item_id, std::shared_ptr<class Box_ipma>, uint32_t);
};

class Box_ipma {};

class Box_infe : public Box {
public:
    std::string get_item_type() const;
    bool is_hidden_item() const;
    uint32_t get_short_type() const override;
};

class Box_iref {
public:
    struct Reference {
        const Box& header;
        std::vector<heif_item_id> to_item_ID;
    };
    std::vector<Reference> get_references_from(heif_item_id);
};

class Box_auxC : public Box {
public:
    std::string get_aux_type() const;
    std::vector<uint8_t> get_subtypes() const;
    uint32_t get_short_type() const override;
};

class Box_ispe : public Box {
public:
    uint32_t get_width() const;
    uint32_t get_height() const;
    uint32_t get_short_type() const override;
};

class Box_clap : public Box {
public:
    uint32_t get_width_rounded() const;
    uint32_t get_height_rounded() const;
    uint32_t get_short_type() const override;
};

class Box_irot : public Box {
public:
    uint32_t get_rotation() const;
    uint32_t get_short_type() const override;
};

class Box_colr : public Box {
public:
    std::shared_ptr<class ColorProfile> get_color_profile() const;
    uint32_t get_short_type() const override;
};

class ColorProfile {};

class SEIMessage {
public:
    virtual ~SEIMessage() = default;
};

class SEIMessage_depth_representation_info : public SEIMessage {
};

class ImageMetadata {
public:
    heif_item_id item_id;
    std::string item_type;
    std::string content_type;
    std::vector<uint8_t> m_data;
};

class Image {
public:
    Image(class HeifContext*, heif_item_id);
    void set_primary(bool);
    heif_item_id get_id() const;
    void set_is_thumbnail_of(heif_item_id);
    bool is_thumbnail() const;
    void add_thumbnail(std::shared_ptr<Image>);
    void set_is_alpha_channel_of(heif_item_id);
    void set_alpha_channel(std::shared_ptr<Image>);
    void set_is_depth_channel_of(heif_item_id);
    void set_depth_channel(std::shared_ptr<Image>);
    void set_depth_representation_info(const SEIMessage_depth_representation_info&);
    void set_resolution(uint32_t, uint32_t);
    void set_ispe_resolution(uint32_t, uint32_t);
    uint32_t get_width() const;
    uint32_t get_height() const;
    void set_color_profile(std::shared_ptr<ColorProfile>);
    bool is_primary() const;
    bool is_alpha_channel() const;
    bool is_depth_channel() const;
    void add_metadata(std::shared_ptr<ImageMetadata>);
};

class HeifFile {
public:
    std::vector<heif_item_id> get_item_IDs() const;
    std::shared_ptr<Box_infe> get_infe_box(heif_item_id) const;
    heif_item_id get_primary_image_ID() const;
    std::shared_ptr<Box_iref> get_iref_box() const;
    Error get_properties(heif_item_id, std::vector<Box_ipco::Property>&) const;
    std::string get_item_type(heif_item_id) const;
    std::string get_content_type(heif_item_id) const;
    Error get_compressed_image_data(heif_item_id, std::vector<uint8_t>*) const;
    std::shared_ptr<Box_ipco> get_ipco_box() const;
    std::shared_ptr<Box_ipma> get_ipma_box() const;
};

class HeifContext {
public:
    Error interpret_heif_file();
private:
    std::map<heif_item_id, std::shared_ptr<Image>> m_all_images;
    std::vector<std::shared_ptr<Image>> m_top_level_images;
    std::shared_ptr<Image> m_primary_image;
    HeifFile* m_heif_file;

    void remove_top_level_image(std::shared_ptr<Image>);
    bool item_type_is_image(const std::string&);
};

uint32_t fourcc(const char*);
Error decode_hevc_aux_sei_messages(const std::vector<uint8_t>&, std::vector<std::shared_ptr<SEIMessage>>&);

const int MAX_IMAGE_WIDTH = 0;
const int MAX_IMAGE_HEIGHT = 0;