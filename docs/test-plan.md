# Test Plan

## Unit Tests
- Frame decoder: split/coalesce boundary cases.
- JSON validation and canonical mapping.
- Rotation threshold and file naming logic.
- Queue push/pop correctness under contention.

## Integration Tests
- Multi-client concurrent uploads over TCP.
- End-to-end path: network -> queue -> writer -> file.
- Rotation while writes are active.
- Shutdown drain behavior with in-flight records.

## Load Tests
- Throughput sweep by client count and message size.
- Backpressure behavior when writer is slowed.
- Memory and fd trend over long run (>= 1 hour).

## Fault Injection
- Disk full / write permission error.
- Client sending oversized and malformed payloads.
- Sudden client disconnect storms.

## Acceptance Gates
- Meet phase-1 SLOs in `nonfunctional-requirements.md`.
- No memory growth trend in 1-hour soak.
- No data corruption across rotate boundaries.
