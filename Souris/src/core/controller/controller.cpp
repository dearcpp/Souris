#include "controller.hpp"

#include "platform/platform.hpp"

#include <cstdio>

SOURIS_CORE_BEGIN_NAMESPACE

Controller::Controller(int argc, char *argv[]) : _client("127.0.0.1", 8888) {
    printf("num: %i, first: %s\n", argc, argv[0]);
}

std::shared_ptr<Controller> Controller::Create(int argc, char *argv[]) {
    return std::make_shared<Platform::Controller>(argc, argv);
}

int Controller::exec() {
    return _client.exec();
}

SOURIS_CORE_END_NAMESPACE
