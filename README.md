# cpp-chess-engine

I'm building this chess engine completely from scratch in C++. Everything you see here is written by me.

It might look overengineered in spots, but this is my personal project and I've been grinding on it. I started prototyping the logic using C++ standard containers (`std::map`, `std::vector`), and I'm actively refactoring them into raw arrays and direct pointer arithmetic to cut down tree overhead and get maximum speed.

I'm going to keep working on it until it reaches standard engine quality, or at least nails these three goals:

1. Predict who will win (position evaluation)
2. Find the best move possible (search and move generation)
3. Run as fast as C++ allows (raw memory and low-level optimization)

No chess libraries, no pre-made bitboard templates. Just pure problem-solving and systems programming from first principles.

**Status:** In progress. I am working on two versions on two branches.

## Branches

### `main`: 1D array version
- Board stored as a 1D array, with `std::map` to track pieces
- A custom binary search to check whether the path between two squares is blocked
- King safety and escape-route counting (`king_inner_guard`, escape counters) to detect check, threats and checkmate
- Extra logic for row wrap-around, since moving past the edge of a 1D array lands on the wrong row

### `matrix-2d`: 2D board version
A second version on a plain 2D board (`vector<vector<char>>`). It is quicker to write and test, so I can get the rules right and refresh the basics, then carry the ideas across.

- 8x8 board with the standard starting position (uppercase = White, lowercase = Black, `.` = empty)
- Path-clearance checks along diagonals and straight lines, used by bishop, rook and queen
- In progress: king safety and attack detection (`under_at`, `safecheck`)
- In progress: move validation for pawn (two-step, captures, promotion), bishop, rook, queen, knight and king

## Next

- Full legal move generation (check, castling, en passant)
- Checkmate and stalemate detection
- Search (minimax with alpha-beta pruning) and position evaluation
- Replace standard containers with raw arrays for speed

## Design notes

My thinking, edge cases and attack-counting ideas are in `why.txt`.

## Build

<!-- EDIT: put the exact command you use to compile and run, for example: -->
```
g++ -std=c++17 *.cpp -o chess
./chess
```
