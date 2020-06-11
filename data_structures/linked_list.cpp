#include <bits/stdc++.h>
using namespace std;

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

int main(void)
{
    Node *head = createLinkedListByArray({1, 2, 3, 4, 5, 6});

    printLinkedList(head);
    return 0;
}