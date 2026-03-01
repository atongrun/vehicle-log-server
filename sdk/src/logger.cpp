#include "vls/sdk/logger.hpp"

namespace vls::sdk {

Logger::Logger() {
    vls_config_t cfg{};
    vls_config_set_defaults(&cfg);
    (void)vls_server_init(&server_, &cfg);
}

Logger::~Logger() {
    if (running_) {
        (void)stop();
    }
    (void)vls_server_shutdown(&server_);
}

bool Logger::start() {
    if (running_) {
        return false;
    }

    const auto rc = vls_server_start(&server_);
    running_ = (rc == VLS_OK);
    return running_;
}

bool Logger::submit(const std::string &payload) {
    if (!running_) {
        return false;
    }

    vls_record_t rec{};
    rec.payload = payload.c_str();
    rec.payload_len = payload.size();
    return vls_server_submit(&server_, &rec) == VLS_OK;
}

bool Logger::stop() {
    if (!running_) {
        return false;
    }

    const auto rc = vls_server_stop(&server_);
    running_ = false;
    return rc == VLS_OK;
}

} // namespace vls::sdk
