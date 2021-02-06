#include "client_path.hpp"

#include "core/utilities.hpp"

#include <cstring>

SOURIS_CORE_BEGIN_NAMESPACE
SOURIS_DELEGATOR_BEGIN_NAMESPACE

void ClientPath::handler(const Controller *controller) {
    const char *result = Platform::get_file_path();
    controller->get_client().send(result, strlen(result));
}

SOURIS_DELEGATOR_END_NAMESPACE
SOURIS_CORE_END_NAMESPACE
