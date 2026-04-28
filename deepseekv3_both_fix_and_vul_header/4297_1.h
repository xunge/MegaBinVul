#include <stddef.h>

class PluginView;
class PluginDocumentParser {
public:
    void appendBytes(const char* data, size_t length);
    bool isStopped();
    void createDocumentStructure();
    PluginView* pluginView();
    void* m_embedElement;
};

class PluginView {
public:
    void didReceiveData(const char* data, size_t length);
};