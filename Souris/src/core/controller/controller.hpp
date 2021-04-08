#ifndef SOURIS_CORE_CONTROLLER_CONTROLLER_HPP
#define SOURIS_CORE_CONTROLLER_CONTROLLER_HPP

# include <core/client/client.hpp>
# include <memory>

SOURIS_CORE_BEGIN_NAMESPACE

class Controller
{
public:

    explicit Controller(int argc, char *argv[]);

    static std::shared_ptr<Controller> Create(int argc, char *argv[]);

    const Client &get_client() const;

    int exec();

protected:

    Client _client;

};

SOURIS_CORE_END_NAMESPACE

#endif
