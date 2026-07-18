#pragma once

#include <string>
#include "grid.h"

// Convert a boolean grid into a PNG file.
// 'scale' enlarges each grid module into a block of pixels.
void write_matrix_to_png(
    const grid &matrix, 
    int scale,          
    const std::string &filename) ;