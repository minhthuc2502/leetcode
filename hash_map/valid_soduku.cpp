#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int row = board.size();
    int col = board[0].size();
    vector<unordered_map<int, char>> col_maps(col);
    unordered_map<int, char> row_map;
    vector<unordered_map<int, char>> square_maps((col / 3) * (row / 3));

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (board[r][c] == '.')
                continue;
            if (row_map.find(board[r][c]) == row_map.end()) {
                row_map[board[r][c]] = 1;
            }
            else
                return false;
                        vector<unordered_map<int, char>> col_maps(col);
                        unordered_map<int, char> row_map;
                        vector<unordered_map<int, char>> square_maps((col / 3) * (row / 3));
                
                        for (int r = 0; r < row; ++r) {
                            for (int c = 0; c < col; ++c) {
                                if (board[r][c] == '.')
                                    continue;
                                if (row_map.find(board[r][c]) == row_map.end()) {
                                    row_map[board[r][c]] = 1;
                                }
                                else
                                    return false;
                                if (col_maps[c].find(board[r][c]) == col_maps[c].end()) {
                                    col_maps[c][board[r][c]] = 1;
                                }
                                else
                                    return false;
                                if (square_maps[(r / 3) * 3 + c / 3].find(board[r][c]) == square_maps[(r / 3) * 3 + c / 3].end()) {
                                    square_maps[(r / 3) * 3 + c / 3][board[r][c]] = 1;
                                }
                                else
                                    return false;
                            }
                            row_map.clear();
                        }
            if (col_maps[c].find(board[r][c]) == col_maps[c].end()) {
                col_maps[c][board[r][c]] = 1;
            }
            else
                return false;
            if (square_maps[(r / 3) * 3 + c / 3].find(board[r][c]) == square_maps[(r / 3) * 3 + c / 3].end()) {
                square_maps[(r / 3) * 3 + c / 3][board[r][c]] = 1;
            }
            else
                return false;
        }
        row_map.clear();
    }
    return true;
}
int main(void) {
    vector<vector<char>> input = {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};
    cout << isValidSudoku(input) << endl;
    return 0;
}