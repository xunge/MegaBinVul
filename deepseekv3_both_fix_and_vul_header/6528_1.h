#include <sys/types.h>
#include <unistd.h>

struct Options {
    // Placeholder for Options members
};

struct SpawnPreparationInfo {
    bool userSwitching;
    // Placeholder for other SpawnPreparationInfo members
};

void prepareChroot(SpawnPreparationInfo &info, const Options &options);
bool prepareUserSwitching(const Options &options);
void prepareSwitchingWorkingDirectory(SpawnPreparationInfo &info, const Options &options);
void inferApplicationInfo(SpawnPreparationInfo &info);

#define TRACE_POINT()