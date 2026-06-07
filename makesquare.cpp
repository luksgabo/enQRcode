#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool>> Grid;

const int length {15}; 
Grid Board;

void write_on_board(Grid& Board, int length);

void print_board(const Grid& Board);

int main(void)
{
    write_on_board(Board, length);
    Board[5][6] = 1;
    print_board(Board);
}

void write_on_board(Grid& Board, int length){
    Board.resize(length, std::vector<bool>(length));
    for (int i{0}; i<length; ++i){
        for (int j{0}; j<length; ++j){
            Board[j][i] = 0;
        };
    };
}

void print_board(const Grid& Board){

    for (const std::vector vec : Board) {
        for (const bool value : vec){
            std::cout << (value?'x':' ') << ' ';
        }
    std::cout << '\n';
    };
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