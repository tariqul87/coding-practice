class Solution {
public:
    int getMatrixValue(vector<vector<int>> &matrix, int i, int j) {
        int size = matrix.size();
        if (i < 0 || i >= size || j < 0 || j >= matrix[i].size()) {
            return 0;
        }
        
        return matrix[i][j];
    }
    int getResultColumnValue(vector<vector<int>>& matrix, int i, int j) {
        
        if (i < 0) {
            return 0;
        }
        
        if (i >= matrix.size()) {
            i = matrix.size() - 1;
        }
        
        return getMatrixValue(matrix, i, j);
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> colSum, result;
        
        for(int i=0; i<mat.size(); i++) {
            vector<int> temp(mat[i].size(), 0);
            colSum.push_back(temp);
            result.push_back(temp);
            for(int j=0; j<mat[i].size(); j++) {
                colSum[i][j] = mat[i][j];
                if (i > 0) {
                    colSum[i][j] += colSum[i-1][j];
                }
            }
        }
        
        for (int i=0; i<mat.size(); i++) {
            result[i][0] = 0;
            for(int j = -K; j <= K; j++) {
                if (i + K >= mat.size()) {
                    result[i][0] += getMatrixValue(colSum, mat.size() - 1, j);
                } else {
                    result[i][0] += getMatrixValue(colSum, i+K, j);
                }
                result[i][0] -= getMatrixValue(colSum, i - K - 1, j);
            }
        }
        
        for(int i=0; i<mat.size(); i++) {
            for(int j=1; j<mat[i].size(); j++) {
                result[i][j] = result[i][j-1]
                    + getResultColumnValue(colSum, i + K, j + K)
                    - getResultColumnValue(colSum, i - K - 1, j + K)
                    - getResultColumnValue(colSum, i + K, j - K - 1)
                    + getResultColumnValue(colSum, i - K - 1, j - K - 1);
            }
        }
        
        return result;
    }
};