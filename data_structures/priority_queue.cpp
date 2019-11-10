#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<pair<int, int>> arr;
    void upward_balance(int index)
    {
        if (index == 0)
        {
            return;
        }

        int parentIndex = index % 2 == 0 ? (index - 2) / 2 : (index - 1) / 2;
        if (arr[parentIndex].first < arr[index].first)
        {
            swap(arr[parentIndex], arr[index]);
            upward_balance(parentIndex);
        }
    }
    void downward_balance(int index)
    {
        if (index >= arr.size())
        {
            return;
        }

        int leftChild = index * 2 + 1;
        int rightChild = index * 2 + 2;

        if (leftChild < arr.size() && rightChild < arr.size())
        {
            int maxChild = arr[leftChild].first > arr[rightChild].first ? leftChild : rightChild;
            if (arr[maxChild].first > arr[index].first)
            {
                swap(arr[maxChild], arr[index]);
                downward_balance(maxChild);
            }
        }
        else if (leftChild < arr.size() && arr[leftChild].first > arr[index].first)
        {
            swap(arr[leftChild], arr[index]);
            downward_balance(leftChild);
        }
        else if (rightChild < arr.size() && arr[rightChild].first > arr[index].first)
        {
            swap(arr[rightChild], arr[index]);
            downward_balance(rightChild);
        }
    }

public:
    void insert(int key, int value)
    {
        pair<int, int> newPair(key, value);
        arr.push_back(newPair);

        int index = arr.size() - 1;
        upward_balance(index);
    }
    pair<int, int> extract_max()
    {
        // throw empty error if arr.size() == 0
        pair<int, int> top = arr[0];

        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        downward_balance(0);

        return top;
    }
    void printAll()
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << "Index: " << i << ", key: " << arr[i].first << ", value: " << arr[i].second << endl;
        }
        cout << endl;
    }
};

int main(void)
{
    PriorityQueue p;

    for (int i = 1; i <= 10; i++)
    {
        p.insert(i, i);
        p.insert(i * i, i * i);
    }

    for (int i = 0; i < 20; i++)
    {
        pair<int, int> top = p.extract_max();
        cout << "key: " << top.first << ", value: " << top.second << endl;
    }

    return 0;
}