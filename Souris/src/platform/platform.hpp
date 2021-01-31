#ifndef SOURIS_PLATFORM_PLATFORM_HPP
#define SOURIS_PLATFORM_PLATFORM_HPP

#if defined(_WIN32) || defined(_WIN64)
#  define SOURIS_PLATFORM_WINDOWS
# elif defined(__linux__)
#  define SOURIS_PLATFORM_LINUX
# endif

# if defined(SOURIS_PLATFORM_WINDOWS)
#  error RetroWave maybe you will do something?
# elif defined(SOURIS_PLATFORM_LINUX)
#  include "platform/linux/linux.hpp"
# else
#  error This platform is not supported yet
# endif

#endif
