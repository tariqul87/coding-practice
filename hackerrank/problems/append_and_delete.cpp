#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k)
{
    cout<<"ye ye!!"<<endl;
    int i = 0;
    int s_len = s.length(), t_len = t.length();

    while (i < s_len && i < t_len && s[i] == t[i])
    {
        i++;
    }

    if (t_len - i + s_len - i <= k)
    {
        return "Yes";
    }

    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    cout << result << "\n";

    fout.close();

    return 0;
}
