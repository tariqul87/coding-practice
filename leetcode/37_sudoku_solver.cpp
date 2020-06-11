#include "./array.cpp"

void printSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution
{
public:
    bool row[9][10], col[9][10], quad[9][10], solved;
    bool isValidOption(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] != '.' && board[i][col] == c)
                return false; //check row
            if (board[row][i] != '.' && board[row][i] == c)
                return false; //check column
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false; //check 3*3 block
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValidOption(board, i, j, ch))
                        {
                            board[i][j] = ch;
                            if (solve(board))
                            {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

int main(void)
{
    Solution solution;
    // vector<vector<char>> board = {{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
    //                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    vector<vector<char>> board = {
        {'.', '.', '.', '6', '7', '8', '9', '1', '2'},
        {'6', '.', '.', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '.', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};

    cout << "Solve!" << endl;
    solution.solveSudoku(board);
    printSudoku(board);

    return 0;
}