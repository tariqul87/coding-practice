#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s)
{

    int r, c = 0, len = s.size();
    r = sqrt(len);
    if (r * r < len)
    {
        c = r + 1;

        if (r*c < len) {
            r++;
        }
    } else if (r*r == len) {
        c = r;
    }

    string out;

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (s[j * c + i])
            {
                out.append(1, s[j * c + i]);
            }
        }
        out.append(1, ' ');
    }

    cout<<out<<endl;
    return out;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
