#include <platform/platform.hpp>

#if defined(SOURIS_PLATFORM_LINUX)

# include <platform/tools/utilities.hpp>

# include <libgen.h>
# include <unistd.h>
# include <linux/limits.h>

# include <stdexcept>
# include <arpa/inet.h>

SOURIS_PLATFORM_BEGIN_NAMESPACE

bool is_ip_address(const char *str) {
    sockaddr_in sai;
    return inet_pton(AF_INET, str, &sai.sin_addr) != 0;
}

std::tuple<const char*, u32> get_file_path() {
    char result[PATH_MAX];

    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    if (count == -1) {
        throw std::runtime_error("client path parsing error");
        return { nullptr, 0 };
    }

    return { dirname(result), count };
}

SOURIS_PLATFORM_END_NAMESPACE

#endif
