#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

int dfsCountAndPrintPaths(vector<vector<char>>& matrix, string& target, int row, int col, int index, int direction, vector<pair<int, int>>& path) {
    if (index == target.length()) {
        // Print the path when the entire string is found.
        cout << "Found a path: ";
        for (const auto& coord : path) {
            cout << "(" << coord.first << ", " << coord.second << ") ";
        }
        cout << endl;
        return 1;  // The entire string is found.
    }

    if (!isValid(row, col, matrix.size(), matrix[0].size()) || matrix[row][col] != target[index]) {
        return 0;  // Invalid or mismatch, so the string can't be found.
    }

    // Store the current character temporarily.
    char originalChar = matrix[row][col];

    // Mark the current cell as visited.
    matrix[row][col] = '#';

    // Define the possible directions: right, down, and diagonal (down-right).
    int directions[3][2] = {{0, 1}, {1, 0}, {1, 1}};

    // Store the current coordinates in the path.
    path.push_back({row, col});

    // Recursive DFS in the same direction.
    int count = dfsCountAndPrintPaths(matrix, target, row + directions[direction][0], col + directions[direction][1], index + 1, direction, path);

    // Restore the original character in the matrix.
    matrix[row][col] = originalChar;

    // Remove the last coordinate from the path (backtrack).
    path.pop_back();

    return count;
}

int countOccurrencesInMatrixAndPrintPaths(vector<vector<char>>& matrix, string& target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //encounter start of target
            if (matrix[i][j] == target[0]) {
                // 3 choices to go individually only in down or right or diagonal
                for (int direction = 0; direction < 3; ++direction) {
                    vector<pair<int, int>> path;  
                    count += dfsCountAndPrintPaths(matrix, target, i, j, 0, direction, path);
                }
            }
        }
    }

    return count;
}

int main() {
    vector<vector<char>> matrix = {
        {'s', 'o', 's', 'o'},
        {'s', 'o', 'o', 's'},
        {'s', 's', 's', 's'}
    };
    string target = "sos";

    // Print the number of non-overlapping occurrences and their paths.
    int occurrences = countOccurrencesInMatrixAndPrintPaths(matrix, target);
    cout << "Number of non-overlapping occurrences of '" << target << "' in the matrix: " << occurrences << endl;

    return 0;
}
