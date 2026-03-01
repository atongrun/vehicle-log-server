#include "vls/core.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    vls_server_t server;
    vls_config_t cfg;

    vls_config_set_defaults(&cfg);

    if (vls_server_init(&server, &cfg) != VLS_OK) {
        fprintf(stderr, "vlsd: init failed\n");
        return EXIT_FAILURE;
    }

    if (vls_server_start(&server) != VLS_OK) {
        fprintf(stderr, "vlsd: start failed\n");
        return EXIT_FAILURE;
    }

    if (vls_server_stop(&server) != VLS_OK) {
        fprintf(stderr, "vlsd: stop failed\n");
        return EXIT_FAILURE;
    }

    (void)vls_server_shutdown(&server);
    return EXIT_SUCCESS;
}
