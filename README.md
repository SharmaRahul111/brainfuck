# brainfuck
Everything related to the Brainfuck language

## Table of content
* [What is brainfuck](#what-is-brainfuck)
  * [Interpreter Design](#interpreter-design)
  * [The instructions](#the-instructions)
* [Initial Goal for the interpreter in C](#initial-goal-for-the-interpreter-in-c)
* [Other Goals](#other-goals)
* [References](#references)

## What is Brainfuck?
Brain fuck is m esoteric language that is turing complete so theoretically anything that a turing machine can compute can be computed in brainfuck. It's distinguishing feature ks that it only uses eight symbols for instructions (and ignores rest) to do anything achievable (given infinite time and memory).

### Interpreter design
- the size of the tape is taken `30000` in general
- each cell is `1 byte` in size storing from `0 to 255`
- incrementing `255` gives `0`
- decrementing `0` gives `255` _(making a full circle)_
### The instructions
- `+` - increment the value of current cell by 1
- `-` - decrement the value of current cell by 1
- `>` - shifts the memory pointer to right by one
- `<` - shifts the memory pointer to left by one
- `[` - jump to the next corresponding `]` if value at current cell is zero
- `]` - jump to the next corresponding `[` if value at current cell is non zero
- `.` - output the value of current cell in ASCII
- `,` - take one byte input from user and store as integer

## Initial Goal for the interpreter in C
- working compiler ✅
- dynamic file input ✅
- shell interpreter ✅
- polish for use
- give helpful errors
- clean up the code
- wrap the cells at the edge of the tape
- throw an error if wrapping causes overwrite
- add optimizations like
  - pre counting number of `+` or `-`
  - try to execute a block instead of byte by byte
- add helpful comments
- try to use Make or CMake or something ✅
- release binaries ✅

## Other Goals
- Brainfuck interpreter in C ⏳
- Brainfuck example programs
  _(Either code myself or make a program to do that)_
  - Add / subtract
  - other algorithms like sum/factorial
   _(Not even sure how would I approach that)_
- Brainfuck compiler in C
- Brainfuck interpreter in Python/JS
- Brainfuck interpreter in Brainfuck
- Brainfuck explainer/debugger
- Brainfuck targeting transpiler
- Brainfuck compiler in Assembly _(The last chad move)_ 😂😂

## References
- [Specifications](./brainfuck-specs.md)
- [brainfuck.org](https://brainfuck.org/)
- [Tutorial and Interpreter (No cheating at first)](https://gist.github.com/roachhd/dce54bec8ba55fb17d3a)
- [Esolangs](https://esolangs.org/wiki/Brainfuck)
