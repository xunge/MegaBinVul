#include <stdbool.h>
#include <stddef.h>

struct WebstoreInlineInstaller {
    void* host_;
    void* web_contents() const;
    bool CheckRequestorAlive() const;
};