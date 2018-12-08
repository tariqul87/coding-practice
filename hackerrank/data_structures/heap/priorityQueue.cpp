#include <iostream>
#include <vector>
using namespace std;

// mean heap
class PriorityQueue
{
    vector<int> A;
    int length;

  public:
    PriorityQueue(vector<int> arr)
    {
        int heap_size = arr.size();

        for (int i = 0; i < heap_size; i++)
        {
            A.push_back(arr[i]);
        }

        build_max_heap();
    }
    void build_max_heap()
    {
        int heap_size = A.size();
        for (int i = heap_size / 2 - 1; i >= 0; i--)
        {
            max_heapify(i);
        }
    }
    int size()
    {
        return A.size();
    }
    void max_heapify(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        int heap_size = A.size();
        if (l < heap_size && A[l] < A[smallest])
        {
            smallest = l;
        }

        if (r < heap_size && A[r] < A[smallest])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            int temp = A[i];
            A[i] = A[smallest];
            A[smallest] = temp;

            max_heapify(smallest);
        }
    }
    void print()
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    int pop()
    {
        if (A.size() <= 0)
        {
            return -1;
        }
        int heap_size = A.size();
        int number = A[0];
        A[0] = A[heap_size - 1];
        A.pop_back();
        max_heapify(0);

        return number;
    }
    void insert(int i) {
        A.push_back(i);
        int childPosition = A.size() - 1;
        int parentPosition = (childPosition - 1) / 2;

        while(childPosition > 0 && A[childPosition] < A[parentPosition])
        {
            int temp = A[childPosition];
            A[childPosition] = A[parentPosition];
            A[parentPosition] = temp;

            childPosition = parentPosition;
            parentPosition = (childPosition - 1) /2 ;
        }
    }
};

int main()
{
    vector<int> A;

    PriorityQueue *priorityQueue = new PriorityQueue(A);

    priorityQueue->insert(11);
    priorityQueue->print();

    priorityQueue->insert(12);
    priorityQueue->print();
    
    priorityQueue->insert(1);
    priorityQueue->print();
    
    priorityQueue->insert(3);
    priorityQueue->print();

    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;
    // cout << priorityQueue->pop() << " size: " << priorityQueue->size() << endl;

    return 0;
}