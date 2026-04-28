#include <string>
#include <algorithm>
#include <cstdint>
#include <iterator>

namespace Base64 {
    std::string decode(const std::string& encoded, int padding);
}

namespace boost::archive::iterators {
    template<typename Iterator>
    struct binary_from_base64 {
        using iterator_category = std::input_iterator_tag;
        using value_type = char;
        using difference_type = std::ptrdiff_t;
        using pointer = char*;
        using reference = char&;
        
        Iterator it;
        binary_from_base64(Iterator it) : it(it) {}
        char operator*() const { return *it; }
        binary_from_base64& operator++() { ++it; return *this; }
        bool operator!=(const binary_from_base64& other) const { return it != other.it; }
    };

    template<typename Base, int BitsOut, int BitsIn>
    struct transform_width {
        using iterator_category = std::input_iterator_tag;
        using value_type = char;
        using difference_type = std::ptrdiff_t;
        using pointer = char*;
        using reference = char&;
        
        Base base;
        transform_width(Base base) : base(base) {}
        char operator*() const { return *base; }
        transform_width& operator++() { ++base; return *this; }
        bool operator!=(const transform_width& other) const { return base != other.base; }
    };
}