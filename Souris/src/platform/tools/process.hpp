#ifndef SOURIS_PLATFORM_TOOLS_PROCESS_HPP
#define SOURIS_PLATFORM_TOOLS_PROCESS_HPP

# include <core/defines.hpp>
# include <string>

SOURIS_PLATFORM_BEGIN_NAMESPACE

class Process
{
protected:

    struct file_wrapper;

public:

    Process();
    Process(const char *file);

    void run(const char *file);

    std::string read_output() const;

    virtual ~Process();

protected:

    file_wrapper *_pipe;

};

SOURIS_PLATFORM_END_NAMESPACE

#endif
