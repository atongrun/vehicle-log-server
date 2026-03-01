# vehicle-log-server

High-throughput multi-client vehicle log ingest server based on `epoll` + thread pool.

## Goals
- Support concurrent log upload from many clients.
- Keep event-loop responsiveness under load.
- Persist logs with rotation and chunked files.
- Standardize output to JSON for downstream pipeline ingestion.

## Non-goals (phase 1)
- Full text indexing or search engine integration.
- Cloud transport adapters.
- Multi-host clustering.

## Planned Layout
- `docs/architecture.md`: runtime architecture and module boundaries.
- `docs/protocol.md`: wire protocol and JSON schema.
- `docs/nonfunctional-requirements.md`: SLO and constraints.
- `docs/test-plan.md`: verification strategy.
- `docs/risk-register.md`: tracked risks and mitigations.

## Milestones
1. Define contracts and constraints.
2. Implement minimal vertical slice (accept -> queue -> write).
3. Add rotation and error recovery.
4. Add benchmarking and fault tests.
5. Harden security and operational metrics.

