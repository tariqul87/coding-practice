#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> map) {
    vector<string> result;
    result.push_back(map[0]);

    if (map.size() == 1) {
        return result;
    }
    for (int i = 1; i < map.size() - 1; i++)
    {
        string row = map[i];
        for (int j = 1; j < row.size() - 1; j++)
        {
            char ch = map[i][j];
            int top = (int)(map[i - 1][j] - ch);
            int bottom = (int)(map[i + 1][j] - ch);
            int left = (int)(map[i][j - 1] - ch);
            int right = (int)(map[i][j + 1] - ch);

            if (top < 0 && bottom < 0 && left < 0 && right < 0)
            {
                row[j] = 'X';
            }
        }
        result.push_back(row);
    }

    result.push_back(map[map.size() - 1]);

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
