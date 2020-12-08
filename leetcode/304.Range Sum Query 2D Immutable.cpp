#include "array.cpp"

class NumMatrix {
public:
    vector<vector<int>> grid;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        
        grid.push_back(vector<int>(matrix[0].size()+1, 0));
        
        
        for(int i=1; i<=matrix.size(); i++) {
            int colSum = 0;
            grid.push_back({0});
            for(int j=1; j<=matrix[0].size(); j++) {
                int sum = matrix[i-1][j-1] + grid[i-1][j] + colSum;
                colSum += matrix[i-1][j-1];
                grid[i].push_back(sum);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = grid[row2+1][col2+1] - grid[row1][col2+1] - 
            (grid[row2+1][col1] - grid[row1][col1]);
        
        return sum;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */