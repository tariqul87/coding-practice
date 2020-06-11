#include "array.cpp"

class TicTacToe
{
public:
    /** Initialize your data structure here. */
    vector<int> rows;
    vector<int> rowsCount;
    vector<int> cols;
    vector<int> colsCount;
    vector<vector<int>> board;
    TicTacToe(int n)
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> row(n, 0);
            board.push_back(row);
            rows.push_back(0);
            rowsCount.push_back(0);
            cols.push_back(0);
            colsCount.push_back(0);
        }
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    bool checkColumn(int row, int player)
    {
        int col = 0;
        while (col < board.size() && board[row][col] == player)
        {
            col++;
        }

        return col == board.size();
    }

    bool checkRow(int col, int player)
    {
        if (rows[col] != player && rows[col] != 0) {
            return false;
        }
        
        int row = 0;
        while (row < board.size() && board[row][col] == player)
        {
            row++;
        }

        return row == board.size();
    }

    bool checkRightDiagonal(int player)
    {
        // cout<<"Checking right diagonal"<<endl;
        int i = 0;
        while (i < board.size() && board[i][i] == player)
        {
            i++;
        }

        return i == board.size();
    }

    bool checkLeftDiagonal(int player) {
        // cout<<"Checking left diagonal"<<endl;
        int size = board.size();
        int i = size - 1;

        while(i >=0 && board[i][size - i - 1] == player) {
            i--;
        }

        return i == -1; 
    }

    bool checkDiagonal(int row, int col, int player)
    {
        if (row != col && (board.size() - row - 1) != col)
        {
            return false;
        }

        return checkRightDiagonal(player) || checkLeftDiagonal(player);
    }
    int move(int row, int col, int player)
    {
        board[row][col] = player;

        if (checkRow(col, player) || checkColumn(row, player) || checkDiagonal(row, col, player))
        {
            return player;
        }

        return 0;
    }
};

int main(void)
{
    TicTacToe game(3);
    cout << game.move(0, 0, 1) << endl;
    cout << game.move(0, 2, 2) << endl;
    cout << game.move(2, 2, 1) << endl;
    cout << game.move(1, 1, 2) << endl;
    cout << game.move(1, 0, 1) << endl;
    cout << game.move(2, 0, 2) << endl;
    return 0;
}