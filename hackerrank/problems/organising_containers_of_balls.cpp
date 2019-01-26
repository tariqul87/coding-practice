#include <bits/stdc++.h>
using namespace std;
#define possible "Possible"
#define impossible "Impossible"

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container)
{
    bool flag = true;
    int size = container.size();
    long long int total_balls[size], correct_balls[size];
    memset(total_balls, 0, size * sizeof(long long int));
    memset(correct_balls, 0, size * sizeof(long long int));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < container[i].size(); j++)
        {
            total_balls[i] += container[i][j];
            correct_balls[j] += container[i][j];
        }
    }

    // sorting needed! consider corner case where 1st container
    // contains 1 numbered ball (which is the only 1 numbered ball in the entire matrix) and 4th container contains only one ball, except 1 numbered ball. 
    sort(total_balls, total_balls + size);
    sort(correct_balls, correct_balls + size);

    for (int i = 0; i < size; i++)
    {
        if (total_balls[i] != correct_balls[i])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << possible << endl;
        return possible;
    }

    cout << impossible << endl;
    return impossible;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++)
        {
            container[i].resize(n);

            for (int j = 0; j < n; j++)
            {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
