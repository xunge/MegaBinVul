#include <iostream>
#include <cassert>
#include <vector>
#include <memory>

namespace Exiv2 {
    bool fileExists(const std::string& path, bool);
    
    class Image {
    public:
        typedef std::unique_ptr<Image> AutoPtr;
        void readMetadata();
    };
    
    class ImageFactory {
    public:
        static Image::AutoPtr open(const std::string& path);
    };
    
    struct PreviewProperties {
        int dummy;
    };
    typedef std::vector<PreviewProperties> PreviewPropertiesList;
    
    class PreviewImage {};
    
    class PreviewManager {
    public:
        PreviewManager(const Image& image);
        PreviewImage getPreviewImage(const PreviewProperties& props) const;
        PreviewPropertiesList getPreviewProperties() const;
    };
}

namespace Params {
    typedef std::vector<int> PreviewNumbers;
    
    class instance {
    public:
        static instance& get() {
            static instance inst;
            return inst;
        }
        const PreviewNumbers previewNumbers_ = {};
    };
}

class Extract {
private:
    std::string path_;
    void writePreviewFile(const Exiv2::PreviewImage& img, int num) const;
public:
    int writePreviews() const;
};

const char* _(const char* str) { return str; }