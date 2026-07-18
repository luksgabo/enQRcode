#pragma once
#include <vector>

class grid {
public:
    // Default empty grid.
    grid(){}
    // Create a square grid of the requested length.
    grid(size_t length);

    // Resize the grid and reset all cells to false.
    void SetLength(size_t length);

    // Set if square of grid is an encoding area
    void SetUnwritable(size_t row, size_t col){body_writable[row][col]=false;}

    // Return the current grid dimension.
    size_t size() const{ return body.size();}

    // Return a copy of the internal 2D matrix.
    // std::vector<std::vector<bool>> GetBody() { return body;}
    // std::vector<std::vector<bool>> GetWritable() { return body_writable;}

    const std::vector<std::vector<bool>>& GetWritableMask() const {
    return body_writable;}

    // Access a row by index.
    std::vector<bool>& operator[](size_t index){ return body[index];}
    const std::vector<bool>& operator[](size_t index) const 
    { return body[index];}

    // 1D matrix with indexes of grid
    std::vector<size_t> vec_index;

private:
    // number of rows and columns in the square grid
    size_t mlength{0};
    // 2D matrix of module values: true = black, false = white
    std::vector<std::vector<bool>> body;
    // 2D matrix of boolean values to determine the encoding area
    std::vector<std::vector<bool>> body_writable;
    // Set grid dimensions and fill with false.
    void EmptyGrid();

    // Placeholder for adding data codewords into the grid.
    void DataCodewords();

    // Vector of indexes relating to the original.
    void IndexGrid();

};