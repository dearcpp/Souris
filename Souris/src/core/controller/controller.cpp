#include "controller.hpp"

#include <iostream>
#include <thread>

#include <stdexcept>
#include <cstring>

#include "core/utilities.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

Controller::Controller(int, char *argv[]) : _client() {
    if (argv[1] == 0 || argv[2] == 0)
        throw std::invalid_argument("not all arguments were passed");

    if (!Platform::is_ip_address(argv[1]))
        throw std::invalid_argument("invalid ip address passed");

    if (!is_number(argv[2]) || std::strlen(argv[2]) > 5)
        throw std::invalid_argument("invalid port passed");

    _client.connect(argv[1], std::atoi(argv[2]));
}

std::shared_ptr<Controller> Controller::Create(int argc, char *argv[]) {
    return std::make_shared<SOURIS_CORE_NAMESPACE::Controller>(argc, argv);
}

int Controller::exec() const {
    return _client.listen();
}

SOURIS_CORE_END_NAMESPACE
