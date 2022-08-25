#include <iostream>
#include <vector>

using namespace std;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int num_row = matrix.size();
    int num_col = matrix[0].size();    
    int low_row = 1;
    int low_col = 0;
    int r = 0;
    int c = 0;
    vector<int> result;
    result.push_back(matrix[r][c]);
    int direction = Direction::RIGHT;
    int cnt = 1;
    int size = num_row * num_col;

    while(1) {
        if (cnt == size)
            break;
        if (direction ==  Direction::RIGHT) {
            if (c == num_col - 1) {
                --num_col;
                direction = Direction::DOWN;
                continue;
            }
            result.push_back(matrix[r][++c]);
        }
        else if (direction == Direction::DOWN) {
            if (r == num_row - 1) {
                --num_row;
                direction = Direction::LEFT; 
                continue;
            }
            result.push_back(matrix[++r][c]);
        }
        else if (direction == Direction::LEFT) {
            if (c == low_col) {
                ++low_col;
                direction = Direction::UP;
                continue;
            }
            result.push_back(matrix[r][--c]);
        }
        else {
            if (r == low_row) {
                ++low_row;
                direction = Direction::RIGHT;
                continue;
            }
            result.push_back(matrix[--r][c]);
        }
        ++cnt;
    }
    return result;
}

int main() {
    vector<vector<int>> input = {{3}, {2}};
    vector<int> result = spiralOrder(input);
    for (auto c : result) {
        cout << c << " ";
    }
    return 0;
}