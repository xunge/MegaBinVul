#include <stddef.h>
#include <stdbool.h>

struct Document;

struct ExecutionContext {
    bool isDocument() const;
};

struct ContentSecurityPolicy {
    ExecutionContext* m_executionContext;
    Document* document() const;
};

Document* toDocument(ExecutionContext*);