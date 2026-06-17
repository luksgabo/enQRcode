#pragma once

#include <string>
#include "grid.h"

// from matrix containing the boolean values for the QRcode
// output a png file 
// enlarges each source pixel to a scale x scale block in the output
void write_matrix_to_png(
    const grid &matrix, 
    int scale,          
    const std::string &filename) ;