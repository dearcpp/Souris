#include "controller.hpp"

#include <stdexcept>
#include <cstring>

#include "platform/platform.hpp"
#include "core/utilities.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

Controller::Controller(int, char *argv[]) : _client(argv[1], std::atoi(argv[2])) {
    if (!Platform::is_ip_address(argv[1]))
        throw std::runtime_error("invalid ip address passed");

    if (!is_number(argv[2]) || std::strlen(argv[2]) > 5)
        throw std::runtime_error("invalid port passed");
}

std::shared_ptr<Controller> Controller::Create(int argc, char *argv[]) {
    return std::make_shared<SOURIS_CORE_NAMESPACE::Controller>(argc, argv);
}

int Controller::exec() const {
    return _client.listen();
}

SOURIS_CORE_END_NAMESPACE
