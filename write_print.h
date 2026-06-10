#pragma once

#include <vector>
#include "vec.h"
#include "grid.h"

void print_line(size_t length, char symbol );
grid finder_pattern(size_t length);
void paste_on_grid(grid& LargeGrid, const grid& SmallGrid,
                size_t start_row, size_t start_col);
void paste_on_grid(grid& LargeGrid, const vec& Vec,
                size_t start_row, size_t start_col, 
                char orientation );
void write_on_board(grid& Board);
void print_board(const grid& Board);