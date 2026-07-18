#pragma once

#include <vector>
#include "vec.h"
#include "grid.h"

// Print a horizontal border line around the grid for console output.
void print_line(size_t length, char symbol );
// Build a finder/alignment square pattern used in QR-like output.
grid finder_pattern(size_t length);
// Paste a smaller grid into a larger grid at the given start location.
void paste_grid_grid(grid& LargeGrid, const grid& SmallGrid,
                size_t start_row, size_t start_col, bool uwtb );
// Paste a linear vector into a grid either horizontally or vertically.
void paste_vec_grid(grid& LargeGrid, const vec& Vec,
                size_t start_row, size_t start_col, 
                char orientation, bool uwtb );
// Place static QR-like patterns and timing lines on the board.
void write_patterns_on_board(grid& Board);
// Print the boolean grid to stdout using display symbols.
void print_board(const grid& Board);

void print_board_index(const grid& Board);