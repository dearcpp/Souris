#include <platform/platform.hpp>

#if defined(SOURIS_PLATFORM_LINUX)

# include <platform/tools/process.hpp>

# include <cstdio>
# include <cstdlib>

SOURIS_PLATFORM_BEGIN_NAMESPACE

struct Process::file_wrapper {
    FILE *handle;
};

Process::Process() : _pipe(new file_wrapper) { }

Process::Process(const char *file) : _pipe(new file_wrapper) {
    run(file);
}

void Process::run(const char *file) {
    _pipe->handle = popen(file, "r");
}

std::string Process::read_output() const {
    std::string result;
    char *buffer = new char[32]();
    while (std::fgets(buffer, 32, _pipe->handle) != 0) {
        result += buffer;
    }
    delete[] buffer;
    return result;
}

Process::~Process() {
    pclose(_pipe->handle);
    delete _pipe;
}

SOURIS_PLATFORM_END_NAMESPACE

#endif
