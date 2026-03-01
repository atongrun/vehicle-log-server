#include "vls/core.h"

void vls_config_set_defaults(vls_config_t *cfg) {
    if (cfg == NULL) {
        return;
    }

    cfg->port = 9501U;
    cfg->worker_threads = 4U;
    cfg->queue_capacity = 8192U;
    cfg->rotate_size_bytes = 128ULL * 1024ULL * 1024ULL;
}

vls_status_t vls_config_validate(const vls_config_t *cfg) {
    if (cfg == NULL) {
        return VLS_E_INVALID_ARG;
    }
    if (cfg->port == 0U) {
        return VLS_E_INVALID_ARG;
    }
    if (cfg->worker_threads == 0U || cfg->queue_capacity == 0U) {
        return VLS_E_INVALID_ARG;
    }
    if (cfg->rotate_size_bytes < (1ULL * 1024ULL * 1024ULL)) {
        return VLS_E_INVALID_ARG;
    }

    return VLS_OK;
}
