#include <iostream>
#include <vector>
#include <bitset>

#include "globals.h"
#include "grid.h"
#include "vec.h"
#include "write_print.h"
#include "grid_to_png.h"
#include "encoding.h"

// Defining global variables
const size_t klength {25}; 
// I will start with only version 2 (25x25 modules)
// in the future I can adapt for larger versions
constexpr char kWhite_symbol= 'x', kBlack_symbol =' ';

int main(void)
{
    grid Board(klength);

    write_patterns_on_board(Board);

    print_board(Board);

    // write_matrix_to_png(Board, 5, "code.png") ;

    // wait input message and output it encoded in bytes
    // encode_message_to_bytes();  

}

