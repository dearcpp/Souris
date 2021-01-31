#ifndef SOURIS_CORE_CONTROLLER_CONTROLLER_HPP
#define SOURIS_CORE_CONTROLLER_CONTROLLER_HPP

# include <memory>

#include "core/client/client.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

class Controller
{
public:

    explicit Controller(int argc, char *argv[]);

    static std::shared_ptr<Controller> Create(int argc, char *argv[]);

    int exec() const;

protected:

    Client _client;

};

SOURIS_CORE_END_NAMESPACE

#endif
