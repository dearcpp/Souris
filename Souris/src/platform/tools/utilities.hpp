#ifndef SOURIS_PLATFORM_TOOLS_UTILITIES_HPP
#define SOURIS_PLATFORM_TOOLS_UTILITIES_HPP

# include <core/defines.hpp>
# include <tuple>

SOURIS_PLATFORM_BEGIN_NAMESPACE

extern bool is_ip_address(const char *str);

extern std::tuple<const char*, u32> get_file_path();

SOURIS_PLATFORM_END_NAMESPACE

#endif
