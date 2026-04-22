*This project has been created as part of the 42 curriculum by anjaraan, tokrabem.*

---

# Push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using exactly two stacks — `a` and `b` — and a restricted set of operations, while minimizing the total number of moves.

The program reads a list of integers as arguments, outputs the sequence of operations that sorts them, and does so as efficiently as possible. A separate **benchmarking system** is included to measure performance metrics for each strategy.

The core challenge is not just sorting, but sorting **optimally**: the fewer operations used, the better the grade.

---

## Instructions

### Requirements

- GCC or CC compiler
- GNU Make
- A Unix-based system (Linux)

### Compilation

```bash
make
```

This produces the `push_swap` executable. To clean object files:

```bash
make clean
```

To fully reset:

```bash
make fclean
make re
```

### Execution

```bash
./push_swap [flags] <integers>
```

Integers can be passed as separate arguments or as a quoted string:

```bash
./push_swap 5 3 1 4 2
./push_swap "5 3 1 4 2"
```

### Flags

| Flag | Description |
|---|---|
| *(none)* | Uses the adaptive strategy automatically |
| `--simple` | Forces the simple O(n²) strategy |
| `--medium` | Forces the medium O(n√n) strategy |
| `--complex` | Forces the complex O(n log n) strategy |
| `--adaptive` | Explicitly selects the adaptive strategy |
| `--bench` | Enables benchmark mode (outputs stats to stderr) |

Flags can be placed at the beginning or end of the argument list. The `--bench` flag can be combined with a strategy flag:

```bash
./push_swap --simple 5 3 1 4 2
./push_swap --bench 5 3 1 4 2
./push_swap --bench --complex 5 3 1 4 2
```

### Verifying correctness with the checker

```bash
./push_swap 5 3 1 4 2 | ./checker_linux 5 3 1 4 2
```

### Running benchmarks

```bash
# Benchmark only (no moves printed):
./push_swap --bench $(cat args.txt) 2> bench.txt

# Benchmark while also verifying with checker:
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)

# Generate random input:
shuf -i 0-9999 -n 500 > args.txt
```

### Error handling

The program writes `Error` to stderr and exits in these cases:
- Non-integer arguments
- Integer overflow (outside [-2147483648, 2147483647])
- Duplicate values
- Invalid flag usage

---

## Algorithms

### Disorder metric

Before choosing a strategy, the program computes a **disorder metric** — the ratio of adjacent pairs that are out of order:

```
disorder = number of inversions between adjacent elements / (n - 1)
```

This gives a value between 0.00 (fully sorted) and 1.00 (fully reversed). The adaptive strategy uses this metric to pick the most efficient algorithm for the given input.

| Disorder range | Strategy chosen |
|---|---|
| < 0.2 | Simple — O(n²) |
| 0.2 to 0.5 | Medium — O(n√n) |
| ≥ 0.5 | Complex — O(n log n) |

---

### Simple strategy — Selection sort O(n²)

**How it works:** Selection sort adapted to stacks. Repeatedly finds the minimum element in `a`, brings it to the top, and pushes it to `b`. Once 3 elements remain in `a`, they are sorted in place with `sort_three`. Everything is then pushed back from `b` to `a`.

**Why it was chosen:** For small or nearly sorted inputs (n ≤ ~15), the overhead of more sophisticated algorithms outweighs their benefits. Simple sort has no setup cost and executes a minimal number of moves on small inputs.

**Performance:**
- n=10 → ~16 moves
- n=15 → ~40 moves

---

### Medium strategy — Chunk-based sorting O(n√n)

**How it works:** Chunk-based sorting. Each element is assigned a rank (index from 0 to n-1). Elements are divided into √n chunks of √n elements. Chunks are pushed from `a` to `b` one at a time using a bidirectional rotation heuristic (`top_closer`) that always chooses the cheapest direction. After all chunks are in `b`, elements are pulled back to `a` by repeatedly extracting the maximum.

**Why it was chosen:** For medium-sized inputs, processing groups of elements per scan is far more efficient than one element per scan. The √n chunk size is the mathematical optimum that minimizes total rotations.

**Optimisation:** For n ≤ 10, the medium strategy falls back to the simple strategy to avoid chunk overhead on small inputs.

**Performance:**
- n=100 → ~700 moves average
- n=500 → ~7500 moves average

---

### Complex strategy — Optimized Merge sort O(n log n)

**How it works:** A greedy cost-based insertion algorithm. All but 3 elements are pushed to `b`. The remaining 3 are sorted in `a` with `sort_three`. Then, for each element in `b`, the algorithm:

1. Finds its **target node** in `a` — the smallest value in `a` greater than the `b` element (maintaining sorted circular order)
2. Calculates the **push cost** — how many moves to bring both the `b` node and its target to the top of their respective stacks, accounting for simultaneous rotations (`rr`/`rrr`)
3. Marks the **cheapest** node across all `b` elements
4. Executes that move, using `rr`/`rrr` when both stacks need the same rotation direction

After all elements are back in `a`, the minimum is rotated to the top.

**Why it was chosen:** For great-sized inputs, this algorithm produces the fewest moves because every `pa` places an element directly into its final sorted position. The cost calculation ensures no move is ever wasted. Alternatives were benchmarked and rejected:


**Performance:**
- n=100 → ~550 moves average (limit: 700)
- n=500 → ~5200 moves average (limit: 5500)

---

### Benchmark system

The `--bench` flag activates a benchmark overlay that tracks every individual operation and reports:

```
[bench] disorder : 49.93%
[bench] strategy : Adaptive / O(n log n)
[bench] total_ops : 565
[bench] sa: 0  sb: 0  ss: 0  pa: 97  pb: 97
[bench] ra: 142  rb: 89  rr: 31  rra: 67  rrb: 52  rrr: 18
```

Stats go to **stderr** so they never interfere with the move output on stdout, which remains pipeable to the checker.

---

## Resources

### Documentation and references

- [Push_swap — a visual and algorithmic study](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — Jamie Dawson's breakdown of the Turk algorithm
- [Sorting algorithms complexity](https://www.bigocheatsheet.com/) — Big-O reference sheet
- [42 push_swap subject](https://cdn.intra.42.fr/pdf/pdf/136456/en.us_push_swap.pdf) — official project specification
- [Radix sort explanation](https://www.geeksforgeeks.org/radix-sort/) — GeeksForGeeks
- [Merge sort on linked structures](https://www.geeksforgeeks.org/merge-sort-for-linked-list/) — GeeksForGeeks

### AI usage


All algorithmic decisions, implementation choices, and final code were made and written by the project authors. AI was used as a reference and debugging tool.
