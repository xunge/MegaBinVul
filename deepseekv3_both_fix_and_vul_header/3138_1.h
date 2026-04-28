#include <stdlib.h>

class NavigationControllerImpl {
public:
    void DiscardNonCommittedEntriesInternal();
    void DiscardPendingEntry();
    void DiscardTransientEntry();
    void* pending_entry_;
    int pending_entry_index_;
};