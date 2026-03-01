#include "vls/sdk/logger.hpp"

int main() {
    vls::sdk::Logger logger;
    if (!logger.start()) {
        return 1;
    }

    (void)logger.submit("{\"msg\":\"hello\"}");
    (void)logger.stop();
    return 0;
}
