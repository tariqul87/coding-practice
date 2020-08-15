class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValidPosition(vector<vector<char>>& board, int i, int j) {
        if (i == -1 || i  == board.size() || j ==-1 || j == board[i].size()) {
            return false;
        }
         
        char ch = board[i][j];
        
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }
    bool existAtPosition(vector<vector<char>>& board, string word, int index, int i, int j) {
        if (index == word.size()) {
            return true;
        }
        
        if (!isValidPosition(board, i, j)) {
            return false;
        }
        
        if (board[i][j] != word[index]) {
            return false;
        }
        
        char ch = board[i][j];
        board[i][j] = '-';
        
        for(int k=0; k<dirs.size(); k++) {
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            
            if (existAtPosition(board, word, index + 1, x, y)) {
                return true;
            }
        }
        
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if (existAtPosition(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};