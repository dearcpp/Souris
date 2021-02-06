#include "controller.hpp"

#include <iostream>
#include <thread>

#include <stdexcept>
#include <cstring>

#include "core/utilities.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

Controller::Controller(int, char *argv[]) : _client(this) {
    if (argv[1] == 0 || argv[2] == 0) {
        throw std::invalid_argument("not all arguments were passed");
        std::exit(-1);
    }

    if (!Platform::is_ip_address(argv[1])) {
        throw std::invalid_argument("invalid ip address passed");
        std::exit(-1);
    }

    if (!is_number(argv[2]) || std::strlen(argv[2]) > 5) {
        throw std::invalid_argument("invalid port passed");
        std::exit(-1);
    }

    _client.connect(argv[1], std::atoi(argv[2]));
}

std::shared_ptr<Controller> Controller::Create(int argc, char *argv[]) {
    return std::make_shared<SOURIS_CORE_NAMESPACE::Controller>(argc, argv);
}

const Client &Controller::get_client() const {
    return _client;
}

int Controller::exec() {
    return _client.listen();
}

SOURIS_CORE_END_NAMESPACE
