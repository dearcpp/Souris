#include "core/controller/controller.hpp"

int main(int argc, char *argv[]) {
    auto controller = Core::Controller::Create(argc, argv);
    return controller->exec();
}
