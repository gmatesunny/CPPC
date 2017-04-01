#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <chrono>


using namespace std;

//void display(vector<vector<int>>& _board) {
//    for (vector<vector<int>>::iterator row = _board.begin(); row != _board.end(); ++row) {
//        for (vector<int>::iterator col = row->begin(); col != row->end(); ++col) { //pre is faster than post
//            cout << *col << "  ";
//        }
//        cout << endl;
//    }
//}

void display(vector<vector<int>> &_board) {
    for (auto row: _board) {
        for (auto col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
}


bool isBoardSolved(vector<vector<int>> &_board) {
    for (auto row: _board) {
        for (auto col: row) { //style[1] of 2D vector traversal
            if (col == 0) {
                return false;
            }
        }
    }
    return true;
}

map<int, int> findOptions(vector<vector<int>> &_board, int _row, int _col) {
    map<int, int> options;
    int x, y;
    for (int digit = 1; digit < 10; ++digit) {
        options[digit] = 0; //state 0 means available as options
    }
    //col in a row
    for (y = 0; y < 9; ++y) {
        if (_board[_row][y] != 0) {
            options[_board[_row][y]] = 1;
        }
    }
    //row in a col
    for (x = 0; x < 9; ++x) {
        if (_board[x][_col] != 0) {
            options[_board[x][_col]] = 1;
        }
    }
    //in a rectangular 3*3 matrix
    if (_row <= 2)
        x = 0;
    else if (_row > 2 && _row <= 5)
        x = 3;
    else
        x = 6;
    if (_col <= 2)
        y = 0;
    else if (_col > 2 && _col <= 5)
        y = 3;
    else
        y = 6;


    for (int i = x; i < x + 3; ++i) {
        for (int j = y; j < y + 3; ++j) {
            if (_board[i][j] != 0) {
                options[_board[i][j]] = 1;
            }
        }
    }
    return options;

}

bool solveBoard(vector<vector<int>> &_board) {
    int row = 0;
    int col = 0;
    bool flag;
    if (isBoardSolved(_board)) {
        return true;
    } else {
        for (int x = 0; x < 9; ++x) { //not using the style[1] because I need explicit index of empty slot
            flag = false;
            for (int y = 0; y < 9; ++y) {
                if (_board[x][y] == 0) {
                    row = x;
                    col = y;
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
    }

    auto options = findOptions(_board, row, col);
    for (auto digit: options) {
        if (digit.second != 1) {
            _board[row][col] = digit.first;
            if (solveBoard(_board)) {
                return true;
            }
        }
    }
    _board[row][col] = 0;
    return false;
}

void sudokuMaker(vector<vector<int>> &_board) {
    int row = 0;
    int col = 0;

    map<int, int> options;
    for (int x = 0; x < 9; ++x) { //not using the style[1] because I need explicit index
        for (int y = 0; y < 9; ++y) {
            if (rand() % 2) {
                row = x;
                col = y;
                options = findOptions(_board, row, col);
                int p = rand() % 9 + 1;
                if (options[p] == 0) {
                    _board[x][y] = p;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {

    srand(time(0));

    auto start = chrono::steady_clock::now();

    int i = 0, yes = 0, no = 0;


    while (i < 100) {

        vector<vector<int>> board(9, vector<int>(9, 0));

//    board[1][0]=3;
//    board[5][0]=4;
//
//    board[3][1]=9;
//    board[6][1]=8;
//    board[8][1]=1;
//
//    board[2][2]=2;
//    board[5][2]=1;
//    board[6][2]=6;
//    board[8][2]=7;
//
//    board[6][3]=4;
//    board[7][3]=6;
//    board[8][3]=3;

//    board[0][4]=7;
//    board[1][4]=8;
//    board[4][4]=1;
//    board[6][4]=9;

//    board[5][5]=6;
//    board[8][5]=5;
//
//    board[2][6]=4;

//    board[0][7]=8;
//    board[2][7]=1;
//    board[6][7]=3;
//    board[8][7]=6;

//    board[0][8]=6;
//    board[3][8]=2;
//    board[5][8]=7;


        sudokuMaker(board);
//        cout << "Given Sudoku Board" << endl;
//        display(board);

        solveBoard(board);
        if (!isBoardSolved(board)) {
            ++no;
//            cout << "\nNo solution exists for the Sudoku Board" << endl;
        } else {
            ++yes;
//            cout << "Solved Sudoku Board" << endl;
//            display(board);
        }
        cout << "Yes:" << yes << "\tNo:" << no << endl;
        ++i;
    }

    cout << "\nNo. of times Sudoku ran: " << i << endl;
    cout << "Generated Soduku with possible solution: " << yes << endl;
    cout << "Generated Soduku with no solution: " << no << endl;
    cout << "Total time taken: " << chrono::duration<double, milli>(chrono::steady_clock::now() - start).count()
         << " ms";
}