# Risk Register

## R1 Queue Saturation
- Impact: dropped logs or unstable latency.
- Trigger: queue depth near capacity for sustained interval.
- Mitigation: bounded queue, per-client throttling, backpressure policy.
- Owner: runtime core.

## R2 Rotation Race
- Impact: record loss or duplicate lines around rotate.
- Trigger: high write rate with frequent rotation.
- Mitigation: single-writer ownership and atomic rotate sequence.
- Owner: storage pipeline.

## R3 JSON CPU Hotspot
- Impact: worker pool bottleneck, increased end-to-disk latency.
- Trigger: high cardinality fields and large payloads.
- Mitigation: preallocated buffers, fast-path validation, profiling.
- Owner: data transform.

## R4 Slow Disk
- Impact: queue backlog and cascading drops.
- Trigger: fsync spikes or degraded storage.
- Mitigation: configurable flush policy and overload shedding.
- Owner: storage pipeline.

## R5 Connection Storm
- Impact: event-loop starvation and fd pressure.
- Trigger: reconnect spikes from many clients.
- Mitigation: accept rate control and fd guardrails.
- Owner: network ingress.
