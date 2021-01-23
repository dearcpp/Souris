#ifndef SOURIS_PLATFORM_LINUX_CONTROLLER_HPP
#define SOURIS_PLATFORM_LINUX_CONTROLLER_HPP

#include <cstdio>

# include "core/controller/controller.hpp"
# include "socket/client/client.hpp"

namespace Platform
{
    class Controller : public SOURIS_CORE_NAMESPACE::Controller
    {
    public:

        using SOURIS_CORE_NAMESPACE::Controller::Controller;

    };
}

#endif
