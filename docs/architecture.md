# Architecture

## Runtime Model
- One I/O thread owns the listening socket and `epoll` instance.
- I/O thread performs accept/read, packet framing, and enqueue.
- Worker pool consumes queue items for parse/transform/write.
- File writer subsystem handles append, flush policy, and rotation.

## Core Modules
- `net_listener`: socket init, accept, connection lifecycle.
- `event_loop`: `epoll_wait`, read readiness handling, backpressure trigger.
- `ingest_queue`: bounded MPSC queue between I/O and workers.
- `worker_pool`: N workers for JSON transform and dispatch.
- `log_writer`: append, chunk split, fsync policy, rotate.
- `config`: runtime knobs (ports, queue size, rotate threshold).
- `metrics`: counters and latency histograms.

## Data Flow
1. Client sends framed log records over TCP.
2. Event loop reads bytes, decodes frame boundaries.
3. Event loop enqueues record into bounded queue.
4. Worker parses and validates record, maps to canonical JSON.
5. Writer appends to active file and rotates when threshold reached.
6. Metrics are updated at each stage.

## Backpressure
- If queue is full, event loop should:
  - stop reading from that fd temporarily (remove `EPOLLIN`), or
  - drop records by policy with explicit metric increments.
- Policy is configurable; default is reject new records when full.

## Shutdown
- Stop accepting new clients.
- Drain queue up to timeout budget.
- Flush and close active log files.
- Emit final metrics summary.
