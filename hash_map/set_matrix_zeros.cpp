#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    unordered_map<string, vector<int>> mapping;
    int row = matrix.size();
    int col = matrix[0].size();
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (matrix[r][c] == 0) {
                mapping["row"].push_back(r);
                mapping["col"].push_back(c);
            }
        }
    }
    for (auto &r : mapping["row"]) {
        for (int c = 0; c < col; ++c) {
            matrix[r][c] = 0;
        }
    }
    for (auto &c : mapping["col"]) {
        for (int r = 0; r < row; ++r) {
            matrix[r][c] = 0;
        }
    }
}

int main(void) {
    return 0;
}