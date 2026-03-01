#include "vls/core.h"

#include <stdlib.h>

int main(void) {
    vls_server_t server;
    vls_config_t cfg;

    vls_config_set_defaults(&cfg);

    if (vls_server_init(&server, &cfg) != VLS_OK) {
        return EXIT_FAILURE;
    }
    if (vls_server_start(&server) != VLS_OK) {
        return EXIT_FAILURE;
    }
    if (vls_server_stop(&server) != VLS_OK) {
        return EXIT_FAILURE;
    }
    if (vls_server_shutdown(&server) != VLS_OK) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
