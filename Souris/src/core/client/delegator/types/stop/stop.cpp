#include "stop.hpp"

#include "core/utilities.hpp"

#include <cstring>

SOURIS_CORE_BEGIN_NAMESPACE
SOURIS_DELEGATOR_BEGIN_NAMESPACE

void Stop::handler() {
    std::exit(EXIT_SUCCESS);
}

SOURIS_DELEGATOR_END_NAMESPACE
SOURIS_CORE_END_NAMESPACE
