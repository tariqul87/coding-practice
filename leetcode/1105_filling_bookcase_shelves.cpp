#include "array.cpp"

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> heights(books.size(), INT_MAX);
        heights.push_back(0);
        int n = books.size();
        
        for(int i=n-1; i>=0 ; i--) {
            int bookWidth = books[i][0], bookHeight = books[i][1];
            int remainingWidth = shelfWidth - bookWidth;
            heights[i] = min(heights[i], bookHeight + heights[i+1]);
            
            for(int j=i+1; j < n; j++) {
                remainingWidth -= books[j][0];
                
                if (remainingWidth < 0) {
                    break;
                }
                
                bookHeight = max(bookHeight, books[j][1]);
                heights[i] = min(heights[i], bookHeight + heights[j+1]);
            }
        }
        
        return heights[0];
    }
};

/*
1 = 1
1, 2 = [1,3], []
*/