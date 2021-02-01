#include "utilities.hpp"

#include <arpa/inet.h>

SOURIS_PLATFORM_BEGIN_NAMESPACE

bool is_ip_address(const char *str) {
    struct sockaddr_in sai;
    return inet_pton(AF_INET, str, &sai.sin_addr) != 0;
}

SOURIS_PLATFORM_END_NAMESPACE
