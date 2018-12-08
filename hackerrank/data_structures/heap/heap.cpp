#include <iostream>
#include <vector>
using namespace std;

// mean heap
class MaxHeap
{
    vector<int> A;
    int length;

  public:
    MaxHeap(vector<int> arr)
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
    void max_heapify(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        int heap_size = A.size();
        if (l < heap_size && A[l] > A[largest])
        {
            largest = l;
        }

        if (r < heap_size && A[r] > A[largest])
        {
            largest = r;
        }

        if (largest != i)
        {
            int temp = A[i];
            A[i] = A[largest];
            A[largest] = temp;

            max_heapify(largest);
        }
    }
    void print_heap()
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    int pop()
    {
        int heap_size = A.size();
        int temp = A[0];
        A[0] = A[heap_size - 1];
        A.pop_back();
        max_heapify(0);

        return temp;
    }
};

int main()
{
    vector<int> A;
    A.push_back(16);
    A.push_back(14);
    A.push_back(10);
    A.push_back(8);
    A.push_back(7);
    A.push_back(9);
    A.push_back(3);
    A.push_back(2);
    A.push_back(4);
    A.push_back(1);

    MaxHeap *heap = new MaxHeap(A);

    cout << heap->pop() << " " << endl;
    cout << heap->pop() << " " << endl;
    cout << heap->pop() << " " << endl;
    cout << heap->pop() << " " << endl;
    cout << heap->pop() << " " << endl;
    cout << heap->pop() << " " << endl;
    cout << heap->pop() << " " << endl;
    cout << heap->pop() << " " << endl;
    cout << heap->pop() << " " << endl;
    cout << heap->pop() << " " << endl;

    return 0;
}