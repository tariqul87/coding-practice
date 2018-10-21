#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n, d;
    cin >> n;
    cin >> d;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[(i + n - d) % n] = x;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}