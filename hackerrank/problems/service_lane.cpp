#include <bits/stdc++.h>
using namespace std;

vector<int> service_lane(vector<int> width_list, vector< vector<int> > test_cases) {
    vector<int> result;

    for(int i=0; i<test_cases.size(); i++) {
        int min = 100001;
        for(int j=test_cases[i][0]; j<= test_cases[i][1]; j++) {
            if (min > width_list[j]) {
                min = width_list[j];
            }
        }
        result.push_back(min);
    }

    return result;
}

int main(void)
{
    int n, t;
    vector<int> width_list;

    cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        width_list.push_back(x);
    }

    vector< vector<int> > test_cases;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        vector<int> test_case;
        test_case.push_back(a);
        test_case.push_back(b);

        test_cases.push_back(test_case);
    }
    
    vector<int> result = service_lane(width_list, test_cases);
    for(int i=0; i<t; i++) {
        cout<<result[i]<<endl;
    }

    return 0;
}