#ifndef SOURIS_PLATFORM_LINUX_CORE_UTILITIES_HPP
#define SOURIS_PLATFORM_LINUX_CORE_UTILITIES_HPP

# include "core/defines.hpp"

SOURIS_PLATFORM_BEGIN_NAMESPACE

extern bool is_ip_address(const char *str);

extern const char *get_file_path();

SOURIS_PLATFORM_END_NAMESPACE

#endif
