#include <iostream>
#include <iomanip>
#include <vector>
#include "write_print.h"
#include "globals.h"

// Place the static QR-like patterns onto the board, including finder squares,
// alignment squares, and timing lines.
void write_patterns_on_board(grid& Board){
    size_t length{Board.size()};

    // square modules in corners
    grid finder_square {finder_pattern(7)};
    vec separator(8);
    // upper-left
    paste_grid_grid(Board, finder_square, 0, 0, false);
    paste_vec_grid(Board, separator, 0, 7, 'v', true);
    paste_vec_grid(Board, separator, 7, 0, 'h', true);
    // upper-right
    paste_grid_grid(Board, finder_square, 0, length-7, false);
    paste_vec_grid(Board, separator, 0, length-8, 'v', true);
    paste_vec_grid(Board, separator, 7, length-8, 'h', true);
    // upper-right
    paste_grid_grid(Board, finder_square, length-7, 0, false);
    paste_vec_grid(Board, separator, length-8, 7, 'v', true);
    paste_vec_grid(Board, separator, length-8, 0, 'h', true);

    grid align_square {finder_pattern(5)};
    paste_grid_grid(Board, align_square, 16, 16, true);

    // timing pattern
    vec timing(9); 
    for (size_t i{0}; i<timing.size(); i+=2) {
        timing[i].flip();
    }
    paste_vec_grid(Board, timing, 8, 6, 'v', true);
    paste_vec_grid(Board, timing, 6, 8, 'h', true);

    // Format information pattern
    // only defining as unwritable for now
    vec information(8);
    // upper-left
    paste_vec_grid(Board, information, 0, 8, 'v', true);
    paste_vec_grid(Board, information, 8, 0, 'h', true);
    Board.SetUnwritable(8,8);
    // upper-right
    paste_vec_grid(Board, information, 8, length-8, 'h', true);
    // lower-left
    paste_vec_grid(Board, information, length-8, 8, 'v', true);
}

// Build a finder or alignment square pattern of the given size.
grid finder_pattern(size_t square_length) {
    grid square(square_length);

    square[0].flip();
    square[square_length-1].flip();

    switch (square_length){
    case 7:
        for (size_t i{1}; i<square_length-1;++i){
            square[i][0].flip();
            square[i][square_length-1].flip();
        };
        for (int row: {2,3,4}){
            for (int col: {2,3,4}){
                square[row][col].flip();
            };
        };
        break;
    case 5:
        for (size_t i{1}; i<square_length-1;++i){
            square[i][0].flip();
            square[i][square_length-1].flip();
        };
        square[2][2].flip();
        break;
    };

    return square;
}

// Copy a smaller grid into a larger grid at the specified location.
void paste_grid_grid(grid& LargeGrid, const grid& SmallGrid,
                size_t start_row, size_t start_col, bool uwtb = false ){
    size_t small_row_length{SmallGrid.size()};
    size_t small_col_length{SmallGrid.size()};
    for (size_t i{0};i < small_row_length; ++i){
        for (size_t j{0};j < small_col_length; ++j){
            LargeGrid[start_row + i][start_col + j] =
             SmallGrid[i][j];
            // for a static pattern the square is unwritable
            if (uwtb) {LargeGrid.SetUnwritable(start_row + i,start_col + j);}
        };
    };    
}

// Copy a linear vector into a grid either vertically or horizontally.
void paste_vec_grid(grid& LargeGrid, const vec& Vec,
                size_t start_row, size_t start_col, 
                char orientation, bool uwtb = false ) {
    
    size_t vec_length{Vec.size()};
    if (orientation=='v') {
    for (size_t i{0};i < vec_length; ++i){
            LargeGrid[start_row + i][start_col] =
             Vec[i];
             // for a static pattern the square is unwritable
            if (uwtb) {LargeGrid.SetUnwritable(start_row + i,start_col);}
    };    
    }
    else if (orientation=='h') {
    for (size_t j{0};j < vec_length; ++j){
            LargeGrid[start_row ][start_col + j] =
             Vec[j];
             // for a static pattern the square is unwritable
            if (uwtb) {LargeGrid.SetUnwritable(start_row,start_col + j);}
    };    
    }
}

// Print a border line around the board for console display.
void print_line(size_t box_length, char symbol = kWhite_symbol) {
    std::string line;
    line.reserve((box_length + 1) * 2 );

    for (size_t i = 0; i <= box_length + 1; ++i) {
        line += symbol; line += ' ';
    }
    std::cout << line << std::endl;
}

// Display board in terminal with symbols for dark and light squares
void print_board(const grid& Board){
    size_t box_length { Board[0].size()};

    // std::cout << std::string(box_length,'x') << '\n';
    print_line(box_length);
    for (size_t i = 0; i < Board.size(); ++i) {
        std::cout << kWhite_symbol << ' ';
        for (const bool value : Board[i]){    
            std::cout << (value?kBlack_symbol:kWhite_symbol) << ' ';
        }
    std::cout << kWhite_symbol<< '\n';
    };
    // std::cout << std::string(box_length*2+3,'x') << std::endl;
    print_line(box_length);
    std::cout << '\n';
}

void print_board(const std::vector<std::vector<bool>>& Board){
    size_t box_length { Board[0].size()};

    // std::cout << std::string(box_length,'x') << '\n';
    print_line(box_length);
    for (size_t i = 0; i < Board.size(); ++i) {
        std::cout << kWhite_symbol << ' ';
        for (const bool value : Board[i]){    
            std::cout << (value?kBlack_symbol:kWhite_symbol) << ' ';
        }
    std::cout << kWhite_symbol<< '\n';
    };
    // std::cout << std::string(box_length*2+3,'x') << std::endl;
    print_line(box_length);
    std::cout << '\n';
}

// Display the indexes of the squares in the terminal.
// Useful for debugging the board layout and position mapping.
void print_board_index(const grid& Board){
    size_t box_length { Board[0].size()};

    // std::cout << std::string(box_length,'x') << '\n';
    print_line(box_length);
    for (size_t i = 0; i < Board.size(); ++i) {
        std::cout << kWhite_symbol << ' ';
        // for (const bool value : Board[i]){
        for (size_t j = 0; i<Board.size(); ++j){ 
            std::cout << std::setw(3);
            std::cout << Board.vec_index[i*Board.size()+j] << ' ';
        }
    std::cout << kWhite_symbol<< '\n';
    };
    // std::cout << std::string(box_length*2+3,'x') << std::endl;
    print_line(box_length);
    std::cout << '\n';
}

// std::cout << '-' << std::string(2*length+2, '-') << '\n';
// for (int i = 0; i < length; ++i)
// {
//     std::cout << "| ";
//     for (int j = 0; j < length; ++j)
//     {
//         if (array[i][j]==1)
//         std::cout << '*' << ' ';
//         else
//         std::cout << ' ' << ' ';
//     }
//     std::cout << "|\n";
// }
// std::cout << '-' << std::string(2*length+2, '-') << '\n';
// std::cout << std::endl;