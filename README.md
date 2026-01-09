# brainfuck
Everything related to the Brainfuck language

## Table of content
* [What is brainfuck](#what-is-brainfuck)
  * [Interpreter Design](#interpreter-design)
  * [Instructions](#instructions)
* [Features](#features)
* [Usage](#usage)
* [Issues](#issues)
* [Initial Goal for the interpreter in C](#initial-goal-for-the-interpreter-in-c)
* [Goals](#goals)
* [References](#references)

## What is Brainfuck?
Brain fuck is m esoteric language that is turing complete so theoretically anything that a turing machine can compute can be computed in brainfuck. It's distinguishing feature ks that it only uses eight symbols for instructions (and ignores rest) to do anything achievable (given infinite time and memory).

### Interpreter design
- the size of the tape is taken `30000` in general
- the program terminates if tape cell `-1` or `30001` is tried to access
- each cell is `1 byte` in size storing from `0 to 255`
- incrementing `255` gives `0`
- decrementing `0` gives `255` _(making a full circle)_
### Instructions

- `+` - increment the value of current cell by 1
- `-` - decrement the value of current cell by 1
- `>` - shifts the memory pointer to right by one
- `<` - shifts the memory pointer to left by one
- `[` - jump to the next corresponding `]` if value at current cell is zero
- `]` - jump to the next corresponding `[` if value at current cell is non zero
- `.` - output the value of current cell in ASCII
- `,` - take one byte input from user and store as integer

## Features
- execute a file via `$brainfuck <file>`
- enter interactive mode (REPL) via `$brainfuck`
- gives helpful errors
  - Error: Couldn't open file: `<file>`
  - Error: Maximum tape length exceeded
  - Error: Tried to access negative tape cell
  - Error: Couldn't find corresponding `[`
  - Error: Couldn't find corresponding `]`
- access the binaries in the release section

## Usage
* Execute from a file `$brainfuck <file>`
* Interactive shell (REPL mode) `$brainfuck`
* Help menu `$brainfuck -h` or `$brainfuck --help`
* Version number `$brainfuck -v` or `$brainfuck --version`
* About author `$brainfuck --about`
* Anything else shows the usage menu


## Issues
- currently user can't input newline `\n` intentionally at both `,` command and REPL
- command length is hardcoded at 50KB
- REPL prompt gets cut off at space character due to `%s` scanf behaviour of C
- loops spanning multiple REPL prompts isn't possible (probably won't implement)

## Goals
- Brainfuck interpreter in C ✅
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
- [brainfuck.org](https://brainfuck.org/)
- [Tutorial and Interpreter (No cheating at first)](https://gist.github.com/roachhd/dce54bec8ba55fb17d3a)
- [Esolangs](https://esolangs.org/wiki/Brainfuck)
