#ifndef SOURIS_CORE_LAUNCHER_LAUNCHER_HPP
#define SOURIS_CORE_LAUNCHER_LAUNCHER_HPP

# include "core/defines.hpp"

# include <memory>

SOURIS_CORE_BEGIN_NAMESPACE

class Launcher
{
public:

    Launcher(int argc, char *argv[]);

    static std::unique_ptr<Launcher> Create(int argc, char *argv[]);

    int exec();

};


SOURIS_CORE_END_NAMESPACE

#endif
