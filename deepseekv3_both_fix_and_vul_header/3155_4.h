#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <utility>

typedef std::pair<std::string, std::string> StringPair;
typedef std::vector<StringPair> StringPairVector;

struct HTMLFormElement;

struct Event {
    static Event* createCancelableBubble(const char*);
};

struct Frame {
    struct Loader {
        struct Client {
            void dispatchWillSendSubmitEvent(void*);
        };
        Client* client() { return nullptr; }
    };
    Loader* loader() { return nullptr; }
};

struct Document {
    Frame* frame() { return nullptr; }
};

struct FormState {
    static FormState* create(HTMLFormElement*, const StringPairVector&, Document*, int);
};

enum SubmissionTrigger {
    NotSubmittedByJavaScript
};

template<typename T> struct RefPtr {
    T* ptr;
    RefPtr(T* p) : ptr(p) {}
    T* release() { return ptr; }
};

struct HTMLFormElement {
    bool m_isSubmittingOrPreparingForSubmission;
    bool m_shouldSubmit;
    Document& document();
    bool validateInteractively(Event*);
    void getTextFieldValues(StringPairVector&);
    bool dispatchEvent(Event*);
    void submit(Event*, bool, bool, SubmissionTrigger);
    bool prepareForSubmission(Event*);
};

struct EventNames {
    const char* submitEvent;
};

EventNames eventNames();