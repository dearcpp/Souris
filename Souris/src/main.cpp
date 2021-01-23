#include "core/launcher/launcher.hpp"

int main(int argc, char *argv[]) {
    auto launcher = Core::Launcher::Create(argc, argv);
    return launcher->exec();
}
