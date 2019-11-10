#include "array.cpp"

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
        if (index >= arr.size()) {
            return;
        }

        int leftChild = index * 2 + 1;
        int rightChild = index * 2 + 2;

        if (leftChild < arr.size() && rightChild < arr.size()) {
            int maxChild = arr[leftChild].first > arr[rightChild].first ? leftChild :  rightChild;
            if (arr[maxChild].first > arr[index].first) {
                swap(arr[maxChild], arr[index]);
                downward_balance(maxChild);
            }
        } else if (leftChild < arr.size() && arr[leftChild].first > arr[index].first) {
            swap(arr[leftChild], arr[index]);
            downward_balance(leftChild);
        } else if (rightChild < arr.size() && arr[rightChild].first > arr[index].first) {
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
        pair<int, int> top = arr[0];

        arr[0].first = 0;
        arr[0].second = 0;
        downward_balance(0);

        return top;
    }
    void printAll()
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << "Index: " << i << ", key: " << arr[i].first << ", value: " << arr[i].second << endl;
        }
        cout<<endl;
    }
};

bool compareVector(vector<int> &i, vector<int> &j)
{
    return i[0] > j[0];
}
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> frequency;

        for (int i = 0; i < nums.size(); i++)
        {
            if (frequency.find(nums[i]) != frequency.end())
            {
                frequency[nums[i]]++;
            }
            else
            {
                frequency[nums[i]] = 1;
            }
        }

        priority_queue<pair<int, int>> p;
        vector<vector<int>> frequencyMap;
        for (auto i : frequency)
        {
            p.push({i.second, i.first});
        }

        vector<int> result;

        for(int i=0; i<k; i++) {
            result.push_back(p.top().second);
            p.pop();
        }

        return result;
    }
};

int main(void)
{
    vector<int> nums = {1, 1, 1, 2, 2, 1, 1, 3, 3, 3, 3};
    int k = 2;
    Solution solution;
    printIntArray(solution.topKFrequent(nums, k), " ");

    return 0;
}