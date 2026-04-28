#include <memory>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>

using heif_item_id = uint32_t;

class HeifFile {
public:
    class Box {
    public:
        virtual ~Box() = default;
        virtual std::shared_ptr<Box> get_property_for_item_ID(heif_item_id, std::shared_ptr<Box>, uint32_t) = 0;
    };
    
    std::shared_ptr<Box> get_ipco_box() const;
    std::shared_ptr<Box> get_ipma_box() const;
};

class Box_uncC : public HeifFile::Box {
public:
    struct Component {
        uint16_t component_index;
        uint8_t component_bit_depth;
    };
    
    std::vector<Component> get_components() const;
    std::shared_ptr<HeifFile::Box> get_property_for_item_ID(heif_item_id, std::shared_ptr<HeifFile::Box>, uint32_t) override;
};

class Box_cmpd : public HeifFile::Box {
public:
    enum ComponentType {
        component_type_monochrome,
        component_type_red,
        component_type_green,
        component_type_blue,
        component_type_Y
    };

    struct Component {
        ComponentType component_type;
    };
    
    const std::vector<Component>& get_components() const;
    std::shared_ptr<HeifFile::Box> get_property_for_item_ID(heif_item_id, std::shared_ptr<HeifFile::Box>, uint32_t) override;
};

class UncompressedImageCodec {
public:
    int get_luma_bits_per_pixel_from_configuration_unci(const HeifFile& heif_file, heif_item_id imageID);
};

uint32_t fourcc(const char* str);

namespace {
    constexpr Box_cmpd::ComponentType component_type_monochrome = Box_cmpd::component_type_monochrome;
    constexpr Box_cmpd::ComponentType component_type_red = Box_cmpd::component_type_red;
    constexpr Box_cmpd::ComponentType component_type_green = Box_cmpd::component_type_green;
    constexpr Box_cmpd::ComponentType component_type_blue = Box_cmpd::component_type_blue;
    constexpr Box_cmpd::ComponentType component_type_Y = Box_cmpd::component_type_Y;
}