#ifndef VLS_CORE_H
#define VLS_CORE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum vls_status {
    VLS_OK = 0,
    VLS_E_INVALID_ARG = 1,
    VLS_E_INVALID_STATE = 2,
    VLS_E_NOT_IMPLEMENTED = 3
} vls_status_t;

typedef struct vls_record {
    const char *payload;
    size_t payload_len;
} vls_record_t;

typedef struct vls_config {
    uint16_t port;
    uint32_t worker_threads;
    uint32_t queue_capacity;
    uint64_t rotate_size_bytes;
} vls_config_t;

typedef struct vls_server {
    vls_config_t cfg;
    uint32_t state;
} vls_server_t;

void vls_config_set_defaults(vls_config_t *cfg);
vls_status_t vls_config_validate(const vls_config_t *cfg);

vls_status_t vls_server_init(vls_server_t *server, const vls_config_t *cfg);
vls_status_t vls_server_start(vls_server_t *server);
vls_status_t vls_server_submit(vls_server_t *server, const vls_record_t *record);
vls_status_t vls_server_flush(vls_server_t *server);
vls_status_t vls_server_stop(vls_server_t *server);
vls_status_t vls_server_shutdown(vls_server_t *server);

#ifdef __cplusplus
}
#endif

#endif
