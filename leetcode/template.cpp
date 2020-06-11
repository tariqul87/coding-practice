#include <bits/stdc++.h>
using namespace std;

void intArrayInput(int count, vector<int> &array);
void intArrayInputWithCount(vector<int> &array);
void printIntArray(vector<int> array, string delemeter);
void printDoubleIntArray(vector<vector<int>> array, string delemeter);

void printIntArray(vector<int> array, string delemeter)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << delemeter;
    }

    cout << endl;
}

void printDoubleIntArray(vector<vector<int>> array, string delemeter)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[i].size(); j++)
        {
            cout << array[i][j] << delemeter;
        }
        cout << endl;
    }

    cout << endl;
}

void intArrayInput(int count, vector<int> &array)
{
    for (int i = 0; i < count; i++)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }
}

void intArrayInputWithCount(vector<int> &array)
{
    int count;
    cin >> count;
    intArrayInput(count, array);
}

class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

Node *createLinkedListByArray(vector<int> arr)
{
    Node *head = NULL;

    if (arr.size() == 0)
    {
        return head;
    }

    head = new Node(arr[0]);
    Node *node = head;

    for (int i = 1; i < arr.size(); i++)
    {
        node->next = new Node(arr[i]);
        node = node->next;
    }

    return head;
}

void printLinkedList(Node *head)
{
    Node *node = head;
    while (node)
    {
        cout << node->val;
        if (node->next)
        {
            cout << "-";
        }
        else
        {
            cout << endl;
        }
        node = node->next;
    }
}