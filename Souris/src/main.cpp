#include "platform/platform.hpp"

#if defined(SOURIS_PLATFORM_WINDOWS)
# error RetroWave maybe you will do something?
#elif defined(SOURIS_PLATFORM_LINUX)

# include "platform/linux/linux.hpp"

int main(int argc, char *argv[]) {
    auto controller = Platform::Controller::Create(argc, argv);
    return controller->exec();
}

#else
# error This platform is not supported yet
#endif
