#include "grid.h"

grid::grid(size_t length){
    mlength = length;
    grid::EmptyGrid();
    grid::IndexGrid();
}
void grid::SetLength(size_t length){
    mlength = length;
    grid::EmptyGrid();
    grid::IndexGrid();
}

void grid::EmptyGrid(){
    body.resize(mlength, std::vector<bool>(mlength));
    body_writable.resize(mlength, std::vector<bool>(mlength));
    vec_index.resize(mlength * mlength);

    for (size_t i{0}; i<mlength; ++i){
        for (size_t j{0}; j<mlength; ++j){
            body[j][i] = false;
            body_writable[i][j] = true;
        }
    }
}

void grid::IndexGrid(){
    size_t total = mlength * mlength;
    vec_index.resize(total);
    for (size_t idx{0}; idx < total; ++idx){
        vec_index[idx] = idx;
    }
}

// partition of grid into codewords: pieces of 8 squares
// usually in two columns by four rows, from right to left and either upwards or downwards
// but depends on alignment patterns boundaries
void DataCodewords(){
    // get the empty grid with all the alignment patterns 
    // get a list of indexes of available squares
    // assign the indexes to each codeword
}