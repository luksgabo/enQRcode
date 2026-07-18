# enQRcode

A small C++ project that turns text into a QR-style image.

## What it does
- Encodes a message into a grid-based pattern
- Outputs the result as a PNG file

## Project structure
- main.cpp: entry point of the program
- grid.h / grid.cpp: 2D board structure used to build the pattern
- vec.h / vec.cpp: 1D helper structure for timing and pattern lines
- encoding.h / encoding.cpp: converts text into bytes
- write_print.h / write_print.cpp: draws and prints the pattern
- grid_to_png.h / grid_to_png.cpp: exports the final pattern as a PNG
- globals.h / globals.cpp: shared constants used across the project

## Requirements
- C++17 compiler
- Standard C++ libraries
- TinyPngOut for PNG generation

## Notes
- This project is mainly for learning C++ and Git
- PNG generation uses the TinyPngOut library (Project Nayuki)