# Simply Walk

simply walk.

## How to Run

Clone the repo and `cd` into it, and do:

`g++ main.cpp -lncurses -o main`

then run it: `./main`

## Controls

<kbd>w</kbd> - Increases your `Y` value by 50.

<kbd>s</kbd> - Decreases your `Y` value by 50.

<kbd>r</kbd> - Reset the `Y` value to `0`

**You can set a new limit by doing:**

`./main [new_limit]`

Replace `[new_limit]` with the new limit you want. <br />
(Cannot be negative.)
