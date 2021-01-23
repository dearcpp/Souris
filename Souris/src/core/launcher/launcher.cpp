#include "launcher.hpp"

#include "platform/platform.hpp"

#include <cstdio>

SOURIS_CORE_BEGIN_NAMESPACE

Launcher::Launcher(int argc, char *argv[]) {
    printf("num: %i, first: %s\n", argc, argv[0]);
}

std::unique_ptr<Launcher> Launcher::Create(int argc, char *argv[]) {
    return std::make_unique<Platform::Launcher>(argc, argv);
}

int Launcher::exec() {
    return 1;
}

SOURIS_CORE_END_NAMESPACE
