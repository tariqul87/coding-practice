#include <bits/stdc++.h>
using namespace std;

int get_spacial_problem_count(vector<int> problem_list, int k)
{
    int special_problems = 0;
    int page = 1;

    for (int i = 0; i < problem_list.size(); i++)
    {
        int problems = 0;

        while (problems < problem_list[i])
        {
            if (problems > 0 && problems % k == 0)
            {
                page++;
            }
            problems++;
            // cout << "Page=" << page << " Problem=" << problems << endl;

            if (problems == page)
            {
                special_problems++;
            }
        }
        page++;
    }

    return special_problems;
}

int main(void)
{
    int n, k;
    vector<int> problem_list;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        problem_list.push_back(x);
    }

    int result = get_spacial_problem_count(problem_list, k);
    cout << result << endl;
    return 0;
}