#include <vector>
#include <iostream>

using namespace std;

void eraseIsland(vector<vector<char>>& grid, int curr, int curc, vector<vector<bool>>& visited) {
    if (curr < 0 || curr >= grid.size() || curc < 0 || curc >= grid[0].size() || visited[curr][curc] || grid[curr][curc] == '0') {
        return;
    }

    visited[curr][curc] = true;
    grid[curr][curc] = '0';

    eraseIsland(grid, curr + 1, curc, visited);
    eraseIsland(grid, curr - 1, curc, visited);
    eraseIsland(grid, curr, curc + 1, visited);
    eraseIsland(grid, curr, curc - 1, visited);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == '1') {
                ++count;
                eraseIsland(grid, r, c, visited);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> input = {{'1','1','0','0','0'},
                                  {'1','1','0','0','0'},
                                  {'0','0','1','0','0'},
                                  {'0','0','0','1','1'}};
    cout << numIslands(input);
    return 0;
}