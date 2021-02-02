#ifndef SOURIS_PLATFORM_PLATFORM_HPP
#define SOURIS_PLATFORM_PLATFORM_HPP

# if defined(_WIN32) || defined(_WIN64)
#  define SOURIS_PLATFORM_WINDOWS
# elif defined(__linux__)
#  define SOURIS_PLATFORM_LINUX
# endif

#endif
