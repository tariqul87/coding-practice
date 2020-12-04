#include "array.cpp"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return 0;
        }
        
        vector<int> row(grid[0].size(), 0);
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    row[j] = 0;
                    continue;
                } else if (i == 0 && j == 0) {
                    row[j] = 1;
                } else {
                    int left = j > 0 ? row[j-1] : 0;
                    int top = i > 0 ? row[j] : 0;
                    
                    row[j] = left + top;
                }
            }
        }
        
        return row.back();
    }
};