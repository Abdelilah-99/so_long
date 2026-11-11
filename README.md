# so_long: 2D game with MiniLibX

A project from **1337** (42 network): a small top-down **2D game** in C using the **MiniLibX** graphics library: collect every item, then
reach the exit.

## Features
- Maps loaded from `.ber` files (`0` floor, `1` wall, `C` collectible, `E` exit, `P` player)
- **Map validation**: closed by walls, exactly one player and one exit, at least one
  collectible, and a **flood fill** to prove every collectible and the exit can be reached
- Keyboard movement, with the move count printed in the terminal (`MOVE: n`)
- You win by stepping on the exit after taking every collectible
- All images, windows and memory freed on exit (custom cleanup)

## Build and run
```bash
make
./so_long maps/valid_map.ber
```
The game expects its sprites in a `textures/` folder (`0.xpm`, `1.xpm`, ...) next to the binary.

**Stack:** C · MiniLibX · X11
