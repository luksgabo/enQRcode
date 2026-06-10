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
