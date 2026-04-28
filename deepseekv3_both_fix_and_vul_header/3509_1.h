class WebSharedWorkerStub {
public:
    void OnTerminateWorkerContext();
};

class Impl {
public:
    void terminateWorkerContext();
};

Impl* impl_;
bool running_;

void EnsureWorkerContextTerminates();