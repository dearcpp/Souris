#include "client_path.hpp"

#include "core/utilities.hpp"

#include <cstring>

SOURIS_CORE_BEGIN_NAMESPACE
SOURIS_DELEGATOR_BEGIN_NAMESPACE

void ClientPath::handler(const Controller *controller) {
    auto [result, size] = Platform::get_file_path();
    controller->get_client().send(result, size);
}

SOURIS_DELEGATOR_END_NAMESPACE
SOURIS_CORE_END_NAMESPACE
