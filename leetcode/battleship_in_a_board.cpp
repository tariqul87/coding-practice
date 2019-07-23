#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int count = 0;
        int row = board[0].size();
        int column = board.size();
        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (board[i][j] == 'X')
                {
                    if ((i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

int main(void)
{
    vector<vector<char>> board = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'X', '.', '.', 'X'}};
    Solution solution;
    cout << solution.countBattleships(board) << endl;

    return 0;
}