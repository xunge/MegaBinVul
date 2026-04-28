#include <string>
#include <memory>

class StringImpl;

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr);
    RefPtr(const RefPtr& other);
};

template<typename T> class PassRefPtr {
public:
    PassRefPtr(T* ptr);
    PassRefPtr(const RefPtr<T>& other);
};

class SegmentedString {
public:
    SegmentedString(PassRefPtr<StringImpl>);
    void append(const SegmentedString&);
    std::string toString() const;
};

class ImageLoader {
public:
    static void dispatchPendingBeforeLoadEvents();
};

class XMLDocumentParser {
public:
    void append(PassRefPtr<StringImpl> inputSource);
private:
    bool m_sawXSLTransform;
    bool m_sawFirstElement;
    bool m_parserPaused;
    SegmentedString m_originalSourceForTransform;
    SegmentedString m_pendingSrc;

    bool isStopped();
    void doWrite(const std::string& source);
    class Document* document();
};

class Document {
public:
    class Frame* frame();
};

class Frame {
public:
    class Script* script();
};

class Script {
public:
    bool canExecuteScripts(int executionPolicy);
};

enum ScriptExecutionStatus { NotAboutToExecuteScript };