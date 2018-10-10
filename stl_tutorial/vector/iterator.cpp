#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.push_back(i);
    }

    for (auto iterator = list.begin(); iterator != list.end(); iterator++)
    {
        cout << *iterator << " ";
    }

    for (auto iterator = list.cbegin(); iterator != list.cend(); iterator++)
    {
        cout << *iterator << " ";
    }
    return 0;
}