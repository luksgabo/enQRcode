#include "grid.h"

grid::grid(size_t length){
    mlength = length;
    grid::EmptyGrid();
}
void grid::SetLength(size_t length){
    mlength = length;
    grid::EmptyGrid();
}

void grid::EmptyGrid(){
    body.resize(mlength, std::vector<bool>(mlength));
    for (size_t i{0}; i<mlength; ++i){
        for (size_t j{0}; j<mlength; ++j){
            body[j][i] = 0;
        };
    };
}

// partition of grid into codewords: pieces of 8 squares
// usually in two columns by four rows, from right to left and either upwards or downwards
// but depends on alignment patterns boundaries
void DataCodewords(){
// get the empty grid with all the alignment patterns 
// get a list of indexes of available squares
// assign the indexes to each codeword
}