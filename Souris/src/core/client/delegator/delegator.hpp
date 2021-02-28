#ifndef SOURIS_CORE_CLIENT_DELEGATOR_DELEGATOR_HPP
#define SOURIS_CORE_CLIENT_DELEGATOR_DELEGATOR_HPP

# include "core/defines.hpp"
# include "core/controller/controller.hpp"

# include <nlohmann/json.hpp>

# define SOURIS_PARAMETERS_WRAPPER(...) __VA_ARGS__

# define SOURIS_DECLARE_DELEGATOR(delegator_name, delegator_message, delegator_parameters) \
    class delegator_name \
    { \
    public: \
        static void handler(delegator_parameters); \
    }; \

# define SOURIS_DECLARE_DELEGATOR_EMPTY_PARAMETERS(delegator_name, delegator_message) \
    class delegator_name \
    { \
    public: \
        static void handler(); \
    }; \

#endif
