#include <memory>
#include <thread>

class GpuMem {
public:
    void initialize();
};

namespace gpuwork {
    class GpuWork {
    public:
        void initialize();
    };
}

class GpuStats {
public:
    GpuStats();
};

class GpuMemTracer {
public:
    void initialize(std::shared_ptr<GpuMem> mem);
};

class GpuService {
public:
    GpuService();
private:
    std::shared_ptr<GpuMem> mGpuMem;
    std::shared_ptr<gpuwork::GpuWork> mGpuWork;
    std::unique_ptr<GpuStats> mGpuStats;
    std::unique_ptr<GpuMemTracer> mGpuMemTracer;
    std::unique_ptr<std::thread> mGpuMemAsyncInitThread;
    std::unique_ptr<std::thread> mGpuWorkAsyncInitThread;
};