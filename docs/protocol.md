# Protocol

## Transport
- TCP server, one stream per client.
- Frame format: `uint32_be length` + payload bytes.
- Payload encoding: UTF-8 JSON object.

## Required Payload Fields
- `ts_ms` (number): client event timestamp in milliseconds.
- `level` (string): `trace|debug|info|warn|error|fatal`.
- `module` (string): source module identifier.
- `msg` (string): message text.
- `client_id` (string): stable client identity.

## Optional Fields
- `kv` (object): additional key-values.
- `seq` (number): client-side sequence number.
- `thread` (string): thread or task name.

## Validation Rules
- Maximum payload size: 64 KiB (phase 1 default).
- Unknown fields are preserved under `extra` object.
- Invalid JSON increments parse-error metric and returns error reply.

## Server Reply (optional in phase 1)
- Success: `{ "ok": true, "accepted": 1 }`
- Failure: `{ "ok": false, "code": "QUEUE_FULL|INVALID_JSON|TOO_LARGE" }`

## File Naming and Rotation
- Active file: `logs/current.log`
- Rotated file: `logs/log-YYYYMMDD-HHMMSS-<index>.jsonl`
- Rotate when current file exceeds configured size (for example 128 MiB).
- Each line in output file is one canonical JSON object.
