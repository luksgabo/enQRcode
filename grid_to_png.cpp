#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "grid.h"
#include "grid_to_png.h"
#include "TinyPngOut.hpp"
#include "write_print.h"

void writeMatrixToPng(
    const grid &Board, 
    int scale,          
    const std::string &filename) {

    size_t Board_length{Board.size() };
    // add quiet zone: 4 white modules around grid 
    grid matrix(Board_length + 4);
    paste_on_grid(matrix, Board, 2, 2);

    size_t grid_heigth{matrix.size() * scale};
    size_t grid_width{matrix[0].size() * scale};

    std::vector<uint8_t> pixels(grid_width * grid_heigth * 3);
    // single row vector to allocate pixels buffer

    for (uint32_t y = 0; y < grid_heigth; ++y) {
        for (uint32_t x = 0; x < grid_width; ++x) {

            uint32_t sx = x / scale;
            uint32_t sy = y / scale;

            uint8_t bit = matrix[sx][sy];
            uint8_t value = bit ? 0 : 255 ; 
            // 1 -> black, 0 -> white

            size_t idx = (static_cast<size_t>(y) * grid_width + x) * 3;

            // Add color options
            pixels[idx + 0] = value; // Red pixel
            pixels[idx + 1] = value; // Green pixel
            pixels[idx + 2] = value; // Blue pixel
        }
    }

    std::ofstream out(filename, std::ios::binary); 
    // opening the output file
    TinyPngOut pngout(grid_width, grid_heigth, out);
    // creating TinyPngOut writer
    pngout.write(pixels.data(), grid_width * grid_heigth);
    // write the pixel buffer into the png file
    }