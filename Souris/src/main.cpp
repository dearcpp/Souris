#include "platform/platform.hpp"

int main(int argc, char *argv[]) {
    auto controller = Platform::Controller::Create(argc, argv);
    return controller->exec();
}
