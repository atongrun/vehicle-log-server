#ifndef VLS_SDK_LOGGER_HPP
#define VLS_SDK_LOGGER_HPP

#include <cstdint>
#include <string>

extern "C" {
#include "vls/core.h"
}

namespace vls::sdk {

class Logger {
public:
    Logger();
    ~Logger();

    bool start();
    bool submit(const std::string &payload);
    bool stop();

private:
    vls_server_t server_{};
    bool running_{false};
};

} // namespace vls::sdk

#endif
