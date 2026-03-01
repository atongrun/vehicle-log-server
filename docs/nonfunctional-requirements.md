# Nonfunctional Requirements

## Performance Targets (phase 1)
- Sustained ingest: >= 50,000 records/sec on target dev machine.
- p99 enqueue latency: <= 5 ms under normal load.
- p99 end-to-disk latency: <= 50 ms at 70% peak throughput.

## Reliability Targets
- No process crash on malformed client payloads.
- Graceful degradation under overload with explicit drop metrics.
- At-least-once file persistence after server accepts a record.

## Resource Constraints
- Memory cap target: <= 512 MiB at configured max clients.
- File descriptor usage bounded and monitored.
- Queue capacity explicit and configurable.

## Security Baseline
- Input length and schema validation on every frame.
- Path traversal safe file handling.
- No shell execution from untrusted input.
- Dependency footprint minimal; prefer libc and audited libs.

## Operability
- Expose counters: accepted, dropped, parse_errors, write_errors.
- Expose queue depth and worker utilization.
- Config values printed at startup.
