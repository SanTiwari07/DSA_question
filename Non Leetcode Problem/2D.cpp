#include <iostream>
#include <vector>

using namespace std;


bool searchMatrix(const vector<vector<int>>& matrix, int target, int& row_out, int& col_out) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int R = matrix.size();
    int C = matrix[0].size();

  
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (matrix[i][j] == target) {
                
                row_out = i;
                col_out = j;
                return true;
            }
        }
    }

    return false;
}

int main() {
    cout << "--- Searching Element in the 2D Matrix ---" << endl;

    vector<vector<int>> matrix = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    
    cout << "Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    int target1 = 5;
    int row1, col1;
    cout << "\nSearching for target: " << target1 << endl;
    if (searchMatrix(matrix, target1, row1, col1)) {
        cout << "Element " << target1 << " found at position: (" << row1 << ", " << col1 << ")" << endl;
    } else {
        cout << "Element " << target1 << " not found." << endl;
    }

    int target2 = 10;
    int row2, col2;
    cout << "\nSearching for target: " << target2 << endl;
    if (searchMatrix(matrix, target2, row2, col2)) {
        cout << "Element " << target2 << " found at position: (" << row2 << ", " << col2 << ")" << endl;
    } else {
        cout << "Element " << target2 << " not found." << endl;
    }

    return 0;
}
