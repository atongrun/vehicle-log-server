#include "vls/core.h"

#include <string.h>

enum vls_run_state {
    VLS_STATE_STOPPED = 0,
    VLS_STATE_RUNNING = 1
};

vls_status_t vls_server_init(vls_server_t *server, const vls_config_t *cfg) {
    if (server == NULL || cfg == NULL) {
        return VLS_E_INVALID_ARG;
    }
    if (vls_config_validate(cfg) != VLS_OK) {
        return VLS_E_INVALID_ARG;
    }

    memset(server, 0, sizeof(*server));
    server->cfg = *cfg;
    server->state = VLS_STATE_STOPPED;
    return VLS_OK;
}

vls_status_t vls_server_start(vls_server_t *server) {
    if (server == NULL) {
        return VLS_E_INVALID_ARG;
    }
    if (server->state == VLS_STATE_RUNNING) {
        return VLS_E_INVALID_STATE;
    }

    server->state = VLS_STATE_RUNNING;
    return VLS_OK;
}

vls_status_t vls_server_submit(vls_server_t *server, const vls_record_t *record) {
    if (server == NULL || record == NULL || record->payload == NULL) {
        return VLS_E_INVALID_ARG;
    }
    if (server->state != VLS_STATE_RUNNING) {
        return VLS_E_INVALID_STATE;
    }

    return VLS_E_NOT_IMPLEMENTED;
}

vls_status_t vls_server_flush(vls_server_t *server) {
    if (server == NULL) {
        return VLS_E_INVALID_ARG;
    }

    return VLS_OK;
}

vls_status_t vls_server_stop(vls_server_t *server) {
    if (server == NULL) {
        return VLS_E_INVALID_ARG;
    }
    if (server->state != VLS_STATE_RUNNING) {
        return VLS_E_INVALID_STATE;
    }

    server->state = VLS_STATE_STOPPED;
    return VLS_OK;
}

vls_status_t vls_server_shutdown(vls_server_t *server) {
    if (server == NULL) {
        return VLS_E_INVALID_ARG;
    }

    server->state = VLS_STATE_STOPPED;
    memset(&server->cfg, 0, sizeof(server->cfg));
    return VLS_OK;
}
