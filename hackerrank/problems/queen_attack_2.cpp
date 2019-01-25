#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    int up = n - r_q;
    int down = r_q - 1;
    int left = c_q - 1;
    int right = n - c_q;
    int lud = min(left, up);
    int rud = min(right, up);
    int ldd = min(left, down);
    int rdd = min(right, down);

    for (int i = 0; i < obstacles.size(); i++)
    {
        int r = obstacles[i][0], c = obstacles[i][1];
        int r_d = r - r_q;

        if (r_d > 0)
        {
            if (c_q - c == abs(r_d)) // lud
            {
                lud = min(lud, c_q - c - 1);
            }
            else if (c_q == c)
            { // up
                up = min(up, r - r_q - 1);
            }
            else if (c - c_q == abs(r_d))
            { //rud
                rud = min(c - c_q - 1, rud);
            }
        }
        else if (r_d == 0)
        {
            if (c_q > c)
            {
                left = min(left, c_q - c - 1);
            }
            else if (c > c_q)
            {
                right = min(right, c - c_q - 1);
            }
        }
        else if (r_d < 0)
        {
            if (c_q - c == abs(r_d)) // ldd
            {
                ldd = min(ldd, c_q - c - 1);
            }
            else if (c_q == c) // down
            {
                down = min(down, r_q - r - 1);
            }
            else if (c - c_q == abs(r_d)) // rdd
            {
                rdd = min(c - c_q - 1, rdd);
            }
        }
    }

    int result = lud + up + rud + left + right + ldd + down + rdd;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++)
    {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++)
        {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
